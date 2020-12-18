#!/bin/bash
APP=Minesweep
APPDIR=./$APP.AppDir
APPIMAGE=./appimagetool-x86_64.AppImage
UNAME_M=`uname -m`
if [ $UNAME_M == 'armv7l' ]; then
  APPIMAGE=./appimagetool-armhf.AppImage
fi
if [ $UNAME_M == 'i686' ]; then
  APPIMAGE=./appimagetool-i686.AppImage
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
LIBS=`ldd $APPBINDIR/$EXE | cut -d " " -f 3`
for lib in $LIBS
do
	cp $lib $APPLIBDIR
done

##
## modified from https://github.com/aferrero2707/appimage-helper-scripts/blob/master/bundle-gtk2.sh
##
## begin
##

echo ""
echo "========= compile Glib schemas ========="
# Compile Glib schemas
glib_prefix="$(pkg-config --variable=prefix glib-2.0)"
(mkdir -p "$APPDIR/usr/share/glib-2.0/schemas/" && \
cp -a ${glib_prefix}/share/glib-2.0/schemas/* "$APPDIR/usr/share/glib-2.0/schemas" && \
cd "$APPDIR/usr/share/glib-2.0/schemas/" && \
glib-compile-schemas .) || exit 1

echo ""
echo "========= copy gdk-pixbuf modules and cache file ========="
# Copy gdk-pixbuf modules and cache file, and patch the cache file
# so that modules are picked from the AppImage bundle
gdk_pixbuf_moduledir="$(pkg-config --variable=gdk_pixbuf_moduledir gdk-pixbuf-2.0)"
gdk_pixbuf_cache_file="$(pkg-config --variable=gdk_pixbuf_cache_file gdk-pixbuf-2.0)"
gdk_pixbuf_libdir_bundle="lib/gdk-pixbuf-2.0"
gdk_pixbuf_cache_file_bundle="$APPDIR/usr/${gdk_pixbuf_libdir_bundle}/loaders.cache"

mkdir -p "$APPDIR/usr/${gdk_pixbuf_libdir_bundle}"
cp -a "$gdk_pixbuf_moduledir" "$APPDIR/usr/${gdk_pixbuf_libdir_bundle}"
cp -a "$gdk_pixbuf_cache_file" "$APPDIR/usr/${gdk_pixbuf_libdir_bundle}"
sed -i -e "s|${gdk_pixbuf_moduledir}/||g" "$gdk_pixbuf_cache_file_bundle"

printf '%s\n' "" "==================" "gdk-pixbuf cache:"
cat "$gdk_pixbuf_cache_file_bundle"
printf '%s\n' "==================" "gdk-pixbuf loaders:"
ls "$APPDIR/usr/${gdk_pixbuf_libdir_bundle}/loaders"
printf '%s\n' "=================="

echo ""
echo "========= copy the theme engines ========="
# Copy the theme engines
mkdir -p "$APPDIR/usr/lib/gtk-3.0"
GTK_LIBDIR=$(pkg-config --variable=libdir gtk+-3.0)
GTK_BINARY_VERSION=$(pkg-config --variable=gtk_binary_version gtk+-3.0)
cp -a "${GTK_LIBDIR}/gtk-3.0/${GTK_BINARY_VERSION}"/* "$APPDIR/usr/lib/gtk-3.0"

##
## end
##

echo "Creating AppImage"
touch $APPDIR/built-on-$(date +%s)
${APPIMAGE} $APPDIR
mv ${APP}*.AppImage release

echo "Removing temporary files"
rm -rf $APPDIR
