#!/bin/bash

# Check if a commit message was provided
if [ -z "$1" ]; then
  echo "⚠️ Please provide a commit message (like the problem name)."
  echo "Usage: ./sync.sh \"Solved Codeforces 71A\""
  exit 1
fi

echo "Syncing to GitHub..."

# The Git commands
git add .
git commit -m "$1"
git push origin main

echo "✅ Successfully pushed!"