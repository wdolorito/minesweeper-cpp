#!/bin/bash

# compile wxWidgets
mkdir -p local/src/wxWidgets-3.0.3-configure-32
mkdir -p local/src/wxWidgets-3.0.3-configure-64
cd local/src
tar xf /home/vagrant/project/packages/wxWidgets-3.0.3.tar.bz2

# compile/install i686 wxWidgets
cd /home/vagrant/local/src/wxWidgets-3.0.3-configure-32
../wxWidgets-3.0.3/configure --prefix=/home/vagrant/local-i686 --enable-stl --disable-threads --host=i686-w64-mingw32 --with-msw
make
make install

# compile/install x86_64 wxWidgets
cd /home/vagrant/local/src/wxWidgets-3.0.3-configure-64
../wxWidgets-3.0.3/configure --prefix=/home/vagrant/local-x86_64 --enable-stl --disable-threads --host=x86_64-w64-mingw32 --with-msw
make
make install
