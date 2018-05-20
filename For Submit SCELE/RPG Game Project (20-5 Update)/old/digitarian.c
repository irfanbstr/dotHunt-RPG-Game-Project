#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#define MAX_LEN 128
 
int h, n = 0, job;
char name[10];

void text (char text[128]) 	//fungsi scrolling text
{	
	int size;
	size = strlen(text);
	for(int x=0;x<size;x++)
    {   
        Sleep(20); 
        printf("%c",text[x]);
    }
    getch();
}

int main(void)				//main function
{				
	startmenu();
	
	if(h == 1){
		if (n == 1){
		}
		else{
		newgame();
	}
	}
	else if(h == 2){
		helpmenu();
	}
	else if(h == 3){
		return 0;
	}
	else {
		printf("INVALID INPUT!");
		getch();
		return main();
	}
}

void startmenu()			//start menu
{ 
	system("cls");		//clear screen
    title();
    printf("[1] Start\t[2] Help\t[3] Exit\n");
	printf("Choose Option: (1, 2, 3): ");
	scanf("%d", &h);
	
}

void helpmenu()				//help menu
{			
    
	system("cls");		//clear screen
    title();
    printf("\t\tHELP\n\n");
    
    text("This is a Text-Based RPG Game. Gameplay is divided into two parts: Story and Battle.\n");
	text("In Story mode you will enjoy the story through novel-like experience.\n");
	text("In Battle mode, you will be fighting against monsters in a traditional RPG gameplay.\n\n");
	text("Battle mode Guide:\n[1] Attack : Attack the enemy\n[2] Block : Block to reduce damage\n");
	
    printf("\n\n");
    system("pause");
    
    return main();
    
}

void newgame()				//jika n = 0, mulai new game
{				
	system("cls");
	text("System starting...\n\n");
	printf("Please Enter Your Name:\n");
	scanf("%s", name);
    printf("\n\n");
    
	text("Getting your access code ready...\n");
	text("username = 58003 password = **********\n\n");
	text("Login start...\n\n");
	text("Logged into System. \n\n");
	printf("Welcome to Digitarian, %s.", name);
    printf("\n\n");
    system("pause");
    
    chapter1();

}

int quitgame()				//quit game
{				
	return -1;
}

void chapter1()				//chapter 1
{			
	system("cls");
	
	text("Incoming Transmission...\n");
    printf("\n\n");
    system("pause");
    system("cls");
    
    laura();
    printf("\n");
    	
	text("-- I see that you are here. Let's begin the briefing. -- \n");
	text("-- My Name is Laura. I will be the operator for your mission. --\n");
	text("-- Unit 58, Personnel ID. Number 3... ");
	printf("%s was it? --\n", name);
	getch();
	
	text("-- You are assigned to a green unit. --\n");
	text("-- We will ask of you to mostly stick to reconnaissance and spotting for us. --\n");
	text("-- Now, what class exactly did you register yourself as? --\n");
    
    printf("\n");
    printf("[1] Hunter\n[2] Hijacker\n[3] Heavyarms\n");
	scanf("%d", &job);
	
	system("cls");
	laura();
    printf("\n");
    
	text("-- Ah, very good. -- \n");
	text("-- The details of your mission is as following: -- \n\n");
	text("-- 1. You will lead the infiltration of the garrison on the east of B sector. -- \n");
	
	if(job == 1){
		text("-- 2. As a Hunter you can use a wide variety of skills to your disposal. --\n");
		text("-- Formulize and use a steady tactic to defeat your enemies. --\n");
	}
		
	else if(job == 2){
		text("-- 2. As a Hijacker you can utilize hacks more effectively than others. --\n");
		text("-- Use your enemies to defeat them in their own game.--\n");
	}
	
	else if(job == 3){
		text("-- 2. As a Heavyarms specialist you have access to greater firepower. --\n");
		text("-- Storm your enemies and wipe them out quickly.--\n");
	}
    
    
}

void title()				//header title
{
	printf("========================================================\n");
	char *filename = "title.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
 
    fclose(fptr);
 	
 	printf("\t\t   by E&I. 2018\n");
    printf("========================================================\n\n");
 	
    return 0;
}

void laura()				//character file for laura
{				
	char *filename = "operator.txt";
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
