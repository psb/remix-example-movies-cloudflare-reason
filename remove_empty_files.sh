#!/bin/bash

grep -Ril \
    --exclude-dir={_opam,_build,node_modules} \
    --include=\*.js \
    -e "\/\* This output is empty. Its source's type definitions, externals and\/or unused code got optimized away. \*\/" . \
    | xargs echo \
    | xargs rm -f