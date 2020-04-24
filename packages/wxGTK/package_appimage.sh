#!/bin/bash
APP=Minesweep
APPDIR=./$APP.AppDir
APPIMAGE=./appimagetool-x86_64.AppImage
UNAME_M=`uname -m`
if [ $UNAME_M == 'armv7l' ]; then
  APPIMAGE=./appimagetool-armhf.AppImage
fi
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
APPMETDIR=$APPDIR/usr/share/metainfo
mkdir -p $APPBINDIR
mkdir -p $APPLIBDIR
mkdir -p $APPMETDIR

echo "Copying AppImage Info"
cp AppRun Minesweep.desktop $APPDIR
# cp Minesweep.appdata.xml $APPMETDIR

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

echo "Creating AppImage"
${APPIMAGE} $APPDIR

echo "Removing temporary files"
rm -rf $APPDIR
