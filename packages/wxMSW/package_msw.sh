#!/bin/bash
APP="Minesweep.$MSYSTEM"
BINDIR="../../bin"
EXE="minesweeper.exe"
ASSETDIR="../../assets"
LIBSFILE="libs.$MSYSTEM"
ZIP="7z"

walk_libs() {
    OPS="$(ntldd.exe "$1" | grep -v -i 'windows' | awk '{print $1}')"
    for lib in $OPS
    do
        OPLIB="$(which $lib)"
        echo "$OPLIB" >> "$LIBSFILE"
        walk_libs "$OPLIB"
    done 
}

if [ ! -f "$BINDIR/$EXE" ]; then
	echo -e "\t$BINDIR/$EXE doesn't exist!"
	echo -e "\tPlease run \`make -f Makefile.msw release\` first"
	echo -e "\texiting"
	exit
fi

if [ -d ./"$APP" ]
then
	rm -rf ./"$APP"
fi

mkdir "$APP"

echo "Copying resources"
cp -r $ASSETDIR "$APP"

echo "Copying executable"
cp $BINDIR/$EXE "$APP"/

echo "Copying dynamic libraries"

if [ -f "$LIBSFILE" ]
then
    rm -rf "$LIBSFILE"
fi

walk_libs "$BINDIR/$EXE"
sort -u "$LIBSFILE" -o "$LIBSFILE"
for F in $(cat "$LIBSFILE")
do
    cp "$F" "$APP"/
done
rm -rf "$LIBSFILE"

echo "Creating zip archive"
touch "$APP"/built-on-"$(date +%s)"
${ZIP} a -sdel -tzip release/"$APP".zip "$APP"/
