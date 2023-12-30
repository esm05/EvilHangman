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
	hMy_string = my_string_init_default();
	//hMy_string = my_string_init_c_string("hi");
	
	
	my_string_destroy(&hMy_string);
	return 0;
}
