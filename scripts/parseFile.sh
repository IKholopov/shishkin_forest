#!/bin/bash
cat $1 | ./graph && dot -Tsvg tree.dot -o tree.svg
