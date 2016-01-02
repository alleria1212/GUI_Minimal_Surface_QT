#! /bin/bash
wget http://bitbucket.org/eigen/eigen/get/3.2.4.tar.gz
tar -xzf 3.2.4.tar.gz

cp -r eigen-eigen*/Eigen .

rm -rf eigen-eigen*
rm -f 3.2.4.tar.gz
