#!/usr/bin/env bash
set -e
sudo dd if=2020-02-13-raspbian-buster-lite.img of=/dev/mmcblk0 bs=4M
touch /run/media/${USER}/boot/SSH
echo "Eject card !"
