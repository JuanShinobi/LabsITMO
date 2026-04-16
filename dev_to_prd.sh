#!/bin/bash

git checkout prd
git merge dev

tag="stg_$(date +%Y%m%d_%H%M)"
git tag $tag

git push origin prd --tags
