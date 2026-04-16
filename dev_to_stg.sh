#!/bin/bash

git checkout stg
git merge dev

tag="stg_$(date +%Y%m%d_%H%M)"
git tag $tag

git push origin stg --tags
