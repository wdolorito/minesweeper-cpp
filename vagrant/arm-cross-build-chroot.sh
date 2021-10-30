#!/bin/bash

# create chroot
mkdir armhf-chroot
cd armhf-chroot
sudo debootstrap --arch=armhf --foreign bionic .
sudo mount -o bind /dev dev
sudo mount -t proc proc proc
sudo mount -t sysfs sys sys
sudo cp /usr/bin/qemu-arm-static usr/bin
sudo cp -r /home/vagrant/project root
sudo cp /home/vagrant/build-wxWidgets.sh root
sudo cp /home/vagrant/build-project.sh root
sudo chroot . /debootstrap/debootstrap --second-stage
sudo chroot . apt-get update
sudo chroot . apt-get -y install software-properties-common
sudo chroot . add-apt-repository universe
sudo chroot . apt-get update
sudo chroot . apt-get -y install make clang lld-6.0 libgtk-3-dev libfuse2 pkg-config libgdk-pixbuf2.0-dev
sudo umount sys
sudo umount proc
sudo umount dev
