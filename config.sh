#!/bin/bash

if [ ! -f "meta/config.txt" ]; then
    # define meta folder
    mkdir -p "meta"

    # store old config user setting
    config_dump=`arduino-cli config dump`
    old_user=$(echo $config_dump | awk -F'user: ' '{print $2}' | awk '{print $1}')
    echo $old_user > meta/config.txt
    echo "Stored old config settings in '/meta/config.txt'"

    # set new config user to pwd
    arduino-cli config set directories.user `pwd`
    echo "Set new config settings to '`pwd`'."

else 
    echo "Already set up config settings. If this was a mistake, remove '/meta/config.txt' and retry."
fi


