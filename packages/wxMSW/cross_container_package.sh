#!/bin/bash
BINDIR=../../bin
EXE=minesweeper.exe
ASSETDIR=../../assets
FIND=find
ZIP=7z

if [ ! -f "$BINDIR/$EXE" ]; then
	echo -e "\t$BINDIR/$EXE doesn't exist!"
	echo -e "\tPlease run \`make -f Makefile.mswx release\` first"
	echo -e "\texiting"
	exit
fi

TYPE=$(file $BINDIR/$EXE | cut -d ' ' -f 5)
if [ $TYPE = "x86-64" ]; then
	PREFIX=x86_64-w64-mingw32
else
	PREFIX=i686-w64-mingw32
fi
APP=Minesweep.$PREFIX

if [ -d ./$APP ]; then
	rm -rf ./$APP
fi

mkdir $APP

LIBS=`${PREFIX}-strings ../../bin/minesweeper.exe | grep -i '\.dll$'`

echo "Copying resources"
cp -r $ASSETDIR $APP

echo "Copying executable"
cp $BINDIR/$EXE $APP/

echo "Copying dynamic libraries"
for lib in $LIBS
do
  find / -not -path "*posix/*" -name $lib -exec cp {} $APP \; 2>/dev/null
done

echo "Creating zip archive"
touch $APP/built-on-$(date +%s)
${ZIP} a -sdel -tzip release/$APP.zip $APP/
