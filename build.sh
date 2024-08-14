#!/bin/bash

cd build
cmake ..
make
sudo make install

cd ../cli
poetry build
# poetry export > dist/requirements.txt
# python3 -m pip install -r dist/requirements.txt
python3 -m pip install ./dist/gfuzz-*.whl --force-reinstall
