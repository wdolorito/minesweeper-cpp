#!/bin/bash

# create chroot
cd armhf-chroot
sudo mount -o bind /dev dev
sudo mount -t proc proc proc
sudo mount -t sysfs sys sys
sudo chroot .
