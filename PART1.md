# Part 1

## Video Demo

link to our demo : https://youtu.be/yTEdPkDRRz4

## Minimum Requirements

### Completed

List all the features completed.

1. Display game board 
2. Game settings 
3. Random game objects 
4. Center Alien position in the board
5. Alien movement across the board 
6. Game UI 
7. Game instruction (help)

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1. Game metrix for Zombies and Alien
2. Functions of game objects 
3. Zombie movements
4. Zombie and Alien attacks 
5. Edge of game board
6. Zombie trail 
7. Cool features 1 and 2
8. Saving the game 
9. Loading the game 
10. Do user manual


## Additional Features

Describe the additional features that has been implemented.

## Contributions


### Imran

1. Randomly generate game board.
2. Creating the game UI
3. Alien trail 


### Balvinder

1. Movement of Alien
2. Generate the game board
3. Added the object array


### Jeeva

1. Placing the Alien in the center of the board
2. Generate the game board
3. Help brainstorm and reasearch

## Problems Encountered & Solutions

### 1. Generating game board. The game board would generate with only '.' as rows and columns. Furthermore there were no lines to seperate each rows and columns. 

Solution : We online for ideas / inspiration and then experimented with varios positions of where to place the code so that the board will look as it should


### 2. Placing the Alien in the center of the board. The Alien would appear at only the top left of the board. After randomizing the game objects, the alien would appear at random places on the board  

Solution : We brainstorm the calculations necessarry then experimented with the placing of the calculations at different parts of the code. 


### 3. Figuring out the movement of the Alien accross the board. We realized that after creating the board, there was no way to move the Alien. 

Solution : First we tried to modify the code by adding or subtracting 1 from rows or colummns. However  we encountered another issue where doing that would move the entire column or row instead of just the alien. With a lot of code-fondling and senior advice, we figured it out there was an issue with the board itself. So we had to reconstruct the whole grid from scratch using 2D arrays.


### 4. Figuring out how to randomly fill up the game grid with the other game objects. 

Solution : First we declared an array of several characters datatypes. Then we used the rand() function to print out a grid with objects placed at random 


