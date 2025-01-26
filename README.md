# Overview
Push Swap is [42](https://42.fr)'s common core project.
The aim is to sort an integers stack in a minimum number of moves in a specific context where they are restricted.

GIF/WEBP HERE

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
With these specific rules (which I had never seen elsewhere), this project gave me something to think during all the days I worked on it ^^ I remember, it was something like an obsession.
Never enough optimization! In fact, when I read it now, I have new ideas, but it is not the time anymore to improve this project's algorithm.

Apart from that, it was also the opportunity to better master linked list (discovered in the first 42's common core project libft, which is by the way included in my push_swap): double linked list! After this project, this concept was my first choice to solve many C challenges.

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

   Then skip this step and go back to [the main installation guide](#Getting-Started).

   Otherwise, install it:
   ```bash
   sudo apt install make
   ```
   By the way, it could be useful for other projects you would clone!
   Some of them automate many things.
   It would require a lot of manual typing in your terminal without it.
   Read more about `make` [here](https://en.wikipedia.org/wiki/Make_(software)).

   You and your computer are now ready to install the program! Go back to [the main installation guide](#Getting-Started).

---

# Aim and Rules

Start: you receive a randomly chosen integers stack (which we call `A`), and have at your disposal (essential in fact: to get a proper score, you have to use it) another stack `B`, empty.

 58                                      -45
-45                                      -2
 78                ---- goal ---->        8
-2                                        58
 8                                        78
`A`    `B`                                `A`    `B`




