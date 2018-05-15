#include<stdio.h>
#include<string>

int main(){
	
int PlayerHealth = 100;
int EnemyHealth = 100;
int Choice1; 
int DmgToPlayer = 10;
int DmgToEnemy = 10;
int DmgBlock = 5;


	do{
//		printf ("                                                ,w.\n");
//		printf ("                                              ,YWMMw  ,M  ,\n");
//		printf ("                         _.---.._   __..---._.'MMMMMw,wMWmW,\n");
//		printf ("                    _.-""        ;;           YP;WMMMMMMMMMb,\n");
//		printf ("                 .-' __.'                   .'     MMMMW^WMMMM;\n");
//		printf ("     _,        .'.-'; `,       /`     .--""      :MMM[==MWMW^;\n");
//		printf ("  ,mM^;     ,-;;;   /   ;      ;      /   ,       MMMMb_wMW;  @\;n");
//		printf (" ,MM:.    .'.-'   .'     ;     `\    ;     `,     MMMMMMMW `;=./`-,\n");
//		printf (" WMMm__,-'.'     /      _.\      F"";-+,,   ;_,_.dMMMMMMMM[,_ / `=_}");
//		printf ("  ;^MP__.-'    ,-' _.--;;   `-,   ;       \  ; ;MMMMMMMMMMW^``; __|\n");
//		printf ("  ,mM^;     ,-;;;   /   ;      ;      /   ,       MMMMb_wMW;  @\\n");
//		printf ("            /   .'            ; ;         )  )`{  \ `;^W^`,   \  :\n");
//		printf ("           /  .'             /  (       .'  /     Ww._     `.  `;\n");
//		printf ("          /  Y,              `,  `-,=,_{   ;      MMMP`""-,  `-._.-,\n");
//		printf ("         (--, )                `,_ / `) \/"")      ^;      ;-, -;l\:\n");
//		printf ("          `"";                    `;;;   `;'                  `--- \n");
//		printf ("\n\t\t\tEnemy: Cyber Lion Beast\n\n");
//		
//		
//		
		printf ("Battle Now!\t\t\t Player HP: %d  Enemy HP: %d \nSelect Action: \n\n[1]Attack\n[2]Block\n\n",PlayerHealth,EnemyHealth);
		printf("Action: ");
		scanf("%d",&Choice1);
		if(Choice1==1){
			EnemyHealth = EnemyHealth - DmgToEnemy;
		}
		else if(Choice1==2){
			DmgToPlayer = DmgToPlayer - DmgBlock;
			
		}
		printf("\n Enemy is attacking");
		PlayerHealth = PlayerHealth - DmgToPlayer;
		printf("\n Round over \n");
		system("pause");
		system("cls");
		
	}
	while(PlayerHealth>0 && EnemyHealth>0);
	
	if (PlayerHealth==0){
		printf("Game Over!");
	}
	else if (EnemyHealth==0){
		printf("You Win!");
	}
}
