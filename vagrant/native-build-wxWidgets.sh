#!/bin/bash

# compile wxWidgets
cd /home/vagrant
mkdir -p local/src/wxWidgets-3.0.3-configure
cd local/src
tar xf /home/vagrant/project/packages/wxWidgets-3.0.3.tar.bz2
cd wxWidgets-3.0.3-configure
CC=clang CXX=clang++ LDFLAGS=-fuse-ld=lld-6.0 ../wxWidgets-3.0.3/configure --enable-stl --disable-threads --disable-mediactrl --prefix=/home/vagrant/local
make
make install
