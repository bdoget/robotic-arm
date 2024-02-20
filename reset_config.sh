#!/bin/bash
if [ -f "meta/config.txt" ]; then

    old_user=$(cat meta/config.txt)
    arduino-cli config set directories.user $old_user
    echo "Successfully reset config settings."
else 
    echo "No 'meta/config.txt' found."
fi