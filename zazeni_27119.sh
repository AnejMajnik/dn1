#!/bin/bash

# Prijava v docker
docker login -u $DOCKER_USERNAME -p $DOCKER_PASSWORD

docker pull $REPONAME:latest

docker run $REPONAME:latest
