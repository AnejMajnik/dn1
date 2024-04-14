#!/bin/bash

# Prijava v docker
docker login -u $DOCKER_USERNAME -p $DOCKER_PASSWORD

docker pull $REPONAME:$TAG

docker run $REPONAME:$TAG
