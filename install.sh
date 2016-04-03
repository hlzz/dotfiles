#!/bin/sh

platform='unknown'
unamestr=`uname`
if [[ "$unamestr" == 'Linux' ]]; then
   platform='linux'
elif [[ "$unamestr" == 'FreeBSD' ]]; then
   platform='freebsd'
fi

# vim configuration
cp vimrc ~/.vimrc   # copy the vim configuration file
rm -rf ~/.vim       # delete old vim settings if any 
rsync -av vim ~/    # copy the new one
mv ~/vim ~/.vim     # change the folder name

# install the cmake 3.5.1
cd cmake-3.5.1
./bootstrap && make && sudo make install

# put monokai.xml into the qt-creator config folder
if [ -d ~/.config/QtProject/qtcreator/styles ]; then 
    cp monokai.xml ~/.config/QtProject/qtcreator/styles/
    cp dusk.xml ~/.config/QtProject/qtcreator/styles/
    cp twilight.xml ~/.config/QtProject/qtcreator/styles/
fi

# install sublime_text_3
sudo tar -vxjf sublime_text_3_build_3103_x64.tar.bz2 -C /opt
sudo ln -s /opt/sublime_text_3/sublime_text /usr/bin/sublime3
sudo cp /opt/sublime_text_3/sublime_text.desktop /usr/share/applications/

# set up bash
if [[ $platform == 'linux' ]]; then
	cp bash/bashrc_centos ~/.bashrc
	cp bash/bash_profile_centos ~/.bash_profile
fi

echo "complete!"
