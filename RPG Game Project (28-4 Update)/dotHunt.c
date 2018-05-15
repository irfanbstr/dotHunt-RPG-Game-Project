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

void prologue()
{
	
	system("cls");
	text2("\n\n\n\t\t\t-- Prologue: The Hunt --\n\n",30);
	text2("\t\t\t\t-- Day 1 --\n\n",30);
	system("pause");
	
	system("cls");
	
	img("city.txt");
	printf("\n\n");
	text("(D City, M District...)\n");
	text("(Kamu dan teman-teman sedang berjalan melewati pusat kota yang ramai...)\n");
	text("(Kelihatannya semua orang sedang berkumpul di depan layar besar...)");
	
	system("cls");
	
	img("city.txt");
	printf("\n\n");
	printf("[A]\n");
	text2("-- Lihat, ",30);
	text2(name,30);
	text2("! --",30);
	getch();
	text("\n-- Banyak sekali orang berkumpul di sana. --\n");
	text("-- Sepertinya ada yang sedang terjadi. Mau ke sana dan lihat? --\n");
	text("-- Pasti ada sesuatu yang menarik jika ada orang sebanyak ini... --\n");
	
	
	system("cls");
	
	img("news.txt");
	printf("\n\n");
	printf("[A]\n");
	text("-- Ternyata berita NationNetwork. Tapi ada yang aneh dengan siaran nya... --");
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
	
	printf("\n\n");
	printf("[A]\n");
	text("-- Banyak glitch. --\n");
	text("-- Tunggu, sekarang menampilkan tulisan 'WE'... 'Kami'? --\n");
	text("-- Ini bukan siaran NationNetwork. Ada seseorang yang meretas kedalam sistem layar ini. --\n");
	
	system("cls");
	img("we.txt");
	printf("\n\n");
	printf("[Reporter]\n");
	text("-- ...-dilaporkan telah terjadi sebuah peretasan sistem di jaringan NationNetwork.--\n");
	text("-- Pihak Ofisial menyimpulkan bahwa telah terjadi serangan teroris siber.--\n");
	text("-- Serangan ini jauh berbeda dengan apa yang pernah terjadi sebelumnya.--\n");
	text("-- Pemerintah telah mengirim polisi siber, hacker, dan tim investigasi untuk permasalahan ini.--\n");
	system("cls");

	img("we.txt");
	
	printf("\n\n");
	printf("[A]\n");
	text("-- Teroris siber...? --\n");
	text("-- Sulit dipercaya... Jaringan NationNetwork sangat terenkripsi dan aman... --\n");
	text("-- Gedung NationNetwork ada di kawasan paling terlindungi di negara ini, Blok 9. --\n");
	text("-- Dan server mereka secara harafiah ada di bawah laut. --\n");
	text("-- Plus mereka punya Hacker terbaik di negara ini sebagai polisi siber mereka. --\n");
	
	system("cls");
	img("news.txt");
	printf("\n\n");
	printf("[Reporter]\n");
	text("-- ...-pemerintah telah menyatakan sistem kembali normal.--\n");
	text("-- Disimpulkan bahwa telah terjadi retasan pada instruksi model lama.--\n");
	text("-- Semua lubang keamanan pada sistem sudah diperbaiki, berkat kerja baik tim dari N2. --\n");
	
	system("cls");
	img("news.txt");
	printf("\n\n");
	printf("[A]\n");
	text("-- Lihat kan? --\n");
	text("-- Ternyata bukan apa-apa bagi tim N2. Mari pergi. --\n");

	system("cls");
	img("news.txt");
	
	printf("\n\n");
	text("(Apakah benar bukan apa-apa?)\n");
	text("(...)\n");
	Sleep(1000);
	system("cls");
	img("we.txt");
	Sleep(100);
	system("cls");
	img("news.txt");
	text("\n\n(!)\n");
	text("(Ada sesuatu yang tidak benar...)\n\n");
	text("(...)\n");
	text("(Kamu memutuskan untuk pergi.)\n");
	
	system("cls");
	text2("\n\n\n\t\t\t\t-- Day 2 --\n\n",30);
	system("pause");
	
	system("cls");
	
	img("city.txt");
	printf("\n\n");
	text("(D City, M District...)\n");
	text("(Lagi-lagi terjadi keramaian di pusat kota... nampaknya lebih banyak dibandingkan kemarin.)\n");
	text("(Semua orang sedang berkumpul di depan layar besar...)");
	
	system("cls");
	
	img("city.txt");
	printf("\n\n");
	printf("[A]\n");
	text2("-- Hey, ",30);
	text2(name,30);
	text2(". --",30);
	getch();
	text("\n-- Apakah kau sudah dengar beritanya? --\n");
	text("-- Siaran itu kembali lagi. Dan tadi malam ada beberapa orang yang dilaporkan menghilang. --\n");
	text("--  --\n");
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
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
