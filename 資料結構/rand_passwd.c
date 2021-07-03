#include <stdlib.h>
#include <stdio.h>

#define STUDENT_ID		0xB0829011

#define DIGIT_LEN		4
#define NUM_BUTTONS		4

int main ()
{
	int i;
	int key;

	printf ("The password for you: ");

	srand (STUDENT_ID);
	for (i=0; i<NUM_BUTTONS; i++) {
		key = rand() % NUM_BUTTONS;
		printf ("%d ", key);
	}//end for i

	printf ("\n");
	return 0;
}




