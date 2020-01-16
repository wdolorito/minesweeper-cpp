#!/bin/bash
APP=Minesweep
BINDIR=../../bin
EXE=minesweeper.exe
ASSETDIR=../../assets
FIND=find

if [ ! -f "$BINDIR/$EXE" ]; then
	echo -e "\t$BINDIR/$EXE doesn't exist!"
	echo -e "\tPlease run \`make release\` first"
	echo -e "\texiting"
	exit
fi

if [ -d ./$APP ]; then
	rm -rf ./$APP
fi

mkdir $APP

WXLIBS=`ntldd ../../bin/minesweeper.exe | grep -v -i "windows" | cut -d " " -f 1 | cut -d $'\t' -f 2`

echo "Copying resources"
cp -r $ASSETDIR $APP

echo "Copying executable"
cp $BINDIR/$EXE $APP/

echo "Copying dynamic libraries"
CMP="*wx*"
for lib in $WXLIBS
do
    DLL=`which $lib`
	cp -f $DLL $APP/

    LIBDLLS=`ntldd $DLL | grep -v -i "windows" | cut -d " " -f 1 | cut -d $'\t' -f 2`

    for libdll in $LIBDLLS
    do
        echo $libdll
        cp -f `which $libdll` $APP/
    done
done
