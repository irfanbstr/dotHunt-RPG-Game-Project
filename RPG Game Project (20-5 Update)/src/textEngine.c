#include "textEngine.h"
#include "gfxEngine.h"


#define MAX_LEN

void speaking (char charname[10], char filename[20])	//fungsi memunculkan nama dan gambar untuk dialog
{
	system("cls");
	IMG(filename);
	printf("\n\n");
	for(int a = 0; a<100; a++){
		printf("=");
	}
	printf("\n\n");
	printf("[%s]\n\n", charname);
}

void speak (char myText[MAX_LEN]) 	//fungsi scrolling text untuk dialog
{	
	int size;
	size = strlen(myText);
	printf("-- ");
	for(int x=0;x<size;x++)
    {   
        Sleep(10); 
        printf("%c",myText[x]);
    }
	printf(" --\n");
    getch();
}

