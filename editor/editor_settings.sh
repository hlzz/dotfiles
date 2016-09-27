#############################################
#           Editor settings                 #
#############################################
# vim configuration
cp vimrc ~/.vimrc   # copy the vim configuration file
rm -rf ~/.vim       # delete old vim settings if any 
rsync -av vim ~/    # copy the new one
mv ~/vim ~/.vim     # change the folder name

# put monokai.xml into the qt-creator config folder
if [ -d ~/.config/QtProject/qtcreator/styles ]; then 
    cp monokai.xml ~/.config/QtProject/qtcreator/styles/
    cp dusk.xml ~/.config/QtProject/qtcreator/styles/
    cp twilight.xml ~/.config/QtProject/qtcreator/styles/
else
    if [ -d ~/.config ]; then 
        mkdir ~/.config/QtProject
        mkdir ~/.config/QtProject/qtcreator
        mkdir ~/.config/QtProject/qtcreator/styles
        cp monokai.xml ~/.config/QtProject/qtcreator/styles/
        cp dusk.xml ~/.config/QtProject/qtcreator/styles/
        cp twilight.xml ~/.config/QtProject/qtcreator/styles/
    fi
fi

# install sublime_text_3
echo "Installing Sublime Text 3"    
sudo tar -vxjf sublime_text_3_build_3103_x64.tar.bz2 -C /opt
sudo ln -s /opt/sublime_text_3/sublime_text /usr/bin/sublime3
sudo cp /opt/sublime_text_3/sublime_text.desktop /usr/share/applications/
if [ -d ~/.config/sublime-text-3/Installed\ Packages ]; then
    cp Package\ Control.sublime-package ~/.config/sublime-text-3/Installed\ Packages/
else
    mkdir ~/.config/sublime-text-3 && mkdir ~/.config/sublime-text-3/Installed\ Packages
    cp Package\ Control.sublime-package ~/.config/sublime-text-3/Installed\ Packages/
fi
