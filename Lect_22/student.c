#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct studentStruct{
	char *NAME;
	int UIN;
	float GPA;
}student;

int main(){
	student *student_records = (student *)malloc(200*sizeof(student));
	if(student_records == NULL)
		return 0;
	int i;
	for(i=0;i<200;i++){
		student_records[i].NAME = (char *)calloc(100, sizeof(char));
		/* check for calloc not shown for simplicity */
		strncpy(student_records[i].NAME, "To be set", 100);
		(student_records+i)->UIN = -1;
		(student_records+i)->GPA = 0.0;
	}
	printf("student_records pointer %p\n",student_records);
	
	student *new_records = realloc(student_records, 400*sizeof(student));
	if(new_records == NULL){
		for(i=0;i<200;i++){
			free((student_records+i)->NAME);
		}	
		free(student_records);
		return 0;
	}

	for(i=200;i<400;i++){
                (new_records+i)->NAME = (char *)calloc(100, sizeof(char));
		/* check for calloc not shown for simplicity */
                strncpy((new_records+i)->NAME, "To be set", 100);
                (new_records+i)->UIN = -1;
                (new_records+i)->GPA = 0.0;
        }
	printf("new_records pointer %p\n", new_records);
	
	for(i=0;i<400;i++){
                free((new_records+i)->NAME);
        }

	free(new_records);

	return 0;
}
