#!/bin/bash
wget https://cdimage.ubuntu.com/ubuntu-core/20/stable/current/ubuntu-core-20-armhf+raspi.img.xz -O /tmp/ubuntu-core-20-armhf+raspi.img.xz
wget https://cdimage.ubuntu.com/ubuntu-core/20/stable/current/SHA256SUMS -O /tmp/coreos-shasums
diff <(echo $(cat /tmp/coreos-shasums  | grep ubuntu-core-20-armhf+raspi.img.xz | awk '{ print $1 }')) <(echo $(sha256sum /tmp/ubuntu-core-20-armhf+raspi.img.xz | awk '{ print $1 }'))
