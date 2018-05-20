#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#define MAX_LEN 128

int h, n = 0, job, progress, choice;
char name[10];

int main()
{

	gamemenu();
	
	scanf("%d", &choice);
	
	if (choice == 1){
		test();
	}
	else if (choice == 4){
		gamemenu();
	}
	
}

void gamemenu()
{
	
	system("cls");
	img("menu.txt");
	
	printf("\n\n");
	printf("[1] Lanjutkan Cerita.\n");
//	
//	if(progress>=1){
//		printf("[2] Status.\n");
//		printf("[3] Hunter Rank.\n");
//	}
	
	printf("[4] Kembali ke Main Menu.\n");

}

int test(){
	printf("hai");
	getch();
	return main();
}

void speaking (char charname[10], char filename[20])
{
	
	system("cls");
	img(filename);
	printf("\n\n");
	printf("[%s]\n\n", charname);
}

void text (char text[128]) 	//fungsi scrolling text
{	
	int size;
	size = strlen(text);
	
	for(int x=0;x<size;x++)
    {   
        Sleep(30); 
        printf("%c",text[x]);
    }
    getch();
}

void text2 (char text[128], int speed) 	//customizable text with adjustable speed
{	
	int size;
	size = strlen(text);
	for(int x=0;x<size;x++)
    {   
        Sleep(speed); 
        printf("%c",text[x]);
    }
}

void speak (char text[128]) 	//fungsi scrolling text dialog
{	
	int size;
	size = strlen(text);
	printf("-- ");
	for(int x=0;x<size;x++)
    {   
        Sleep(30); 
        printf("%c",text[x]);
    }
	printf(" --\n");
    getch();
}

void img(char *filename)	//fungsi panggil print gambar
{				
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
 
    fclose(fptr);
 
    return 0;
}

void print_image(FILE *fptr)//fungsi print gambar
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
