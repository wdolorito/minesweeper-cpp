#!/bin/bash

# update system
sudo apt-get update
sudo apt-get -y dist-upgrade

# install build tools
sudo apt-get -y install make clang lld libwxgtk3.0-dev libfuse2 pkgconf libgdk-pixbuf2.0-dev libgtk-3-dev

# move build scripts
mv /tmp/build-wxWidgets.sh /home/vagrant
mv /tmp/build-project.sh /home/vagrant
chmod +x /home/vagrant/build-wxWidgets.sh
chmod +x /home/vagrant/build-project.sh
