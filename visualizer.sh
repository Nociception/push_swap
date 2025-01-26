#!/bin/bash

advices_and_credits="
The visualizer interface is made of three movable blocs.\n\
I suggest you to move them to the right side of your screen,\n\
and to spread them to avoid overlaping between them.\n\
\n\
Usage:\n\
- read there : https://github.com/o-reo/push_swap_visualizer/blob/master/README.md#usage \n\
or\n\
- shortly:\n\
    - First: \"Values\" bloc:\n\
        - Set the random unique int list size\n\
        - click on Shuffle\n\
        - and then on the bottom, on Compute\n\
    - Second: \"Controls\" bloc\n\
    - \"Commands\" bloc: read the moves number (enlarge the bloc if necessary)\n\
\n\
Remind to thank https://github.com/o-reo by starring his repo ;)\n"


if [ ! -f push_swap ]; then
    printf "push_swap binary file does not exist\n\
    Please \"make\" before to compile and generate it.\n"
    exit 0
fi

if [ -f push_swap_visualizer/build/bin/visualizer ]; then
    printf "%b" "$advices_and_credits"
    read -p "Got it ? [Y/N]: " answer;
    if [ "$answer" = "Y" ] || [ "$answer" = "y" ]; then
        cd push_swap_visualizer/build
        ./bin/visualizer
        exit 0
    else
        printf "Exiting...\n"
        exit 0
    fi
fi

printf "As the push_swap_visualizer does not seem to be installed,\n\
this .sh file will then lead to:\n\
- clone a project (https://github.com/o-reo/push_swap_visualizer)\n\
    and automate these install instructions\n\
    https://github.com/o-reo/push_swap_visualizer/blob/master/README.md#install \n\
- install its dependencies with sudo apt-get if you do not have them:\n\
    - sudo apt-get update\n\
    - sudo apt-get install cmake\n\
    - sudo apt-get install g++\n\
    - sudo apt-get install clang\n\
    - sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev\n\
    - sudo apt-get install libx11-dev libxrandr-dev\n\
    - sudo apt-get install libudev-dev\n\
    - sudo apt-get install libfreetype-dev\n\
\nAll these steps: \n\
- can take one or two minutes\n\
- will ask you to authorize the installation (using sudo)\n"

read -p "Are you ok with that ? [Y/N]: " answer;
if [ "$answer" = "Y" ] || [ "$answer" = "y" ]; then
    printf "Proceeding...\n";

    git clone https://github.com/o-reo/push_swap_visualizer
    cd push_swap_visualizer
    rm -rf .git
    mkdir build
    cd build
    cmake ..
    make

    printf "%b" "$advices_and_credits"
    read -p "Got it ? [Y/N]: " answer;
    if [ "$answer" = "Y" ] || [ "$answer" = "y" ]; then
        ./bin/visualizer
        exit 0
    else
        printf "Exiting...\n"
        exit 0
    fi

else
    printf "Procedure cancelled.\n";
    exit 0
fi
