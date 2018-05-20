
void text (char myText[MAX_LEN]) 	//fungsi scrolling text biasa dengan getch()
{	
	int size; 					//deklarasi variabel size
	size = strlen(myText);		// nilai size = panjang teks
	for(int x=0;x<size;x++)		//for loop untuk memprint teks dengan delay 10ms
    {   
        Sleep(10); 				//delay
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
        Sleep(speed); 			//variabel kecepatan bisa diatur dengan pemanggilan metode.
        printf("%c",myText[x]);
    }
}

void ColorText(char myText[MAX_LEN], int color)	//fungsi menampilkan teks berwarna. 'RED' 'GREEN' 'CYAN'
{
	switch(color)
	{
		case 'RED':
		printf("\033[1;31m");		//ansi code untuk warna merah
		printf("%s", myText);
		printf("\033[0m");			//kembali ke putih
		break;
		
		case 'GREEN':
		printf("\033[1;32m");		//ansi code untuk warna hijau
		printf("%s", myText);
		printf("\033[0m");			//kembali ke putih
		break;
		
		case 'CYAN':
		printf("\033[1;36m");		//ansi code untuk warna cyan
		printf("%s", myText);
		printf("\033[0m");			//kembali ke putih
	}
  	
}

void speaking (char charname[10], char filename[20])	//fungsi memunculkan nama dan gambar untuk dialog
{
	system("cls");
	IMG(filename);					//munculkan gambar latar
	printf("\n\n");
	for(int a = 0; a<100; a++){		//border latar dengan dialog
		printf("=");
	}
	printf("\n\n");
	printf("[%s]\n\n", charname);	//nama karakter yang berbicara
}

void speak (char myText[MAX_LEN]) 	//fungsi scrolling text untuk dialog
{	
	int size;
	size = strlen(myText);			//sama dengan text(), namun dengan border -- pada kiri dan kanan
	printf("-- ");
	for(int x=0;x<size;x++)
    {   
        Sleep(10); 
        printf("%c",myText[x]);
    }
	printf(" --\n");
    getch();
}

