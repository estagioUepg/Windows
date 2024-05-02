#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ' || *d == '\n') {
		//printf("r%s", d);
            ++d;
		//printf("%s", d);
        }
		//printf("a%s", d);
    } while (*s++ = *d++);
}


int main()
{

FILE* fptr;

fptr = fopen("filet.txt", "r");
if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }


char buffer [100];
char *token;
char buffip [100];
char buffTo [20]; 

while (fgets(buffip, sizeof(buffip), fptr) != NULL)
{
	token = strtok(buffip, ": ");
	token = strtok(NULL, ": ");
	token = strtok(NULL, ": ");
	token = strtok(NULL, ": ");
	snprintf(buffTo, sizeof(buffTo), token);
	remove_spaces(buffTo);
	snprintf(buffer, sizeof(buffer), "start cmd.exe /c psexec -h \\\\%s -c \"C:\\users\\deinfo\\ccl.bat\" -u <usuario> -p <senha>", buffTo);
	//puts(buffer);
	system(buffer);
}



return 0;
}
