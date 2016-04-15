#!/bin/sh
# Tianwei Shen <shentianweipku@gmail.com>

set -e	# exit when encountering the first error
set -u 	# don't use uninitialised variables

# test operating system
platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
   platform='linux'
elif [[ "$unamestr" == 'FreeBSD' ]]; then
   platform='freebsd'
fi

#############################################
#           Editor settings                 #
#############################################
cd editor
./editor_settings.sh
cd .. && echo "finish editor settings"

#############################################
#          Develop settings                 #
#############################################
cd dev
# install the cmake 3.5.1
cd cmake-3.5.1
./bootstrap && make && sudo make install
cd ..

# set up bash
if [[ $platform == 'linux' ]]; then
	cp bash/bashrc_centos ~/.bashrc
	cp bash/bash_profile_centos ~/.bash_profile
fi
# install the system profiler on linux
if [[ $platform == 'linux' ]]; then
    cd netdata
    sudo ./netdata-installer.sh
    cd ..
fi
cd .. && echo "finish develop settings"

#################################################
#   Working environments settings               #
#################################################
if [[ $platform == 'linux' ]]; then
#######Install scientific packages#########
    cd science
    # install igraph, the network analysis library
    cd igraph-0.7.1
    ./configure && make && sudo make install
    # install ceres-solver
    # (TODO: tianwei) this is not complete installation
    # may need other dependencies such as eigen, cxsparse,...
    cd ../ceres-solver
    mkdir build && cd build
    cmake .. && make -j4 && sudo make install
    cd ../..    # back to science
    cd .. && echo "finish science package settings"
#######Install packages related to Graphics#########
    cd graphics
    # install meshlab on linux
	echo "Installing Meshlab"    
	cd meshlab/src/external && qmake-qt4 -recursive external.pro && make
	cd .. && qmake-qt4 -recursive meshlab_full.pro && make
    cd ../.. && echo "The compiled meshlab binary is in the distrib folder"
    # install vcglib to /usr/local/include
    sudo rsync -av vcglib/ /usr/local/include/vcglib
    # install VTK-7.0.0
    cd VTK-7.0.0/
    mkdir build && cd build
    cmake .. && make -j4 && sudo make install
    cd ../../cgal    # cd into cgal
    mkdir build && cd build
    cmake .. && make -j4 && sudo make install
    cd ../..        # back to graphics
    cd .. && echo "finish graphics settings"
fi

echo "complete!"
