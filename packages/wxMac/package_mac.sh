#!/bin/bash
APP=Minesweep
BINDIR=../../bin
EXE=minesweeper
ASSETDIR=../../assets
ICON=Minesweep.icns

if [ ! -f "$BINDIR/$EXE" ]; then
	echo -e "\t$BINDIR/$EXE doesn't exist!"
	echo -e "\tPlease run \`make release\` first"
	echo -e "\texiting"
	exit
fi

if [ ! -f $ICON ]; then
	iconutil -c icns Minesweep.iconset
fi

WXLIBS=`otool -L $BINDIR/minesweeper | grep libwx | cut -d " " -f 1 | cut -d $'\t' -f 2`
APPBINDIR=./$APP.app/Contents/MacOS
APPRSRCDIR=./$APP.app/Contents/Resources
# LIBDEFDIR=`wx-config --libs | cut -d " " -f 1 | cut -d "L" -f 2`
FRAMEDIR=./$APP.app/Contents/Frameworks

mkdir -p $APPBINDIR
mkdir -p $APPRSRCDIR
# mkdir -p $FRAMEDIR

echo "Copying bundle Info"
cp Info.plist PkgInfo ./$APP.app/Contents

echo "Copying resources"
cp -r $ASSETDIR $APPRSRCDIR
cp $ICON $APPRSRCDIR

echo "Copying executable"
cp $BINDIR/$EXE $APPBINDIR

# echo "Copying dynamic libraries"
# for file in $WXLIBS
# do
# 	cp $file $FRAMEDIR
# done
#
# echo "Patching executable"
# for libfile in $WXLIBS
# do
# 	install_name_tool -change $LIBDEFDIR/$(basename $libfile)  "@executable_path/../Frameworks/$(basename $libfile)" $APPBINDIR/$EXE
# done
#
# echo "Patching dylibs"
# for libfile in `ls $FRAMEDIR`
# do
# 	echo -e "\tPatching $libfile"
# 	DYLIBS=`otool -L $FRAMEDIR/$libfile | grep -e "libwx" | grep -v -e ":" | grep -v -e "exec" | cut -d " " -f 1 | cut -d $'\t' -f 2`
# 	for dylib in $DYLIBS
# 	do
# 		install_name_tool -change $dylib "@executable_path/../Frameworks/$(basename $libfile)" $FRAMEDIR/$libfile
# 	done
# done
#
# cd $FRAMEDIR
# for libfile in `ls *libwx*`
# do
# 	echo "Patching $libfile"
# 	DYLIBS=`otool -L $libfile | grep -e "_path//" | grep -v -e ":" | cut -d " " -f 1`
# 	echo -e "\t\t\t$DYLIBS"
# 	for dylib in $DYLIBS
# 	do
# 		echo -e "\t\t$dylib"
# 		install_name_tool -id @executable_path/$libfile ./$libfile
# 	done
# done
