#include "my_string.h"

MY_STRING my_string_init_default(void)
{
	String* pStr;
	pStr = (String*)malloc(sizeof(String));

	if (pStr != NULL) {
		pStr->size = 0;
		pStr->capacity = 7;
		pStr->data = (char*)malloc(pStr->capacity * sizeof(char));

		if (pStr->data == NULL) {
			free(pStr);
			pStr = NULL;
		}
	}
	return pStr;
}

void my_string_destroy(MY_STRING* phMy_string)
{
	String* myString = (String*)*phMy_string;
	free(myString->data);
	free(myString);

	myString = NULL;
}

MY_STRING my_string_init_c_string(const char* c_string)
{
	String* pStr;
	pStr = (String*)malloc(sizeof(String));
	int i;
	for (i = 0; c_string[i] != '\0'; i++);

	// check if pStr is NULL - malloc failed
	if (pStr != NULL) {
		// set capacity and size
		pStr->size = i;
		pStr->capacity = i + 1;
		pStr->data = (char*)malloc(sizeof(char) * pStr->capacity);
		if (pStr->data != NULL) {
			for (i = 0; c_string[i] != '\0'; i++) {
				pStr->data[i] = c_string[i];
			}
			pStr->data[i] = '\0';
		}
	}
	
	return pStr;
}

int my_string_get_capacity(MY_STRING hMy_string)
{
	String *pStr = hMy_string;
	return pStr->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
	String* pStr = hMy_string;
	return pStr->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
	String* leftString = (String*)hLeft_string;
	String* rightString = (String*)hRight_string;
	int result = 0;
	int i;
	// Check if both strings are empty
	if (leftString->data[0] == '\0' && rightString->data[0] == '\0') return result;

	//Check if left string is empty result = -1
	else if (leftString->data[0] == '\0') return -1;

	// Check if the right string is empty result = 1
	else if (rightString->data[0] == '\0') return 1;

	else {
		// Normal check
		for (i = 0; i < (leftString->data[i] != '\0') && i < (rightString->data[i] != '\0'); i++) {
			if (leftString->data[i] > rightString->data[i]) {
				result = 1;
				break;
			}
			else if (leftString->data[i] < rightString->data[i]){
				result = -1;
				break;
			}
		}
		if (leftString->data[i] == '\0' && rightString->data[i] == '\0') return 0;
		else if (rightString->data[i] == '\0') return 1;
		else return -1;
		
	}
		
	return result;
}
