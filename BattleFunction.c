#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

int battle(char enemy[20]){
	printf("Commencing Battle.\n");
	getch();
	system("cls");
	printf("Let's Hunt.\n");
	getch();
	
	system("cls");

int PlayerHealth = 150;
int EnemyHealth = 100;
int Choice1,Choice2,Choice3;
int DmgToEnemy = 10;
int DmgBlock=0;
int FireDmg = 5;
int IceDmg = 5;
int ThunderDmg = 5;
int Malware;
srand(time(NULL));

int i;
int x;
int y;
int z;
int burn = 0;
int frost= 0;
int shock = 0;
int DmgToPlayer;
	do{
		if (burn>0){
			DmgToEnemy += burn;
			burn -= 1;
			printf("Musuh masih terkena efek burn\n\n");
		}
		if (frost>0){
			DmgToPlayer += frost;
			
		}
		
		int random = rand();
		int DmgToPlayer = 10;
		DmgBlock = 0;
		system("cls");
		printf ("\t Battle Now!\t\t\t Player HP: %d  Player MP:%d Enemy HP: %d Enemy MP:%d \n\n",PlayerHealth,PMP,EnemyHealth,EMP);
		img(enemy);
		printf("\n\n\tSelect Action: \n[1]Attack\n[2]Block\n");
		printf("[3]Skill\n[4]Hack\n");
		printf("Action: ");
		scanf("%d",&Choice1);
		if(Choice1==1){//the player choose to attack
			EnemyHealth = EnemyHealth - DmgToEnemy;
				DmgBlock = 0;
		}
		else if(Choice1==2){//the player choose to Block
		DmgBlock +=  5;
			DmgToPlayer = DmgToPlayer - DmgBlock - random % 5;
			
			
		}
		else if(Choice1==3){//the player choose to 
			printf("Skill list\n[1]Fire\n[2]Ice\n[3]Thunder\nChoose skill: ");
			//The PLAYER then choose which skill to activate
			scanf("%d",&Choice2);
			
			
			if(Choice2==1){//the player choose fireeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
				printf("the player menyerang dengan fire\n musuh terkena %d Damage", FireDmg);
				EnemyHealth -= FireDmg;
///////////////////////////////////////////////////////////////////					
	x = random % 2;
	
	printf("\n%d\n",x);
	
	if (x==0){
		printf("musuh terkenea efek burn");
		burn += 3;
		EnemyHealth -= burn *4/3;
	}
	else {
		printf("musuh tidak terkena efek burn");
	}
	
				
			}
			else if(Choice2==2){//the player chose ice
			printf("the player attack with ice\n the enemy recieve %d Damage", IceDmg);
				EnemyHealth -= IceDmg;
				
			
	/////////////////////////////////////////////////////////////////////////////////			
	x = random % 2;
	
	printf("%d\n",x);
	
	if (x==0){
		printf("musuh terkenea efek Frost");
		frost += 2;
		DmgToPlayer -= frost *5/4;
	}
	else {
		printf("musuh tidak terkena efek frost");
	}
	
			}
			else if(Choice2==3){//the player choose thunder
				printf("the player attack with fire\n the enemy recieve %d Damage", ThunderDmg);
				EnemyHealth -= ThunderDmg;
					
	x = random % 2;
	
	printf("%d\n",x);
	
	if (x==0){
		printf("musuh terkenea efek Shock");
		shock += 1;
		DmgToPlayer = 0;
	}
	else {
		printf("musuh tidak terkena efek shock");//shoccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccck
	}
	
	
			}
			
			
		}
		
		
		printf("\n Enemy is attacking");
		PlayerHealth = PlayerHealth - DmgToPlayer;
		printf("\n Round over \n");
		system("pause");
		system("cls");
	
	}
	while(PlayerHealth>0 && EnemyHealth>0);
	
	if (EnemyHealth<=0){
		printf("YouWin");
	}
	else if (PlayerHealth==0){
		
		printf("Game Over");
	}
}

int main(){
	printf("Commencing Battle.\n");
	getch();
	system("cls");
	printf("Let's Hunt.\n");
	getch();
	
	system("cls");
int PlayerHealth = 100;
int EnemyHealth = 100;
int Choice1,Choice2,Choice3;
int DmgToEnemy = 10;
int DmgBlock=0;
int BitCredit;
int FireDmg = 5;
int IceDmg = 5;
int ThunderDmg = 5;
int PMP = 100;
int EMP = 100;
int Malware;
srand(time(NULL));

int i;
int x;
int y;
int z;
int burn = 0;
int frost= 0;
int shock = 0;
int DmgToPlayer;
	do{
		if (burn>0){
			DmgToEnemy += burn;
			burn -= 1;
			printf("Musuh masih terkena efek burn\n\n"
			);
		}
		if (frost>0){
			DmgToPlayer += frost;
			
		}
		
		int random = rand();
		int DmgToPlayer = 10;
		DmgBlock = 0;
		printf ("\t Battle Now!\t\t\t Player HP: %d  Player MP:%d Enemy HP: %d Enemy MP:%d \n\tSelect Action: \n[1]Attack\n[2]Block\n",PlayerHealth,PMP,EnemyHealth,EMP);
		printf("[3]Skill\n[4]Hack\n");
		printf("Action: ");
		scanf("%d",&Choice1);
		if(Choice1==1){//the player choose to attack
			EnemyHealth = EnemyHealth - DmgToEnemy;
				DmgBlock = 0;
		}
		else if(Choice1==2){//the player choose to Block
		DmgBlock +=  5;
			DmgToPlayer = DmgToPlayer - DmgBlock - random % 5;
			
			
		}
		else if(Choice1==3){//the player choose to 
			printf("Skill list\n[1]Fire\n[2]Ice\n[3]Thunder\nChoose skill: ");
			//The PLAYER then choose which skill to activate
			scanf("%d",&Choice2);
			
			
			if(Choice2==1){//the player choose fireeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
				printf("the player menyerang dengan fire\n musuh terkena %d Damage", FireDmg);
				EnemyHealth -= FireDmg;
///////////////////////////////////////////////////////////////////					
	x = random % 2;
	
	printf("\n%d\n",x);
	
	if (x==0){
		printf("musuh terkenea efek burn");
		burn += 3;
		EnemyHealth -= burn *4/3;
	}
	else {
		printf("musuh tidak terkena efek burn");
	}
	
				
			}
			else if(Choice2==2){//the player chose ice
			printf("the player attack with ice\n the enemy recieve %d Damage", IceDmg);
				EnemyHealth -= IceDmg;
				
			
	/////////////////////////////////////////////////////////////////////////////////			
	x = random % 2;
	
	printf("%d\n",x);
	
	if (x==0){
		printf("musuh terkenea efek Frost");
		frost += 2;
		DmgToPlayer -= frost *5/4;
	}
	else {
		printf("musuh tidak terkena efek frost");
	}
	
			}
			else if(Choice2==3){//the player choose thunder
				printf("the player attack with fire\n the enemy recieve %d Damage", ThunderDmg);
				EnemyHealth -= ThunderDmg;
					
	x = random % 2;
	
	printf("%d\n",x);
	
	if (x==0){
		printf("musuh terkenea efek Shock");
		shock += 1;
		DmgToPlayer = 0;
	}
	else {
		printf("musuh tidak terkena efek shock");//shoccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccck
	}
	
	
			}
			
			
		}
		
		
		printf("\n Enemy is attacking");
		PlayerHealth = PlayerHealth - DmgToPlayer;
		printf("\n Round over \n");
		system("pause");
		system("cls");
	
	}
	while(PlayerHealth>0 && EnemyHealth>0);
	
	if (EnemyHealth<=0){
		printf("YouWin");
	}
	else if (PlayerHealth==0){
		
		printf("Game Over");
	}
}
