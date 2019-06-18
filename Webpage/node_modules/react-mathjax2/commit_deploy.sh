#!/bin/bash
# Builds, commits, and pushes

set -e # Exit immediately if a command exits with a non-zero status.
set -u # Treat unset variables as an error when substituting.

if [[ $# -ne 1 ]]; then
    echo "Usage ./commit_deploy.sh (commit message)"
    exit 0
fi

npm run build
git add .
git commit -m "$1"
git push
