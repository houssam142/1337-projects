#!/bin/bash

npm install -g pnpm -y

git clone https://github.com/portainer/portainer.git

cd portainer

make deps

make dev

npx http-server ./portainer/app -a 0.0.0.0 -p 9443 8999
