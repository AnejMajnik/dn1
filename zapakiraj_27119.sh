#!/bin/bash

# generacija date
date=$(date +'%Y-%m-%d--%M-%S')

# print date
echo "Date: $date"

# Prijava v docker
docker login -u $DOCKER_USERNAME -p $DOCKER_PASSWORD

echo "date=$date" >> "$GITHUB_ENV"

# izgradnja docker slike
docker build . --file Dockerfile --tag $REPONAME:$date

# Push slike na Docker Hub
docker push $REPONAME:$date