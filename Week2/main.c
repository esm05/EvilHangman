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
	//hMy_string = my_string_init_default();
	hMy_string = my_string_init_c_string("Comrade");
	MY_STRING string1 = my_string_init_c_string("Geek");
	MY_STRING string2 = my_string_init_c_string("Geeks");
	
	printf("Comparing %s and %s: %d\n", "Apple", "Apple", my_string_compare(string1, string2));
	printf("Size of String is: %d \n Capacity of String is: %d\n", my_string_get_size(hMy_string), my_string_get_capacity(hMy_string));
	printf("%d", strcmp("Geek", "Geeks"));
	
	
	
	my_string_destroy(&hMy_string);
	my_string_destroy(&string1);
	my_string_destroy(&string2);
	//_CrtDumpMemoryLeaks();
	return 0;
}
