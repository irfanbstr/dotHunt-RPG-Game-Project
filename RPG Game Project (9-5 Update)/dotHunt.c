#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
 
int h, n = 0, job, progress;
char name[10];


int main(void)				//main function
{				

SetConsoleTitle("dotHunt by E&I");
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
	
//	battle("invader2.txt");
}

void speaking (char charname[10], char filename[20])	//fungsi memunculkan nama dan gambar untuk dialog
{
	system("cls");
	img(filename);
	printf("\n\n");
	for(int a = 0; a<100; a++){
		printf("=");
	}
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

void speak (char text[128]) 	//fungsi scrolling text untuk dialog
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

void startmenu()			//start menu
{ 
	system("cls");		//clear screen
    title();
    printf("[1] Mulai Permainan\t[2] Bantuan\t[3] Keluar\n");
	printf("Pilih Opsi: (1, 2, 3): ");
	scanf("%d", &h);
	
}

void helpmenu()				//help menu
{			
    
	system("cls");		//clear screen
    title();
    text2("\t\t--Bantuan--\n\n", 50);
    
    text(".Hunt adalah permainan Text-Based RPG. Gameplay terbagi dalam dua aspek: Narasi dan Pertarungan.\n");
	text("Cerita dalam game ini disampaikan dengan format seperti novel interaktif.\n");
	text("Mode pertarungan dalam game ini menyerupai permainan RPG tradisional.\n\n");
	text("Penjelasan mode pertarungan:\n[1] Serang : Serang Musuh.\n[2] Bertahan : Bertahan untuk mengurangi kekuatan serang musuh\n[3] Retas : Melakukan Hacking untuk mempengaruhi musuh.\n\n");
	text("Karakter anda dapat menjadi salah satu dari tiga kelas:\n[1] Hunter : Distribusi Stat Seimbang\n[2] Hijacker : Kemampuan Hacking lebih tinggi\n[3] Heavyarms : Kekuatan Fisik lebih tinggi\n\n");	
    
    text("Silakan nikmati permainan ini dan berikan tanggapan anda! (E&I).");
	printf("\n\n");
    system("pause");
    
    return main();
    
}

void gamemenu()
{
	
	system("cls");
	img("menu.txt");
	
	printf("\n\n");
	printf("[1] Lanjutkan Cerita.\n");
	
	if(progress>1){
		printf("[2] Status.\n");
		printf("[3] Hunter Rank.\n");
	}
	
	printf("[4] Kembali ke Main Menu.\n");

}

void newgame()				//jika n = 0, mulai new game
{				
	system("cls");
	text2("> Sistem dijalankan...\n\n", 50);
	getch();
	text2("> Sistem menyala. Menghubungkan anda dengan server...\n\n", 50);
	getch();
	text2("> Terhubung!\n\n", 30);
	system("pause");
	system("cls");
	img("nationnetwork.txt");
	
	text2("\n\n>> Silakan masukkan nama Anda: ",30);
	scanf("%s", name);
    printf("\n\n");
    
	text("> Mencarikan kode akses...\n");
	text("> username = 58003 password = **********\n\n");
	text("> Login start...\n\n");
	text("> Logged into System. \n\n");
	text2("\n> Selamat datang di NationNetwork, ",30);
	text2(name, 30);
	text2("!", 30);
	
    printf("\n\n");
    system("pause");
    
    disclaimer();
    system("cls");
    img("title.txt");
    text2("\t\tOleh E&I. 2018.\n\n",40);
	system("pause");
    
    prologue();

}

int quitgame()				//quit game
{				
	return -1;
}

void disclaimer()
{
	system("cls");
	text2("\t\t-- Disclaimer --\n\n",30);
	text2("Ini adalah karya fiksi.\nNama, karakter, tempat, dan kejadian adalah dari imajinasi penulis.\nKemiripan apapun kepada tokoh nyata, baik masih hidup maupun tidak, adalah kebetulan belaka.\n\n",30);
	system("pause");
}

void prologue2()
{
	
	speaking("", "invader.txt");
    speak("(D Town Square Game Arcade...)");
    speak("(Permainan Earth Invaders...)");

    speaking("A", "invader.txt");
    speak("Hey, sudah lama aku tak bermain permainan itu.");
    speak("Kamu bisa memainkannya kan? Main berdua dong! Haha.");
    
    speaking("A", "invader2.txt");
    speak("Tunggu sebentar...");
    speak("Alien ini terlihat aneh... Hah?!");
    speak("Itu tulisan WE yang tadi kita lihat! Sudah kutahu aku mempunyai firasat buruk soal ini.");
    speak("Coba lihat ke sekitar...");
    speak("Semua mesin permainan di tempat ini menunjukkan hal yang sama.");
    speak("Kita salah, yang tadi kita lihat bukanlah siaran. Ini Malware! Jaringan NationNetwork sudah terjangkit Malware.");
    speak("Semua mesin permainan di tempat ini menunjukkan hal yang sama.");

    speaking("A", "invader2.txt");
    speak("Tapi apa motif dibalik serangan malware ini? Untuk akuisisi data?");
    speak("Bukan, menurutku lebih dari itu.");
    speak("Aku akan coba tap jaringan komunikasi mesin permainan ini menggunakan laptopku.");
    speak("Tenang saja, IP ku berada di balik tujuh Proxy dan Firewall. Tidak semudah itu malware ini bisa masuk.");
    
    speaking("", "invader2.txt");
    speak("(A mulai mengetik dengan cepat...)");

    speaking("A", "invader2.txt");
    speak("T-Tidak mungkin... malware ini ganas sekali. Satu.. dua Firewall-ku sudah ditembus.");
    speak("Tapi sepertinya aku tahu apa yang diambil oleh Malware ini.");
    speak("Mereka mencuri identitasmu. Semua keterangan tentang dirimu, akun bank, alamat pribadi, semuanya...");
    speak("Aku tidak tahu apa yang akan teroris ini perbuat, tapi aku tidak suka ini.");    
    speak("Dan Malware ini bersifat dorman. Meskipun komputer sudah dimatikan, mereka sudah menginfeksi ROM-mu.");
    speak("Kemudian sialnya kita hidup di zaman dimana perangkat kita selalu terhubung internet dalam kondisi apapun.");

    speaking("A", "invader2.txt");
    speak("Sial. Aku sudah di Firewall-ku yang terakhir. Aku tidak cukup cepat untuk mengatasi mereka.");
    speak("Jika mereka mendapat informasiku... Ugh...");
    speak("SIAAALLLLLL!");

    printf("\n\n");
    system("pause");
    
    system("cls");
    
    text2("> SECURITY BREACH ONGOING...\n\n", 50);
    getch();
    text2("> LAUNCHING EMERGENCY PROGRAM...\n\n", 50);
    getch();
    text2("> CONNECTING TO HUNT NET...\n\n", 30);
    system("pause");
    system("cls");
    img("title.txt");
    
    text("\n\n> LAUNCHING HUNT.EXE. \n\n");
    text("> YOU HAVE ONE LAST CHANCE...\n");
    text2("\n> LET'S HUNT. \n\n",30);

    system("pause");
	
	battle("invader2.txt");
	
	speaking("A", "invader2.txt");
    speak("Sial. Aku sudah di Firewall-ku yang terakhir. Aku tidak cukup cepat untuk mengatasi mereka.");
    speak("Jika mereka mendapat informasiku... Ugh...");
    speak("SIAAALLLLLL!");

}

void prologue()
{
    
    system("cls");
    text2("\n\n\n\t\t\t-- Prologue: The Hunt --\n\n",30);
    text2("\t\t\t\t-- Day 1 --\n\n",30);
    system("pause");
    
    speaking("", "city.txt");
    speak("(M District Shopping Plaza...)");
    speak("(Pusat perbelanjaan Kota D... Tempat yang nampaknya selalu ramai oleh pengunjung.)");
    speak("(Kuliah sudah memasuki musim liburan. Kamu berjanjian dengan teman-teman untuk bertemu di sini...)");
    speak("(Kamu melihat seorang laki-laki temanmu.)\n");

    speaking("A", "city.txt");
    speak("Hey. Maaf terlambat. Pasti kamu sudah menunggu dari tadi.");
    speak("Tadi ada tugas liburan yang perlu diselesaikan secepatnya.");
    speak("Ngomong-ngomong, di mana yang lain?");

    speaking("", "city.txt");
    text("(Ponsel mu berbunyi, menandakan ada pesan masuk.)\n");
    text("('Nampaknya hari ini kami akan menyusul kalian nanti sore, D dan aku sedang sibuk dengan sesuatu.' -  C)\n");
    
    speaking("A", "city.txt");
    speak("Sepertinya baru kita saja sih ini.");
    speak("Ah, padahal aku mau mengajak kalian mencoba makanan yang ada di situ.");
    speak("Hmm, kenapa orang-orang semua berkumpul di depan layar itu ya?");

    speaking("A", "news.txt");
    speak("Ternyata berita NationNetwork... Tapi aneh. Apakah mereka mengalami gangguan siaran?");

    system("cls");
    img("news.txt");
    Sleep(1000);
    system("cls");
    img("we.txt");
    Sleep(1000);
    system("cls");
    img("news.txt");
    Sleep(1000);
    system("cls");
    img("we.txt");
    
    speaking("A", "we.txt");
    speak("Banyak glitch... sekarang menampilkan sesuatu... semacam tulisan.");
    speak("'WE'... 'Kami'?");
    speak("Ini bukan siaran NationNetwork. Ada seseorang yang meretas kedalam sistem layar ini.");
    
    speaking("Reporter", "we.txt");    
    speak("Dilaporkan telah terjadi sebuah peretasan sistem di jaringan NationNetwork.");
    speak("Pihak Kepolisian menyimpulkan bahwa telah terjadi serangan teroris siber.");
    speak("Serangan ini jauh berbeda dengan apa yang pernah terjadi sebelumnya.");
    speak("Pemerintah telah mengirim polisi siber, hacker, dan tim investigasi untuk permasalahan ini.");

    speaking("A", "we.txt");
    speak("Teroris siber...?");
    speak("Sulit dipercaya... Jaringan NationNetwork sangat terenkripsi dan aman...");
    speak("Gedung NationNetwork ada di kawasan paling terlindungi di negara ini, Blok 9. ");
    speak("Dan server mereka secara harafiah ada di bawah laut.");
    speak("Plus mereka punya Hacker terbaik di negara ini sebagai polisi siber mereka.");
    
    speaking("Reporter", "news.txt");
    speak("Pemerintah telah menyatakan sistem kembali normal.");
    speak("Disimpulkan bahwa telah terjadi retasan pada instruksi model lama.");
    speak("Semua lubang keamanan pada sistem sudah diperbaiki, berkat kerja baik tim elit N2.");
    
    speaking("A", "news.txt");
    speak("Secepat itukah bisa terselesaikan?");
    speak("Tim Hacker Elit N2 benar-benar sesuatu...");
    speak("Tapi peretasan jaringan Nation Network bukan hal yang mudah. ");
    speak("Siapapun yang dibalik hal ini, menurutku mereka bukan amatiran.");
    speak("Bagaimana menurutmu?");
    speak("Pikirkan. Jaringan NationNetwork melingkupi hampir segala media informasi di negara ini.");
    speak("Internet, Komunikasi seluler, pesawat TV, Media Sosial... ");
    speak("Semua perangkat Elektronik kita juga IoT yang terhubung dengan jaringan Nation Network.");
    speak("Mungkin saja hacker itu sedang meretas salah satu dari ponsel kita sekarang.");

    speaking("A", "news.txt");
    speak("Haaa... Memikirkan ini akan membuatmu panik. Semoga saja N2 sudah menyelesaikan masalah ini.");
    speak("C dan D akan datang sore ini kan? Bagaimana kalau kita jalan-jalan dulu sambil menunggu mereka?");
    speak("Mari pergi ke arcade game yang ada di D Town Square. Mungkin menunggu disana akan lebih menyenangkan.");

    speaking("", "news.txt");
    speak("(Merasa tidak ada yang lebih baik untuk dilakukan, kamu setuju untuk pergi ke arcade game.)");
    speak("(Kalian berdua meninggalkan area..)");

    Sleep(1000);
    system("cls");
    img("we.txt");
    Sleep(1000);
    printf("\n\n");
    system("pause");
    progress++;     

    gamemenu();
    
    int choice;
    scanf("%d", &choice);
	
	if (choice == 1){
		prologue2();
	}
	else if (choice == 4){
		return main();
	}
	

}

void chapter1()				//chapter 1
{			
	system("cls");
	
	text("Incoming Transmission...\n");
    printf("\n\n");
    system("pause");
    system("cls");
    
    img("operator.txt");
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
	img("operator.txt");
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

int battle(char enemy[20])
{
	system("cls");
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
int BitCredit;
int FireDmg = 5;
int IceDmg = 5;
int ThunderDmg = 5;
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
			printf("Musuh masih terkena efek Burn\n\n");
		}
		
		if (frost>0){
			DmgToPlayer += frost;	
		}
		
		int random = rand();
		int DmgToPlayer = 10;
		DmgBlock = 0;
		
		printf ("\t Battle Now!\t\t\t Player HP: %d Enemy HP: %d\n\n",PlayerHealth,EnemyHealth);
		img(enemy);
		
		printf("\n\n\tSelect Action: \n[1]Attack\n[2]Block\n[3]Hack\n\n");
		printf("Action: ");
		scanf("%d",&Choice1);
		
		if(Choice1==1)
		{//the player choose to attack
			EnemyHealth = EnemyHealth - DmgToEnemy;
			DmgBlock = 0;
		}
		
		else if(Choice1==2)
		{//the player choose to Block
			DmgBlock +=  5;
			DmgToPlayer = DmgToPlayer - DmgBlock - random % 5;
			
		}
		else if(Choice1==3)
		{//the player choose to 
			printf("Skill list\n[1]Fire()\n[2]Ice()\n[3]Thunder()\n\nChoose skill: ");
			//The PLAYER then choose which skill to activate
			scanf("%d",&Choice2);
			
			if(Choice2==1)
				{//the player choose fire
				printf("%s menyerang dengan Fire()\n musuh terkena %d Damage", name, FireDmg);
				EnemyHealth -= FireDmg;			
				x = random % 2;

				if (x==0){
					printf("Musuh terkena efek Burn\n");
					burn += 3;
					EnemyHealth -= burn *4/3;
				}	
			
				else {
				printf("Musuh tidak terkena efek Burn");
				}
		
			}	
			else if(Choice2==2)
				{//the player chose ice
				printf("%s attacked with Ice()\n Musuh terkena %d Damage", name, IceDmg);
				EnemyHealth -= IceDmg;			
				x = random % 2;	
	
				if (x==0)
				{
					printf("Musuh terkena efek Frost");
					frost += 2;
					DmgToPlayer -= frost *5/4;
				}
			
				else 
				{
					printf("Musuh tidak terkena efek frost");
				}
	
				}
			
				else if(Choice2==3)
				{//the player choose thunder
					printf("%s menyerang dengan Thunder().\n the enemy recieve %d Damage", name, ThunderDmg);
					EnemyHealth -= ThunderDmg;	
					x = random % 2;
	
				if (x==0)
				{
					printf("Musuh terkena efek Shock.\n");
					shock += 1;
					DmgToPlayer = 0;
				}
				else 
				{
					printf("Musuh tidak terkena efek Shock.\n");
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
		printf("You Win");
	}
	else if (PlayerHealth==0){
		
		printf("Game Over");
	}
}

void title()				//header title
{
	printf("========================================================\n");
	img("title.txt");
 	
 	printf("\t\t   by E&I. 2018\n");
    printf("========================================================\n\n");
 	
    return 0;
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
    char read_string[128];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}

