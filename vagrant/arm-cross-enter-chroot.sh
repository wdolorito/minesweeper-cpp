#!/bin/bash

# prepare chroot
cd /home/vagrant/armhf-chroot
sudo mount -o bind /dev dev
sudo mount -t proc proc proc
sudo mount -t sysfs sys sys
sudo chroot .
