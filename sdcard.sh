#!/usr/bin/env bash
xzcat /tmp/ubuntu-core-20-armhf+raspi.img.xz | sudo dd of=/dev/mmcblk0 bs=32M
