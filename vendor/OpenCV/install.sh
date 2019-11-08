#!/bin/bash

sudo apt-get install libopenblas-dev liblapack-dev libx11-dev build-essential cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev

cd ../vendor/opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
make -j12
sudo make install
