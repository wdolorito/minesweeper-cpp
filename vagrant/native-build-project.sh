#!/bin/bash

# compile project
cd /home/vagrant/project
PATH=/home/vagrant/local/bin:$PATH make distclean
PATH=/home/vagrant/local/bin:$PATH make release

# pacakage project
cd packages/wxGTK
./package_appimage.sh
