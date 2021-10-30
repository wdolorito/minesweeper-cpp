#!/bin/bash

# update system
sudo apt-get update
sudo apt-get -y dist-upgrade

# install build tools
sudo apt-get -y install make bzip2 g++-mingw-w64-i686 g++-mingw-w64-x86-64 p7zip-full dos2unix

# move build scripts
mv /tmp/build-wxWidgets.sh /home/vagrant
mv /tmp/build-project.sh /home/vagrant
chmod +x /home/vagrant/build-wxWidgets.sh
chmod +x /home/vagrant/build-project.sh
