#!/bin/bash
./build/funjson_test -f data/input.json -s tree -i slice
./build/funjson_test -f data/input.json -s tree -i heart
./build/funjson_test -f data/input.json -s rect -i slice
./build/funjson_test -f data/input.json -s rect -i heart