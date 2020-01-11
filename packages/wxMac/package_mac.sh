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
LIBDEFDIR=`wx-config --libs | cut -d " " -f 1 | cut -d "L" -f 2`
FRAMEDIR=./$APP.app/Contents/Frameworks

mkdir -p $APPBINDIR
mkdir -p $APPRSRCDIR
mkdir -p $FRAMEDIR

echo "Copying bundle Info"
cp Info.plist PkgInfo ./$APP.app/Contents

echo "Copying resources"
cp -r $ASSETDIR $APPRSRCDIR
cp $ICON $APPRSRCDIR

echo "Copying executable"
cp $BINDIR/$EXE $APPBINDIR

echo "Copying dynamic libraries"
for file in $WXLIBS
do
	cp $file $FRAMEDIR
done

echo "Patching executable"
for libfile in $WXLIBS
do
	install_name_tool -change $LIBDEFDIR/$(basename $libfile)  "@executable_path/../Frameworks/$(basename $libfile)" $APPBINDIR/$EXE
done

# echo "Patching dylibs"
# for libfile in `ls $FRAMEDIR`
# do
# 	echo -e "Patching $libfile"
# 	DYNAME=`otool -D $FRAMEDIR/$libfile | grep -e "libwx" | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
# 	DYLIBS=`otool -L $FRAMEDIR/$libfile | grep -e "libwx" | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
#
# 	# echo $DYNAME
# 	# install_name_tool -id "../Frameworks/$(basename $DYNAME)" $DYNAME
#
# 	for dylib in $DYLIBS
# 	do
# 		echo -e "\twith @executable_path/../Frameworks/$(basename $dylib)"
# 		install_name_tool -change $dylib "@executable_path/../Frameworks/$(basename $dylib)" $FRAMEDIR/$libfile
# 	done
#
# done
