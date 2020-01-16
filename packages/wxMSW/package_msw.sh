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

WXLIBS=`ntldd ../../bin/minesweeper.exe | grep -v -e "SYSTEM32" | cut -d " " -f 1 | cut -d $'\t' -f 2`

echo "Copying resources"
cp -r $ASSETDIR $APP

echo "Copying executable"
cp $BINDIR/$EXE $APP

echo "Copying dynamic libraries"
for lib in $WXLIBS
do
	cp -fRP $lib $APP
done

# echo "Patching executable"
# echo -e "\tPatching $APPBINDIR/$EXE"
# EFILE="@executable_path/../Frameworks"
# for libfile in $WXLIBS
# do
# 	echo -e "\t\twith $EFILE/$(basename $libfile)"
# 	install_name_tool -change $LIBDEFDIR/$(basename $libfile)  "$EFILE/$(basename $libfile)" $APPBINDIR/$EXE
# done
#
# echo "Patching dylibs"
# IFS=' '
# LIBFILES=`$FIND ./$APP.app -type f -name "*dylib"`
# unset IFS
#
# NPATH="@executable_path/../Frameworks"
#
# for libfile in $LIBFILES
# do
#
# 	echo -e "\r\n\tPatching $(basename $libfile)"
#
# 	DYLIBS=`otool -L $libfile | grep -e "libwx" | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
# 	echo $libfile
# 	echo -e "\t$DYLIBS"
#
# 	for dylib in $DYLIBS
# 	do
# 		echo -e "\t\twith dependency $NPATH/$(basename $dylib)"
# 		install_name_tool -change $dylib $NPATH/$(basename $dylib) $FRAMEDIR/$(basename $libfile)
# 	done
#
# 	TMP=${PWD}
# 	cd $FRAMEDIR
#
# 	DYNAME=`otool -D $(basename $libfile) | grep -e "libwx" | grep -v -e ":" | cut -d " " -f 1 | cut -d $'\t' -f 2`
# 	echo -e "\t\twith ID $NPATH/$(basename $DYNAME)"
# 	install_name_tool -id $NPATH/$(basename $DYNAME) ../Frameworks/$(basename $DYNAME)
#
# 	cd $TMP
# done
