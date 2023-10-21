#!/bin/bash
echo "No. of files is $(find "$@" -type f | wc -l)"