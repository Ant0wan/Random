#!/bin/bash
set -e
export BIN='ubuntu-core-20-arm64+raspi.img.xz'
export URL='https://cdimage.ubuntu.com/ubuntu-core/20/stable/current/'
export TMP='/tmp/'

wget ${URL}${BIN} -O ${TMP}${BIN}
wget ${URL}SHA256SUMS -O ${TMP}coreos-shasums

diff <(echo $(cat ${TMP}coreos-shasums  | grep ${BIN} | awk '{ print $1 }')) <(echo $(sha256sum ${TMP}${BIN} | awk '{ print $1 }'))
