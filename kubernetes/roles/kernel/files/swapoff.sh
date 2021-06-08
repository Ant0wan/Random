#!/bin/bash
swapoff -a
sed -i '/ swap / s/^/#/' /etc/fstab
printf '$-0i\n@reboot\t\troot\tswapoff -a\n.\nw\n' | ex -s /etc/crontab
