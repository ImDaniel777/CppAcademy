#!/bin/bash -x
projectPath=$(pwd)
server=$projectPath"/server"
client=$projectPath"/client"
compile_app(){
    g++ $server.cpp -o $server
    g++ $client.cpp -o $client
}
start_process() {
    local app_path="$1"
    x-terminal-emulator -e "$app_path"
}

# echo Do you want to start the client/server app? y/n
# read input
# if [[ $input == 'y' ]]; then
echo Script must be in the application folder
compile_app
start_process "$server"
start_process "$client"
# elif [[ $input == 'n' ]]; then
    # echo Exiting..
# else
    # echo Invalid input
# fi  

