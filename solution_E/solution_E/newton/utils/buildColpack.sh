#! /bin/bash

INST_DIR=$(pwd)/ColPack
echo "Extracting ColPack"
tar -xzf ColPack-1.0.9.tar.gz
echo "Configuring ColPack"
cd ColPack-1.0.9
./configure --prefix=$INST_DIR > /dev/null 2>&1
echo "Building ColPack"
make > /dev/null 2>&1
echo "Installing Colpack to $INST_DIR"
make install > /dev/null 2>&1
cd ..
rm -rf ColPack-1.0.9

