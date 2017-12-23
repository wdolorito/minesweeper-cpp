WXLIBPOSTFIX=*wx*dylib
APP=Minesweeper

WXLIBDIR=/Users/d0odman/local/lib
BINDIR=./build/Release/$APP.app/Contents/MacOS
LIBDEFDIR=/usr/local/lib

mkdir -p $BINDIR
echo "Copying dynamic libraries to " $BINDIR " ..."
cp $WXLIBDIR/*.dylib $BINDIR

echo "Changing directory to " $BINDIR " ..."
export TMP=$PWD
cd $BINDIR

# patch all wx dynlibs and Saracon executable
for file in `ls $WXLIBPOSTFIX`
do
	# patch all library internal cross references
	echo "Patching " $file "..."
	for fileother in `ls $WXLIBPOSTFIX `
		do
			# library
			echo "  Patching " $fileother " with " $file "..."
			install_name_tool  -change $LIBDEFDIR/$file @executable_path/$file  $fileother
		done
	# patch current library itself
	install_name_tool  -id  @executable_path/$file  $file
	# patch executable
	install_name_tool  -change $LIBDEFDIR/$file @executable_path/$file $APP
done
cd $TMP