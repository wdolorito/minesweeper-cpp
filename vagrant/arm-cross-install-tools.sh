#!/bin/bash

# update system
sudo apt-get update
sudo apt-get -y dist-upgrade

# install build tools
sudo apt-get -y install qemu-user-static debootstrap

# move build scripts
mv /tmp/build-wxWidgets.sh /home/vagrant
mv /tmp/build-project.sh /home/vagrant
mv /tmp/build-chroot.sh /home/vagrant
mv /tmp/cleanup-chroot.sh /home/vagrant
mv /tmp/enter-chroot.sh /home/vagrant
chmod +x /home/vagrant/build-wxWidgets.sh
chmod +x /home/vagrant/build-project.sh
chmod +x /home/vagrant/build-chroot.sh
chmod +x /home/vagrant/cleanup-chroot.sh
chmod +x /home/vagrant/enter-chroot.sh
