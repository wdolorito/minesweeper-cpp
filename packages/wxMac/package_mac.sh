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
	cp -fRP $file $FRAMEDIR
	echo -e "\tCopying $(basename $file) dependencies"
	LIBWXDEPS=`otool -L $file | grep libwx | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
	for libfile in $LIBWXDEPS
	do
		echo -e "\t\t$libfile"
		if [ ! -f $FRAMEDIR/$(basename $libfile) ]; then
			cp -RP $libfile $FRAMEDIR 2> /dev/null
		fi
	done
done

echo "Patching executable"
for libfile in $WXLIBS
do
	install_name_tool -change $LIBDEFDIR/$(basename $libfile)  "@executable_path/../Frameworks/$(basename $libfile)" $APPBINDIR/$EXE
done

echo "Patching dylibs"
for libfile in $FRAMEDIR/*
do
	if [ ! -L $libfile ]; then
		echo -e "Patching $libfile"
		DYNAME=`otool -D $FRAMEDIR/$libfile | grep -e "libwx" | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
		DYLIBS=`otool -L $FRAMEDIR/$libfile | grep -e "libwx" | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
		echo $DYLIBS

		TMP=${PWD}
		cd $FRAMEDIR
		DPATH="@executable_path"
		echo -e "\twith ID $DPATH/$(basename $DYNAME)"
		install_name_tool -change $DPATH/$(basename $DYNAME) @loader_path/../Frameworks/$(basename $DYNAME) "../MacOS/$EXE"
		cd $TMP

		for dylib in $DYLIBS
		do
			LPATH="@executable_path/../Frameworks"
			echo -e "\twith $LPATH/$(basename $dylib)"
				install_name_tool -change $dylib "$LPATH/$(basename $dylib)" $FRAMEDIR/$(basename $dylib)
		done
	fi
done
