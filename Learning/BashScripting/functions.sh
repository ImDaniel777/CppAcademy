#!/bin/bash
function sum() 
{
    local var
    GLOBAL_VARIABLE="Global variable"
    for value in "$@"
    do
        ((var+=$value))
    done
    echo $var
}
echo $GLOBAL_VARIABLE #not available here
sum 1 2
echo $GLOBAL_VARIABLE

function backup_file()
{
    local file_passed=$1
    if [ -f file_passed ]
    then
        local BACK="/tmp/$(basename ${file_passed}).$(data + %F).$$"
        echo "Backing up ${file_passed} to ${BACK}"
        cp $file_passed $BACK
    else
        return 1
    fi
}