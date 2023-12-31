#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>

struct string {
	int capacity;
	int size;
	char* data;
};
typedef struct string String;

typedef void* MY_STRING;

enum Status{FAILURE, SUCCESS};
typedef enum Status Status;
// Precondition: None 
// Postcondition: Allocate space for a string object that represents an empty 
// string. The string will have capacity 7 and the size 0 by default. A copy of 
// the address of the opaque object will be returned on success and NULL on
// failure

MY_STRING my_string_init_default(void);

// Precondition: phMy_string hold the address of a valid handle to MY_STRING
// object.
// Postcondition: The memory used for the MY_STRING object has be reclaimed by 
// the system and the handle referred to by the pointer phMy_string has been
// set to NULL

void my_string_destroy(MY_STRING* phMy_string);

// Precondition: c_string is a valid null terminated c-string.
// Postcondition: Allocate space for a string object that represents a string 
// with the same value as the given c-string. The capacity of the string.
// As an example, the string "the" would set the capacity at 4 instead of 3. A
// copy of the address of the opaque object will be returned on success and 
// NULL on failure.

MY_STRING my_string_init_c_string(const char* c_string);

// Precondition: hMy_string is the handle of a valid My_string object.
// Postcondition: Returns a copy of the integer value of the object's capacity.
int my_string_get_capacity(MY_STRING hMy_string);

// Preconditin: hMy_string is the handle of a valid My_string object.
// Postcondition: Returns a copy of the integer value of the object's size.
int my_string_get_size(MY_STRING hMy_string);

// Precondition: hLeft_string and hRight_string are valid My_string objects.
// Postcondition: returns an integer less than 0 if the string is represented 
// by hLeft_string is lexicographically smaller than hRight_string. If 
// one string is a prefix of the other string than the shorter string is 
// considered to be the smaller one. (app is less than apple). Returns  
// 0 if the strings are the same and returns a number greater than zero
// if the string represented by hLeft_string is bigger than hRight_string.
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string);

//Precondition: hMy_string is the handle to a valid My_string object.
//Postcondition: HMy_string will be the handle of a string object that contains
// the next string from the file stream fp according to the following rules.
// 1) Leading whitespace will be ignored.
// 2) All characters (After the first non-whitespace character is obtained 
// and included) will be added to the string until a stopping condition is 
// met. The capacity of the string will continue to grow as needed until all 
// characters are stored.
// 3) A stopping condition is met if we reaqd a whitespace character or if we reach EOF
// Function will return SUCCESS if a non-empty string is read successfully and failure otherwise.
// Remember that the incoming string may already 
// contain some data and this function should replace the data but not
// necessarily resize the array unless needed.
Status my_string_extraction(MY_STRING hMy_string, FILE* fp);

//Precondition: hMy_string is the handle to a valid My_string object.
//Post condition: Writes the characters contained in the string object indicated
// by the hMy_string to the file stream fp.
// Function will return SUCCESS if it successfully writes the string and 
// FAILURE otherwise.
Status my_string_insertion(MY_STRING hMy_string, FILE *fp); 
#endif // !MY_STRING_H

