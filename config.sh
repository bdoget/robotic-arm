#!/bin/bash
 
# store old config user setting
config_dump=`arduino-cli config dump`
old_user=$(echo $config_dump | awk -F'user: ' '{print $2}' | awk '{print $1}')

echo $old_user >> meta/config.txt

# set new config user to pwd
arduino-cli config set directories.user `pwd`

# run file

# reset config user setting
arduino-cli config set directories.user $old_user



