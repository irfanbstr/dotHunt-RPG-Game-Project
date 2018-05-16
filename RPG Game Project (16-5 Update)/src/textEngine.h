
void text (char myText[MAX_LEN]) 	//fungsi scrolling text biasa dengan getch()
{	
	int size;
	size = strlen(myText);
	for(int x=0;x<size;x++)
    {   
        Sleep(10); 
        printf("%c",myText[x]);
    }
    getch();
}

void text2 (char myText[MAX_LEN], int speed) 	//fungsi scrolling text tanpa getch() dan dengan variabel kecepatan
{	
	int size;
	size = strlen(myText);
	for(int x=0;x<size;x++)
    {   
        Sleep(speed); 
        printf("%c",myText[x]);
    }
}

void ColorText(char myText[MAX_LEN], int color)	//fungsi menampilkan teks berwarna. 'RED' 'GREEN' 'CYAN'
{
	switch(color)
	{
		case 'RED':
		printf("\033[1;31m");
		printf("%s", myText);
		printf("\033[0m");
		break;
		
		case 'GREEN':
		printf("\033[1;32m");
		printf("%s", myText);
		printf("\033[0m");
		break;
		
		case 'CYAN':
		printf("\033[1;36m");
		printf("%s", myText);
		printf("\033[0m");
	}
  	
}

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

