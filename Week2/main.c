/**
*							Evil Hangman - UML Computing II Lab
* Author: Evan Malia
* Description: Lab from the computing II course @ UML
* Date: 12/20/2023, 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <crtdbg.h>
#include "my_string.h"

int main(int argc, char* argv[]) {
	/*             Lab 2              */	
	MY_STRING hMy_string = NULL;
        MY_STRING string1 = NULL;
        MY_STRING string2 = NULL;
        hMy_string = my_string_init_default();
        //hMy_string = my_string_init_c_string("hi");

        string1 = my_string_init_c_string("Spencer is amazing");
        string2 = my_string_init_c_string("spencer");

	printf("String 1 has a size: %d and capacity: %d\n", my_string_get_size(string1), my_string_get_capacity(string1));
 	printf("String 2 has a size: %d and capacity: %d\n", my_string_get_size(string2), my_string_get_capacity(string2));

	printf("Compare string1 and string2: %d\n", my_string_compare(string1, string2));

	my_string_destroy(&hMy_string);
	my_string_destroy(&string1);
        my_string_destroy(&string2);

	return 0;
}
