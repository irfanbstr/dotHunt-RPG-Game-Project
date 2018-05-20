int choiceH=1, choiceV=1, code=-1, key=-1;  //Kontroler Axis-H dan Axis-V Keyboard. Lihat Controls() 
int optionA = 0, optionB = 0;				//Pengontrol opsi dialog (maksimal 2 opsi). Lihat Choice()

void Controls(int cNumVert, int cNumHorz)		//Kontroler Axis-H dan Axis-V Keyboard, masukkan maksimum vertikal dan horizontal
{
    code = getch();
    if (code == 0 || code == 224)
       key = getch(); 
       
    else if(code == 13)
    	key = code;
	    
//    printf("%d %d\n", code, key);
    
    switch(key){
    	
	case 75:
//		printf("LEFT\n\n");
		
		if(choiceH > 1)
		choiceH--;
		
		else if(choiceH == 1)
		choiceH = cNumHorz;
		
		break;	
			
	case 80:
//		printf("DOWN\n\n");
		
		if(choiceV < cNumVert)
		choiceV++;
		
		else if(choiceV == cNumVert)
		choiceV = 1;
		
		break;
			
	case 72:
//		printf("UP\n\n");
		
		if(choiceV > 1)
		choiceV--;	
		
		else if(choiceV == 1)
		choiceV = cNumVert;
		
		break;
	
	case 77:
//		printf("RIGHT\n\n");
		
		if(choiceH < cNumHorz)
		choiceH++;
		
		else if(choiceH == cNumHorz)
		choiceH = 1;
		
		
		break;
		
	case 13:
//		printf("ENTER\n\n");
		break;
		
	
//	printf("%d, %d\n\n", choiceH, choiceV);
	
	}
}

void ResetControls()		//Reset Kontroler. Taruh sebelum ada pilihan ganda
{
	choiceH=1; choiceV=1; code=-1; key=-1;
}

void ChoiceDialog(char charname[20], char filename[20], char prevText[MAX_LEN], char choice1[MAX_LEN], char choice2[MAX_LEN]) 
//berisi pilihan dialog
{
	optionA = 0; 
	optionB = 0;
	ResetControls(); //init
	
	while(1){
		
		switch (choiceV){
			
		case 1:
		speaking(charname, filename);
		printf(prevText);
		printf("\n\n");
		printf(">>> %s\n", choice1);
		printf(" %s\n", choice2);
		break;
		
		case 2:
		speaking(charname, filename);
		printf(prevText);
		printf("\n\n");
		printf(" %s\n", choice1);
		printf(">>> %s\n", choice2);
		break;
	}
		
		Controls(2,0); //berikan kontrol 2 vertikal
		
		if (choiceV == 1 && key == 13){ //jika tekan enter, pilih choice 2
			optionA=1;
			break;
		}
		
		else if (choiceV == 2 && key == 13){ //jika tekan enter, pilih choice 2
			optionB=1;	
			break;
		}
	}
}

void Choice(char prevText[MAX_LEN], char choice1[MAX_LEN], char choice2[MAX_LEN]) 
//berisi pilihan diluar dialog
{
	optionA = 0; 
	optionB = 0;
	ResetControls();  //init
	
	while(1){
		
		switch (choiceV){
			
		case 1:
		system("cls");
		printf(prevText);
		printf("\n\n");
		printf(">>> %s\n", choice1);
		printf(" %s\n", choice2);
		break;
		
		case 2:
		system("cls");
		printf(prevText);
		printf("\n\n");
		printf(" %s\n", choice1);
		printf(">>> %s\n", choice2);
		break;
	}
		
		Controls(2,0); //berikan kontrol 2 vertikal
		
		if (choiceV == 1 && key == 13){  //jika tekan enter, pilih choice 1
			optionA=1;
			break;
		}
		
		else if (choiceV == 2 && key == 13){ //jika tekan enter, pilih choice 2
			optionB=1;	
			break;
		}
	}
}
