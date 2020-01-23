#!/bin/bash
APP=Minesweep
APPDIR=./$APP.AppDir
APPIMAGE=./appimagetool-x86_64.AppImage
BINDIR=../../bin
EXE=minesweeper
ASSETDIR=../../assets
ICON=../bomb.svg

if [ ! -f "$BINDIR/$EXE" ]; then
	echo -e "\t$BINDIR/$EXE doesn't exist!"
	echo -e "\tPlease run \`make release\` first"
	echo -e "\texiting"
	exit
fi

if [ -d ./$APPDIR ]; then
	rm -rf ./$APPDIR
fi

APPBINDIR=$APPDIR/usr/bin
APPLIBDIR=$APPDIR/usr/lib

mkdir -p $APPBINDIR
mkdir -p $APPLIBDIR

echo "Copying bundle Info"
cp AppRun Minesweep.desktop $APPDIR

echo "Copying resources"
cp -r $ASSETDIR $APPDIR
cp $ICON $APPDIR/Minesweep.svg

echo "Copying executable"
cp $BINDIR/$EXE $APPBINDIR

echo "Copying shared libraries"
WXLIBS=`LD_LIBRARY_PATH=~/local/lib ldd $APPBINDIR/$EXE | grep libwx | cut -d " " -f 3`
for lib in $WXLIBS
do
	cp $lib $APPLIBDIR
done
