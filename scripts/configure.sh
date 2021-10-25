#!/usr/bin/env bash
set -e
#ip link set wlan0 down
#ufw enable
#apt update -y && sudo apt upgrade -y
#apt install -y fail2ban
#snap install canonical-livepatch
#modprobe br_netfilter
if (id -u); then echo "Should run as root"; fi
sed -e 's/^/cgroup_enable=memory cgroup_memory=1 /g' -i /boot/firmware/cmdline.txt
echo "Need reboot"
