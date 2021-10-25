#!/usr/bin/env bash
#snap info microk8s
export k8s_version='1.17'
snap install microk8s --classic --channel=${k8s_version}/stable
