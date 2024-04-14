#!/bin/bash

echo "Date: $date"

# Prijava v docker
docker login -u $DOCKER_USERNAME -p $DOCKER_PASSWORD

echo "date=$(date +'%Y-%m-%d--%M-%S')" >> "$GITHUB_ENV"


# izgradnja docker slike
docker build . --file Dockerfile --tag $REPONAME:$date

# Potisnite sliko na Docker Hub
docker push $REPONAME:$date