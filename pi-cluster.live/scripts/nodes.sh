#!/bin/bash
set -e
sudo microk8s.join | tee join
microk8s.kubectl get node
echo "On workers, execute:
 \$> microk8s.join $(cat join)"
