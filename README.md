[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/CQ0jbgGv)

# PROJECT-DRKUJAWA21

Hello, this is a virtual ecosystem that I have created for my C++ programming class.
After you input the map and species list text files into the terminal after running main,
you will be able to run the ecosystem however many times you want. After each iteration,
you will be shown what the current ecosystem looks like.  

## How to run

Currently, there are some issues with my project (which I plan to fix this summer). The Makefile is how you are going to be able to run the project through. Ideally, you want to put your .txt files into the "input" directory to use. Right now, I have my .txt files in src, they should not be there, I am not sure how to fix my make file to be able to access the .txt files in the "input" directory.

1. In the src directory in your linux terminal, run "make".
2. Type "./ecosystem.bin" into the terminal. This starts the ecosystem. It is also the only build that currently works.
3. Input the name of your map file and then your species file. *NOTE* Currently, I have not made it so you can access .txt files in input. These files must be in src for now.
4. Type "y" to start the simulation or "n" to leave.
5. It will ask you how many times you want to run the simulation. One simulation is where each animal moves once. Input the number you want.
6. Type "y" to continue looping or "n" to leave.

## Code issues

There are some bugs in the code right now, specifically when an animal eats a plant.
To be more specific, when I look for a plant in "findPlant(Plant p)" it crashes but only when an animal is eating a plant, I get a vector out of range error. Besides that, I think there is also an issue with an animal getting its turn skipped sometimes, this one did not occur very often though.

The big issue right now is definitely eating plants.

## Github

drkujawa21











## Notes for myself, IGNORE

Day 1:
Created .h files for the species, movement, eating, and map. Established hierarchy.
Need to figure out how to read from .txt files and how to use them in the .h files.

Day 2:
Reduced amount of h files into 2. Created cpp files for all h files and created a main cpp file.
Working on how to parse the .txt files.
Need to finish parsing the .txt  files before anythign else.

Day 3:
Figured out how to read from file and put it into a map object. Created print functions for map.h. 
Need to next figure out how to move a species and create species from the species list in map. Might need to rearrange class hierarchy. !!!

Day 4:
Didnt get as much work done. 
Next goal is to figure out how to store each specimen and differentiate them from each other. A possible solution is to give each specimen a coordinate pair (ex. [row, col]).


Day 5:
Swapped to using unordered_map. Very helpful.
Trying to figure out how to store map.txt into an unordered_map.
Left off at main.cpp, continue work on Map.h. Pretty sure Species.h can wait for now.

Day 6:
Not much work. Day off lol. Need to figure out how to compare a char to other chars (if char is equal to " " or not).

Day ??:
Got tons done. Need to work on 1. figuring out what's wrong with map. 2. make file changes 3. omnivores cannot eat other omnivores