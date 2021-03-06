dotfiles
================
This project records my configuration files, including bash configurations, text editor configurations, etc. Since I broke my OS quite often, this project serves as a quick recovery. If you find this repository useful, please star it to let me know. :)

Install
----------------
In the top-level directory, run the following command in the terminal:

    ./install.sh

This will do the following things:  
1. update vim setttings  
2. install CMake 3.5.1  
3. (If QtCreator has been installed) After installing qt creator, put several style configuration files (monokai.xml, dusk.xml, twilight.xml) in ~/.config/QtProject/qtcreator/styles/ and select scheme in Text Editor preferences.  
4. install sublime text 3 (build_3103) and install package manager.  
5. For Linux only: install meshlab (the mesh viewer), VTK-7.0.0 (used in many 
graphics projects), igraph (the network analysis library).     

NOTICE: I tried hard to make the install.sh bash robust to unexpected errors. 
However, the script may perform differently under different Linux ditributions. 
Use it at your own discretion

Contact
----------------
Tianwei Shen <shentianweipku@gmail.com>, HKUST.  
License: BSD-3
