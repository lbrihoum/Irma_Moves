# Irma Moves
Implement an interpreter foralgebraic notation for recording and describing the hurricane Irma moves.

## IrmaMoves.h
Included with this project is a customer header file that includes the struct definitions and functional prototypes for the functions that are implemented.
This file was intended to be a bridge for the main source files.
There are three structs in this file.

## Each function implemented
### createMapBoard(void);
This function dynamically allocating space for a 2D char array with dimensions 8x8, and populating the array with the initial configuration of a map board as described in “Appendix A: Irma Movement”.  It is hard coded to initialize the map configuration based on the information given.
It will return a pointer that is dynamically allocated or null if any calls to malloc() fails.
- Malloc() allocates the requested memory and returns a pointer to it.

### destroyMapBoard(char board);
This function frees all dynamically allocated memory associated with the board. The function recieves a dynamically allocated 2D char array with dimensions 8x8.
The return value will be null.

### printMapBoard(char board);
This function takes a pointer to an 8x8 char array and prints the map board represented by that array using the format described below. 
The return value is also null.

### predictIrmaChange(char str, Move irmaMove);
The best function!
This function starts by printing the map board with Irma in its starting position. This function calls createMapBoard() function to create a 2D char array to represent the map board, and then calls the printMapBoard() function to print it to the screen.
