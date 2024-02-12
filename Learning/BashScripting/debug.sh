#!/bin/bash -xev

# use -xev to enable debuging and exit on first error

PS4='+ ${BASH_SOURCE}:${LINENO}:${FUNCNAME[0]}()'

debug()
{
    echo "Executing: $0"
    $0
}

debug ls