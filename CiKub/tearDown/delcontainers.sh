#!/bin/bash
# docker rm --force $(docker ps --all --quiet)
for ID in $(docker ps --all --quiet); do docker rm --force $ID ; done
