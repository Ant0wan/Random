# Build:
#	podman build -t myvim:0 .
#
# Usage:
#	podman run -it --rm test:pod0
#
FROM debian:buster

LABEL maintainer "abarthel <abarthel@student.42.fr>"

RUN apt-get update

RUN apt-get install -y gcc

RUN mkdir /root/bin

WORKDIR /root/bin

COPY output_on_fd.c /root/bin

RUN gcc output_on_fd.c -o output_on_fd
