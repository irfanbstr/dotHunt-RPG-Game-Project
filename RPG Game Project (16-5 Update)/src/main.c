

//dotHUNT//
//TEXT BASED RPG DALAM C OLEH E&I
//IRFAN BUDI SATRIA (GAME MECHANIC AND STORY) DAN EDGAR DIMAS ISAADRAZAK (BATTLE SYSTEM)
//TEKNIK ELEKTRO UNIVERSITAS INDONESIA

//DIBUAT UNTUK MEMENUHI NILAI PROYEK AKHIR MATA KULIAH DASAR KOMPUTER
//DAN JUGA UNTUK ISENG ISENG BERFAEDAH


//CODE:
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#define MAX_LEN 128

#include "textEngine.h"
#include "gfxEngine.h"

int choiceH=1, choiceV=1, code=-1, key=-1;  //Kontroler Axis-H dan Axis-V Keyboard. Lihat Controls() 
int optionA = 0, optionB = 0;				//Pengontrol opsi dialog (maksimal 2 opsi). Lihat Choice()
int job, progress; 							//Variabel permanen
char name[10] = "IRF";						//Nama karakter


int main(void)				//main function
{				
	SetConsoleTitle("dotHunt by E&I");
	StartMenu();
}

int Title()					//header Title
{
	system("cls");
	printf("==================================================================\n");
	IMG("title");
 	printf("\t\t       -- by E&I. 2018 --\n");
    printf("==================================================================\n\n");
 	
    return 0;
}

int StartMenu()				//start menu
{ 
    Title();
    ColorText("\n\t  \t\t-- PRESS ENTER --\n\n", 'GREEN');
    
    int start = 0;
    
    while(start != 1){

		key = getch();
    	switch(key){
    		case 13:
    			start = 1;
    			break;
    		
    		default:
    			start = 0;
    			break;
    		}
	}
	
	ResetControls();
	while(1){
	
	switch (choiceV){
		case 1:
		Title();
		printf(">>> New Game\n");
		ColorText(" Mulai Permainan Baru\n\n", 'GREEN');
		printf(" Load Game\n");
		ColorText(" Lanjutkan Permainan\n\n", 'GREEN');
		printf(" Help\n");
		ColorText(" Menu Bantuan\n\n", 'GREEN');
		printf(" Exit\n");
		ColorText(" Keluar Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 2:
		Title();
		printf(" New Game\n");
		ColorText(" Mulai Permainan Baru\n\n", 'GREEN');
		printf(">>> Load Game\n");
		ColorText(" Lanjutkan Permainan\n\n", 'GREEN');
		printf(" Help\n");
		ColorText(" Menu Bantuan\n\n", 'GREEN');
		printf(" Exit\n");
		ColorText(" Keluar Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 3:
		Title();
		printf(" New Game\n");
		ColorText(" Mulai Permainan Baru\n\n", 'GREEN');
		printf(" Load Game\n");
		ColorText(" Lanjutkan Permainan\n\n", 'GREEN');
		printf(">>> Help\n");
		ColorText(" Menu Bantuan\n\n", 'GREEN');
		printf(" Exit\n");
		ColorText(" Keluar Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 4:
		Title();
		printf(" New Game\n");
		ColorText(" Mulai Permainan Baru\n\n", 'GREEN');
		printf(" Load Game\n");
		ColorText(" Lanjutkan Permainan\n\n", 'GREEN');
		printf(" Help\n");
		ColorText(" Menu Bantuan\n\n", 'GREEN');
		printf(">>> Exit\n");
		ColorText(" Keluar Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		}
		
		Controls(4, 0);
		
		if (choiceV == 1 && key == 13){
//			printf("NEWGAME!!");
			NewGame();
			break;
		}
		
		else if (choiceV == 2 && key == 13){
//			printf("LOAD!!");
			LoadGame();		
			break;
		}
		
		else if (choiceV == 3 && key == 13){
//			printf("HELP!!");
			HelpMenu();
			break;
		}
		
		else if (choiceV == 4 && key == 13){
//			printf("EXIT!!");
			QuitGame();
			break;
		}
		
	}
}
	
int HelpMenu()				//help menu
{			
    Title();
    text2("\t\t\t  --Bantuan--\n\n", 20);
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

int GameMenu()				//Hunt NET Menu
{
	ResetControls();
	
	while(1){
	switch (choiceV){
		case 1:
		system("cls");
		IMG("menu");
		printf("Selamat datang Hunter %s!\t||", name);
		printf("\tHunter Rank anda adalah %d\n\n", progress);
		printf(" Misi Terbaru anda adalah: ");
		Mission(1);
		printf("==============================================================\n\n");
		printf(">>> Lanjutkan Cerita.\n");
		ColorText(" Lanjutkan Cerita\n\n", 'GREEN');
		printf(" Hunter Status\n");
		ColorText(" Cek Status Hunter-mu.\n\n", 'GREEN');
		printf(" Malware List\n");
		ColorText(" Penjelasan Tentang Tiap Malware\n\n", 'GREEN');
		printf(" Save\n");
		ColorText(" Simpan Permainan\n\n", 'GREEN');
		printf(" Log Off\n");
		ColorText(" Keluar dari Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 2:
		system("cls");
		IMG("menu");
		printf("Selamat datang Hunter %s!\t||", name);
		printf("\tHunter Rank anda adalah %d\n\n", progress);
		printf(" Misi Terbaru anda adalah: ");
		Mission(1);
		printf("==============================================================\n\n");
		printf("Lanjutkan Cerita.\n");
		ColorText(" Lanjutkan Cerita\n\n", 'GREEN');
		printf(">>> Hunter Status\n");
		ColorText(" Cek Status Hunter-mu.\n\n", 'GREEN');
		printf(" Malware List\n");
		ColorText(" Penjelasan Tentang Tiap Malware\n\n", 'GREEN');
		printf(" Save\n");
		ColorText(" Simpan Permainan\n\n", 'GREEN');
		printf(" Log Off\n");
		ColorText(" Keluar dari Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 3:
		system("cls");
		IMG("menu");
		printf("Selamat datang Hunter %s!\t||", name);
		printf("\tHunter Rank anda adalah %d\n\n", progress);
		printf(" Misi Terbaru anda adalah: ");
		Mission(1);
		printf("==============================================================\n\n");
		printf(" Lanjutkan Cerita.\n");
		ColorText(" Lanjutkan Cerita\n\n", 'GREEN');
		printf(" Hunter Status\n");
		ColorText(" Cek Status Hunter-mu.\n\n", 'GREEN');
		printf(">>> Malware List\n");
		ColorText(" Penjelasan Tentang Tiap Malware\n\n", 'GREEN');
		printf(" Save\n");
		ColorText(" Simpan Permainan\n\n", 'GREEN');
		printf(" Log Off\n");
		ColorText(" Keluar dari Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 4:
		system("cls");
		IMG("menu");
		printf("Selamat datang Hunter %s!\t||", name);
		printf("\tHunter Rank anda adalah %d\n\n", progress);
		printf(" Misi Terbaru anda adalah: ");
		Mission(1);
		printf("==============================================================\n\n");
		printf(" Lanjutkan Cerita.\n");
		ColorText(" Lanjutkan Cerita\n\n", 'GREEN');
		printf(" Hunter Status\n");
		ColorText(" Cek Status Hunter-mu.\n\n", 'GREEN');
		printf(" Malware List\n");
		ColorText(" Penjelasan Tentang Tiap Malware\n\n", 'GREEN');
		printf(">>> Save\n");
		ColorText(" Simpan Permainan\n\n", 'GREEN');
		printf(" Log Off\n");
		ColorText(" Keluar dari Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		
		case 5:
		system("cls");
		IMG("menu");
		printf("Selamat datang Hunter %s!\t||", name);
		printf("\tHunter Rank anda adalah %d\n\n", progress);
		printf(" Misi Terbaru anda adalah: ");
		Mission(1);
		printf("==============================================================\n\n");
		printf(" Lanjutkan Cerita.\n");
		ColorText(" Lanjutkan Cerita\n\n", 'GREEN');
		printf(" Hunter Status\n");
		ColorText(" Cek Status Hunter-mu.\n\n", 'GREEN');
		printf(" Malware List\n");
		ColorText(" Penjelasan Tentang Tiap Malware\n\n", 'GREEN');
		printf(" Save\n");
		ColorText(" Simpan Permainan\n\n", 'GREEN');
		printf(">>> Log Off\n");
		ColorText(" Keluar dari Permainan\n\n", 'GREEN');
		printf("Petunjuk: Gunakan Atas-Bawah pada Keyboard untuk menentukan seleksi. ENTER untuk memilih.\n");
		break;
		}
		
		Controls(5, 0);
		
		if (choiceV == 1 && key == 13){
//			NewGame();
			break;
		}
		
		else if (choiceV == 2 && key == 13){
//			NewGame();		
			break;
		}
		
		else if (choiceV == 3 && key == 13){
//			HelpMenu();
			break;
		}
		
		else if (choiceV == 4 && key == 13){
//			QuitGame();
			break;
		}
		
	}

}

int NewGame()				//new game
{				
	system("cls");
	text2("> Sistem dijalankan...\n\n", 50);
	getch();
	text2("> Sistem menyala. Menghubungkan anda dengan server...\n\n", 50);
	getch();
	text2("> Terhubung!\n\n", 30);
	system("pause");
	system("cls");
	IMG("nationnetwork");
	
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
    
    Disclaimer();
    system("cls");
    IMG("title");
    text2("\t\tOleh E&I. 2018.\n\n",40);
	system("pause");
    
    Prologue();

}

int LoadGame()				//load game
{
	char password[10];
	system("cls");
	text2("> Enter Password:\n\n",20);
	scanf("%s", password);
	printf("\n\n");
	
	if((strcmp(password, "beforethestorm") == 0))
	{
    	printf("Password Accepted.\n\n");
    	system("pause");
    	Prologue();
	}
		
	else if((strcmp(password, "beginhunt") == 0))
	{
    	printf("Password Accepted.\n\n");
    	system("pause");
    	Chapter1();
	}
		
	else if((strcmp(password, "disaster") == 0))
	{
    	printf("Password Accepted.\n\n");
    	system("pause");
//    	Chapter2();
	}
		
	else if((strcmp(password, "anotherme") == 0))
	{
    	printf("Password Accepted.\n\n");
    	system("pause");
//    	Chapter3();
	}
	else if((strcmp(password, "darkness") == 0))
	{
    	printf("Password Accepted.\n\n");
    	system("pause");
//    	Chapter4();
	}
	
	else{
		printf("Password Rejected.\n\n");
    	system("pause");
    	LoadGame();
	}
}

int QuitGame()				//quit game
{				
	return -1;
}

int Disclaimer()			//teks disclaimer
{
	system("cls");
	text2("\t\t-- Disclaimer --\n\n",10);
	text2("Ini adalah karya fiksi.\nNama, karakter, tempat, dan kejadian adalah dari imajinasi penulis.\nKemiripan apapun kepada tokoh nyata, baik masih hidup maupun tidak, adalah kebetulan belaka.\n\n",30);
	system("pause");
}

int Prologue()				//berisi hardcode cerita prolog bagian 1
{
    
    system("cls");
    text2("\n\n\n\t\t\t-- Prologue: The Hunt --\n\n",30);
    text2("\t\t\t\t-- Day 1 --\n\n",30);
    system("pause");
    
    speaking("", "city");
    speak("(M District Shopping Plaza...)");
    speak("(Pusat perbelanjaan Kota D... Tempat yang nampaknya selalu ramai oleh pengunjung.)");
    speak("(Kuliah sudah memasuki musim liburan. Kamu berjanjian dengan teman-teman untuk bertemu di sini...)");
    speak("(Kamu melihat seorang laki-laki temanmu.)");

    speaking("A", "city");
    speak("Hey. Maaf terlambat. Pasti kamu sudah menunggu dari tadi.");
    speak("Tadi ada tugas liburan yang perlu diselesaikan secepatnya.");
    speak("Ngomong-ngomong, di mana yang lain?");

    speaking("", "city");
    text("(Ponsel mu berbunyi, menandakan ada pesan masuk.)\n");
    text("('Nampaknya hari ini kami akan menyusul kalian nanti sore, D dan aku sedang sibuk dengan sesuatu.' -  C)\n");
    
    speaking("A", "city");
    speak("Sepertinya baru kita saja sih ini.");
    speak("Ah, padahal aku mau mengajak kalian mencoba makanan yang ada di situ.");
    speak("Hmm, kenapa orang-orang semua berkumpul di depan layar itu ya?");

    speaking("A", "news");
    speak("Ternyata berita NationNetwork... Tapi aneh. Apakah mereka mengalami gangguan siaran?");

    system("cls");
    IMG("news");
    Sleep(1000);
    system("cls");
    IMG("we");
    Sleep(1000);
    system("cls");
    IMG("news");
    Sleep(1000);
    system("cls");
    IMG("we");
    
    speaking("A", "we");
    speak("Banyak glitch... sekarang menampilkan sesuatu... semacam tulisan.");
    speak("'WE'... 'Kami'?");
    speak("Ini bukan siaran NationNetwork. Ada seseorang yang meretas kedalam sistem layar ini.");
    
    speaking("Reporter", "we");    
    speak("Dilaporkan telah terjadi sebuah peretasan sistem di jaringan NationNetwork.");
    speak("Pihak Kepolisian menyimpulkan bahwa telah terjadi serangan teroris siber.");
    speak("Serangan ini jauh berbeda dengan apa yang pernah terjadi sebelumnya.");
    speak("Pemerintah telah mengirim polisi siber, hacker, dan tim investigasi untuk permasalahan ini.");

    speaking("A", "we");
    speak("Teroris siber...?");
    speak("Sulit dipercaya... Jaringan NationNetwork sangat terenkripsi dan aman...");
    speak("Gedung NationNetwork ada di kawasan paling terlindungi di negara ini, Blok 9. ");
    speak("Dan server mereka secara harafiah ada di bawah laut.");
    speak("Plus mereka punya Hacker terbaik di negara ini sebagai polisi siber mereka.");
    
    speaking("Reporter", "news");
    speak("Pemerintah telah menyatakan sistem kembali normal.");
    speak("Disimpulkan bahwa telah terjadi retasan pada instruksi model lama.");
    speak("Semua lubang keamanan pada sistem sudah diperbaiki, berkat kerja baik tim elit N2.");
    
    speaking("A", "news");
    speak("Secepat itukah bisa terselesaikan?");
    speak("Tim Hacker Elit N2 benar-benar sesuatu...");
    speak("Tapi peretasan jaringan Nation Network bukan hal yang mudah. ");
    speak("Siapapun yang dibalik hal ini, menurutku mereka bukan amatiran.");
    speak("Bagaimana menurutmu?");
    speak("Pikirkan. Jaringan NationNetwork melingkupi hampir segala media informasi di negara ini.");
    speak("Internet, Komunikasi seluler, pesawat TV, Media Sosial... ");
    speak("Semua perangkat Elektronik kita juga IoT yang terhubung dengan jaringan Nation Network.");
    speak("Mungkin saja hacker itu sedang meretas salah satu dari ponsel kita sekarang.");

    speaking("A", "news");
    speak("Haaa... Memikirkan ini akan membuatmu panik. Semoga saja N2 sudah menyelesaikan masalah ini.");
    speak("C dan D akan datang sore ini kan? Bagaimana kalau kita jalan-jalan dulu sambil menunggu mereka?");
    speak("Mari pergi ke arcade game yang ada di D Town Square. Mungkin menunggu disana akan lebih menyenangkan.");

    speaking("", "news");
    speak("(Merasa tidak ada yang lebih baik untuk dilakukan, kamu setuju untuk pergi ke arcade game.)");
    speak("(Kalian berdua meninggalkan area..)");

    Sleep(1000);
    system("cls");
    IMG("we");
    Sleep(1000);
    printf("\n\n");
    system("pause");
    progress++;     
    
    system("cls");
    
    Choice("Continue Game?", "Yes", "No");
    
    if (optionA == 1){
    	Prologue2();
	}
	else if (optionB == 1){
		StartMenu();
	}
	

}

int Prologue2()				//berisi hardcode cerita prolog bagian 2
{
	
	speaking("", "invader");
    speak("(D Town Square Game Arcade...)");
    speak("(Permainan Earth Invaders...)");

    speaking("A", "invader");
    speak("Hey, sudah lama aku tak bermain permainan itu.");
    speak("Kamu bisa memainkannya kan? Main berdua dong! Haha.");
    
    speaking("A", "invader2");
    speak("Tunggu sebentar...");
    speak("Alien ini terlihat aneh... Hah?!");
    speak("Itu tulisan WE yang tadi kita lihat! Sudah kutahu aku mempunyai firasat buruk soal ini.");
    speak("Coba lihat ke sekitar...");
    speak("Semua mesin permainan di tempat ini menunjukkan hal yang sama.");
    speak("Kita salah, yang tadi kita lihat bukanlah siaran. Ini Malware! Jaringan NationNetwork sudah terjangkit Malware.");
    speak("Semua mesin permainan di tempat ini menunjukkan hal yang sama.");

    speaking("A", "invader2");
    speak("Tapi apa motif dibalik serangan malware ini? Untuk akuisisi data?");
    speak("Bukan, menurutku lebih dari itu.");
    speak("Aku akan coba tap jaringan komunikasi mesin permainan ini menggunakan laptopku.");
    speak("Tenang saja, IP ku berada di balik tujuh Proxy dan Firewall. Tidak semudah itu malware ini bisa masuk.");
    
    speaking("", "invader2");
    speak("(A mulai mengetik dengan cepat...)");

    speaking("A", "invader2");
    speak("T-Tidak mungkin... malware ini ganas sekali. Satu.. dua Firewall-ku sudah ditembus.");
    speak("Tapi sepertinya aku tahu apa yang diambil oleh Malware ini.");
    speak("Mereka mencuri identitasmu. Semua keterangan tentang dirimu, akun bank, alamat pribadi, semuanya...");
    speak("Aku tidak tahu apa yang akan teroris ini perbuat, tapi aku tidak suka ini.");    
    speak("Dan Malware ini bersifat dorman. Meskipun komputer sudah dimatikan, mereka sudah menginfeksi ROM-mu.");
    speak("Kemudian sialnya kita hidup di zaman dimana perangkat kita selalu terhubung internet dalam kondisi apapun.");

    speaking("A", "invader2");
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
    IMG("title");
    
    text("\n\n> LAUNCHING HUNT.EXE. \n\n");
    text("> YOU HAVE ONE LAST CHANCE...\n");
    text2("\n> LET'S HUNT. \n\n",30);

    system("pause");
	
	Battle("invader2");
	
	speaking("A", "invader2");
    speak("Sial. Aku sudah di Firewall-ku yang terakhir. Aku tidak cukup cepat untuk mengatasi mereka.");
    speak("Jika mereka mendapat informasiku... Ugh...");
    speak("SIAAALLLLLL!");

}

int Chapter1()				//berisi hardcode cerita chapter 1
{			
	system("cls");
	
	text("Incoming Transmission...\n");
    printf("\n\n");
    system("pause");
    system("cls");
    
    IMG("operator");
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
	IMG("operator");
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

int Battle(char enemy[20])	//fungsi Battle
{
	
system("cls");

int PlayerHealth = 125;
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

   
		int random = rand();
		int DmgToPlayer = 10;
		DmgBlock = 0;
		printf("=================================\n");
		printf ("|\t Battle Now!\t\t|\t         \t|  Player HP: %d  Musuh HP: %d ",PlayerHealth,EnemyHealth);
		printf("\n=================================\t\t \t|  Player MP: %d  Musuh MP: %d \n",PMP,EMP);
		IMG(enemy);
		printf("\nPilih Action:\n\n[1]Serang (Menyerang Musuh Dengan 10 Damage)\n[2]Blokir (Memblokir serangan musuh sehingga Damage yang diterima berkurang)\n[3]Skill (Menggunakan 20 Mp untuk menyerang)\n");
		
			if (burn>0){
			DmgToEnemy += burn;
			burn -= 1;
			printf("\n\nMusuh terkena efek burn\n\n"
			);
		}
		if (frost>0){
			DmgToPlayer -= frost;
			frost -= 1;
			printf("\n\nMusuh terkena efek frost\n\n");
			
		}
		
		if (shock>0){
			DmgToPlayer = 0;
			shock -= 1;
			printf("\n\nMusuh terkena efek shock\n\n");
		}
		printf("Action: ");
		
		scanf("%d",&Choice1);
		if(Choice1==1){//the player choose to attack
			EnemyHealth = EnemyHealth - DmgToEnemy;
			DmgBlock = 0;
			printf("\n=============================================");
			printf("\nPemain menyerang musuh\n");
			printf("musuh terkena damage sebesar %d",DmgToEnemy);
		}
		else if(Choice1==2){//the player choose to Block
		DmgBlock +=  5;
			DmgToPlayer = DmgToPlayer - DmgBlock - random % 5;
				printf("================================================\n");
				printf("Player Memblokir serangan");
			
		}
		else if(Choice1==3){//the player choose to Skill
		printf("Skill list\n[1]Fire\n[2]Ice\n[3]Thunder\n");
			//The PLAYER then choose which skill to activate
			if (PMP >= 20){
			
			PMP -= 20;
				printf("Choose skill: ");
			scanf("%d",&Choice2);
				
		}
		
		else {
			printf("maaf, MP anda tidak cukup\n");
			
				
		}
			
			
			
			
			if(Choice2==1){//the player choose fireeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
			printf("================================================\n");
				printf("Player menyerang dengan fire\nMusuh terkena %d Damage", FireDmg);
				EnemyHealth -= FireDmg;
///////////////////////////////////////////////////////////////////					
	x = random % 2;

	if (x==0){
		printf("Musuh terkena efek burn");
		burn += 3;
		EnemyHealth -= burn *4/3;
	}
	else {
		printf("Musuh tidak terkena efek burn");
	}
	
				
			}
			else if(Choice2==2){//the player chose ice
				printf("================================================\n");
			printf("Player Menyerang dengan Frost %d Damage", IceDmg);
				EnemyHealth -= IceDmg;
				
			
	/////////////////////////////////////////////////////////////////////////////////			
	x = random % 2;
	
	printf("%d\n",x);
	
	if (x==0){
		
		printf("Musuh terkena efek Frost");
		frost += 2;
		DmgToPlayer -= frost *5/4;
	}
	else {
		printf("Musuh tidak terkena efek frost");
	}
	
			}
			else if(Choice2==3){//the player choose thunder
				printf("============================================\nPlayer Menyerang dengan menggunakan Thunder %d Damage", ThunderDmg);
				EnemyHealth -= ThunderDmg;
					
	x = random % 2;
	
	
	if (x==0){
		printf("\nMusuh terkenea efek Shock");
		shock += 1;
		DmgToPlayer = 0;
	}
	else {
		printf("\nMusuh tidak terkena efek shock");//shoccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccck
	}
	
	
			}
			
			
		}
		else {
			printf("maaf, masukan salah\n");
			system("pause");
			system("cls");
			return main();
		
		}
			y = random % 2;
			if (y==1 && EMP >= 20){
			DmgToPlayer += 5;
			
	 	printf("\nMusuh Menggunakan Skill");
		PlayerHealth = PlayerHealth - DmgToPlayer;
		printf("\nplayer terkena damage sebesar %d",DmgToPlayer);
		EMP -= 20;
		
	}
	else{
		printf("\nEnemy Menyerang");
		PlayerHealth = PlayerHealth - DmgToPlayer;
		printf("\nplayer terkena damage sebesar %d",DmgToPlayer);
	}
		printf("\nRound over \n=============================================\n");
		system("pause");
		system("cls");
	
	}
	while(PlayerHealth>0 && EnemyHealth>0);
	
	if (EnemyHealth <= 0){
			printf("=================================\n");
		printf("\nYouWin\n\n");
			printf("=================================\n");
	}
	

	
	else if (PlayerHealth <= 0) {
			printf("=================================\n");
		printf("\nGame Over\n\n");
			printf("=================================\n");
	}
}
                                            
void Controls(int cNumVert, int cNumHorz)		//Kontroler Axis-H dan Axis-V Keyboard
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
}    
                              
void Mission(int mNumber)	//Berisi misi-misi player
{
	switch(mNumber)
	{
		case 1:
			printf("Hunt 5 DogMalwares.\n\n");
	}
}      

void ChoiceDialog(char charname[20], char filename[20], char prevText[MAX_LEN], char choice1[MAX_LEN], char choice2[MAX_LEN]) 
//berisi pilihan dialog
{
	optionA = 0; 
	optionB = 0;
	ResetControls();
	
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
		
		Controls(2,0);
		
		if (choiceV == 1 && key == 13){
			optionA=1;
			break;
		}
		
		else if (choiceV == 2 && key == 13){
			optionB=1;	
			break;
		}
	}
}   

void Choice(char prevText[MAX_LEN], char choice1[MAX_LEN], char choice2[MAX_LEN]) 
//berisi pilihan diluar dialog
{
	optionA = 0; 
	optionB = 0;
	ResetControls();
	
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
		
		Controls(2,0);
		
		if (choiceV == 1 && key == 13){
			optionA=1;
			break;
		}
		
		else if (choiceV == 2 && key == 13){
			optionB=1;	
			break;
		}
	}
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
