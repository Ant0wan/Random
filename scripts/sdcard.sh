#!/usr/bin/env bash
set -e
source ./os.sh
export DEVICE='/dev/mmcblk0'

xzcat ${TMP}${BIN} | sudo dd of=${DEVICE} bs=32M
