#!/bin/bash
xzcat ~/Downloads/<image-file.xz> | sudo dd of=<drive address> bs=32M
