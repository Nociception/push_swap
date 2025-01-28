# Overview
Push Swap is [42](https://42.fr)'s common core project.
The aim is to sort an integer stack in a minimum number of moves in a specific context where they are restricted.

![visualizer_preview.gif](https://github.com/Nociception/assets_storage/blob/main/push_swap/visualizer_preview.gif)

---

# Summary
1. [Introduction](#Introduction)
2. [Getting started](#Getting-started)
3. [Setting basic tools](#Setting-basic-tools)
4. [Usage](#Usage)
5. [Aim and Rules](#Aim-and-Rules)
6. [Sort method](#Sort-method)
7. [Tests and Visualization](#Tests-and-Visualization)

---

# Introduction
With these specific rules (which I had never seen elsewhere), this project gave me something to think about during all the days I worked on it ^^ I remember, it was something like an obsession.
Never enough optimization! In fact, when I read it now, I have new ideas, but it is not the time anymore to improve this project's algorithm.

Apart from that, it was also the opportunity to better master linked list (discovered in the first 42's common core project libft, which is by the way included in my push_swap): double linked list! After this project, this concept was my first choice to solve many C challenges. Parsing was also my best one so far.

Note: project's files and directories tree structure have been reorganized. It is of course not the same as in the official 42's repo ; algorithm did not change (so far).

---

# Getting started
## Installation
1. Clone the project
  ```bash
  git clone https://github.com/Nociception/push_swap ; cd push_swap
  ```
2. Compile the project (using `make`):
   ```bash
   make
   ```
3. Run it:
   ```bash
   ./push_swap 5 -8 7 55 6
   ```
   Change the integers as you want, add or remove some.
   But be careful: no duplicates, nor unvalid character (something different than `-+0123456789`).

---

# Setting basic tools
This section is designed for users who do not know git or make. Skip it is not the case.
Otherwise, read carefuly the following steps.
1. Open a terminal window which should look like this (search among your app/software list):
![terminal_picture](https://github.com/Nociception/assets_storage/blob/main/global/terminal_picture.png)

You are now going to type some things in this basic window which accepts text, also called commands:
type it, and then press Enter to run it.
You cannot type anything you would like to, as not everything is a valid command: `lol` will not work, whereas `ls` will.

The following steps contain black boxes where proper commands are showed. To run the program, follow then these steps by typing and running these commands in your terminal window.
Some of them may require you to type your computer password. You will not see any * character as you are maybe used to. If you want to move on these steps with these commands, type it and press Enter.

Some commands will lead to new lines (not typed by you) display. They sometime can be numerous ; reading all of them can be quite long, provided that you would understand them. During this display, you cannot type any new command. Once the process is done, the prompt is given back to you, and you can type a new command.

Tip: spot the little square on each of these code boxes (just below in this tutorial), on right side: click on it to copy the command (it can be faster and easier than selecting and copying it). Once back in your terminal, Ctrl + Shift + v to paste it. (The Shift is important ; without, the paste could somehow fail).

2. Install `git`:
   You maybe already have it ; check it out:
   ```bash
   git --version
   ```
   If you have something like: git version 2.34.1 (version number can be different)
   Then go to the step 3.
   Otherwise, install it:
   ```bash
   sudo apt install git
   ```

   You can now clone the project, but you should reach the end of this section before. Read more about git [here](https://en.wikipedia.org/wiki/Git)

4. Install `make`:
   You can run the program with or without `make`.
   However, without is not something you want to with a C written program.

   You maybe already have it ; check it out:
   ```bash
   make --version
   ```
   If you have something like:

   GNU Make 4.3
   Built for x86_64-pc-linux-gnu
   Copyright (C) 1988-2020 Free Software Foundation, Inc.
   License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
   This is free software: you are free to change and redistribute it.
   There is NO WARRANTY, to the extent permitted by law.

   Then go to the step 5.

   Otherwise, install it:
   ```bash
   sudo apt install make
   ```
   By the way, it could be useful for other projects you would clone!
   Some of them automate many things.
   It would require a lot of manual typing in your terminal without it.
   Read more about `make` [here](https://en.wikipedia.org/wiki/Make_(software)).

5. Install `gcc`:
   You maybe already have it ; check it out:
   ```bash
   gcc --version
   ```
   If you have something like:
   gcc (Ubuntu 10.5.0-1ubuntu1~22.04) 10.5.0
   Copyright (C) 2020 Free Software Foundation, Inc.
   This is free software; see the source for copying conditions.  There is NO
   warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

   Then skip this step and go back to [the main installation guide](#Getting-Started).
   Otherwise, install it:
   ```bash
   sudo apt install gcc
   ```

   gcc compiles .c and .h files to produce .o files, gathered to generate a binary executable file : the program.
   Read more about it [here](https://fr.wikipedia.org/wiki/GNU_Compiler_Collection)

   You and your computer are now ready to install the program! Go back to [the main installation guide](#Getting-Started).

---

# Aim and Rules

## Start End
Start: you receive a randomly chosen integers in a stack (which we will call `A`), and have at your disposal another stack `B`, empty.
This `B` stack is in fact essential: with many numbers at start, you have to use it to get a proper `score`.
You must sort `A` in the `ascending order`, from top to bottom.

```
 1                                         1
 8                                         5
 6                ---- goal ---->          6
 9                                         8
 5                                         9
 A      B                                  A      B
```

## Score
You must strive to sort the `A` stack by using the less `moves`.
`B` must be empty at the end, as no integer can miss in `A`.

With a 100 integers stack, you must use less than 700 `moves` to get the maximum score.

With a 500 integers stack, less than 5500 `moves` gives the maximum score.

## Moves
You cannot move any number anywhere as you want. Here are the only possible moves:

![terminal_picture](https://github.com/Nociception/assets_storage/blob/main/push_swap/push_swap_moves.webp)

[credits](https://medium.com/@kilfenbaridon/how-to-over-optimize-an-algorithm-push-swap-42-school-project-d01a50e5fd78)

## Output
The program must then display all the moves, in the proper order, which lead to sort the `A` stack in the ascending order (from top to bottom).
For instance, to sort the [exemple](#Start-End) in the Start End section (try it before reading the solution, if you want to understand better):
```bash
./push_swap 1 8 6 9 5
pb
rra
pb
sa
pa
pa
```
Note: not all the moves are necessary here.

## Check
So you get moves, in a specific order. But how to be sure the stack is properly sorted when applying them ?
42 provides a `checker` which I cannot share here (but if you are an active 42 student, use it ^^).
Fortunatly, I did the bonus part, which asks us to write our own `checker` (generate it with `make bonus`).
Read the [Makefile](https://github.com/Nociception/push_swap/blob/main/Makefile)'s test rules and the [test.sh](https://github.com/Nociception/blob/main/test.sh)'s file to know how my automatic tests work, and what exactly they do.

To activate the `checker mode`, change the Makefile variable's value `CHECKER` to 1, 2 or 3 (depending on which checker you choose).

Usage:
Makefile's variables are settable to adjust these rules' behavior.
- test for 100 unique random integers:
```bash
make test100
```
- test for 500 unique random integers:
```bash
make test500
```
- customized test:
Read the Makefile's rule to know what to type.
```bash
make test-custom min max size display_list checker
```

# Algorithm
I heard about many algorithms already designed for this project. I knew before starting it that I wanted to create my own (no matter if I potentially get eventually and unwillingly one of them, without knowing it). That kind of puzzle is my thing.

Further details and explanation about it later. In fact, I must plunge back into the depth of my code, as I wrote it at the beginning of 42's common core back then. You get it: maybe not the easiest code to understand 😬
But I have, far away somewhere in my memory, the logic/idea. Some variables' value are set for a 100 integers stack, and differently set for 500 (which are the two big sizes tested for getting the project validated).

Furthermore, I do not claim any perfection. In the end (for the defense), I was somehow satisfied. Write about now incents me to improve it again, which I will not.
