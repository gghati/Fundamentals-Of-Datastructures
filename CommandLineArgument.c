/*
=====================================================================
Assignment : File Handling by Command Line Arguments.
Name : Gaurav Ghati
class : SE 10
Batch : F 10

Problem Statement:
	Write C program to implement TYPE and COPY commands of DOS using command line arguments.
====================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]){
   FILE *fp,*fs,*fd;
   char c;
   if(argc==3 && !strcmp(argv[1],"TYPE")){
	fp = fopen(argv[2], "r");
	if (fp == NULL){
	      printf(" '%s' File Not Found!.", argv[2]);
	} else {
	      printf("'%s' File Contents:\n", argv[2]);
	      while ((c = getc(fp)) != EOF){
		     printf("%c",c);
	      }
	      fclose(fp);
	}
  }

  if(argc==4 && !strcmp(argv[1],"COPY")){
	fs= fopen(argv[2],"r");
	fd= fopen(argv[3],"w");
	if((fs==NULL)||(fd==NULL)){
		printf("Cannot Open File.");
	} else {
		while((c=getc(fs))!=EOF){
			putc(c,fd);
		}
	        printf("File '%s' is Copied Successfully in File '%s'.", argv[2], argv[3]);
		fclose(fs);
		fclose(fd);
	}
   }
   if(argc==1 || argc==2){
	   printf("Please Input Correct arguments in cmd!");
   }
    return 0;
}


