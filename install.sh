#!/bin/sh

# vim configuration
cp vimrc ~/.vimrc   # copy the vim configuration file
rm -rf ~/.vim       # delete old vim settings if any 
rsync -av vim ~/    # copy the new one
mv ~/vim ~/.vim     # change the folder name

# install the cmake 3.5.1
cd cmake-3.5.1
./bootstrap && make && sudo make install

echo "complete!"
