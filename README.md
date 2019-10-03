# Hurricane Irma Moves
Implementing an interpreter foralgebraic notation for recording and describing the hurricane Irma moves.
This program was written in C and contains a .c and .h file with multiple test cases to see the movement throughout the 2D array, or in this case, the table.

## To read about hurricane Irma
https://en.wikipedia.org/wiki/Hurricane_Irma

Hurricane Irma directly affected my city at the time I was studying so this project was fun to do :)

## IrmaMoves.c
This file is the main file that contains all the logic for the movement of Irma. Below is a breakdown of all the functions and how they work.

## IrmaMoves.h
Included with this project is a customer header file that includes the struct definitions and functional prototypes for the functions that are implemented.
This file was intended to be a bridge for the main source files.
There are three structs in this file.

## Testcases
There is a folder labeled "testcases" that can be used to see how the program executes with different cases.

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
The return value is the pointer to the allocated 2D array. Or null if any call to malloc() fails.

### parseNotationString(char str, Move irmaMove);
This function recieves an algebraic notation string (str) and one (Move) struct pointer. The function will parse str and extract information about Irma moves encoded there, and populate all corresponding fields in the struct pointed to by irmaMove.
It will set the from_location, current_location, to_location, irma.windspeed, and irma.windgusts feilds in the struct. With this information, it will denote which column and/or row the Irma's move is coming from and determine where Irma will end.
There is no return value.

## Compiling
To compile a file at the command line:
- gcc IrmaMoves.c

To run the file:
- ./IrmaMoves.exe

To run with a test case:
- gcc IrmaMoves.c testcase01.c

Running the program could potentially dump a lot of output to the screen. If you want to redirect your output to a text file in Linux just run the program using the following command, which will create a file called whatever.txt that contains the output from your program
- ./IrmaMoves.exe > whatever.txt

I personally used Code::Blocks to write this program.
- http://www.codeblocks.org/
