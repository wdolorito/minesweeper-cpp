#!/bin/bash

# compile i686 project
cd /home/vagrant/project
PATH=/home/vagrant/local-i686/bin:$PATH make -f Makefile.mswx distclean
PATH=/home/vagrant/local-i686/bin:$PATH make -f Makefile.mswx release

# pacakage i686 project
cd packages/wxMSW
./cross_container_package.sh

# compile x86_64 project
cd /home/vagrant/project
PATH=/home/vagrant/local-x86_64/bin:$PATH make -f Makefile.mswx distclean
PATH=/home/vagrant/local-x86_64/bin:$PATH make -f Makefile.mswx release

# pacakage i686 project
cd packages/wxMSW
./cross_container_package.sh
