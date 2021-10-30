#!/bin/bash

# compile project
cd /root/project
PATH=/root/local/bin:$PATH make distclean
PATH=/root/local/bin:$PATH make release

# pacakage project
cd packages/wxGTK
./package_appimage.sh
