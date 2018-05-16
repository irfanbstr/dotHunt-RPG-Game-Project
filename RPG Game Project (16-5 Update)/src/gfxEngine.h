
void IMG(char *filename)	//fungsi print gambar dari file .txt pakai pointer
{	
	char *dir[80];
	strcpy(dir, "assets/");
	strcat(dir, filename);
	strcat(dir, ".txt");
	
//	printf("%s", dir);
	
    FILE *fptr = NULL;
 
    if((fptr = fopen(dir,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
 
    fclose(fptr);
 
    return 0;
}
