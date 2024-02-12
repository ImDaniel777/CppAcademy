#!/bin/bash -xev

case "$1" in
    start)
        echo "starting scrip"
        ;;
    stop)
        echo "stopping script"
        ;;
esac

read -p "Do you want to continue?" ANSWER
case "$ANSWER" in
    [yY]|[yY][eE][sS])
        echo "Yes"
esac