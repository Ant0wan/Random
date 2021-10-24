#!/bin/bash
ip link set wlan0 down
ufw enable
apt update -y && sudo apt upgrade -y
apt install -y fail2ban
snap install canonical-livepatch
