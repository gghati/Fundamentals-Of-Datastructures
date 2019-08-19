/*
 ============================================================================
 Name        : FileHandling.c
 Author      : Gaurav Ghati
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style


THEORY :

File opening modes in C:

    “r” – Searches file. If the file is opened successfully fopen( ) loads it
          into memory and sets up a pointer which points to the first character
          in it. If the file cannot be opened fopen( ) returns NULL.

    “w” – Searches file. If the file exists, its contents are overwritten.
          If the file doesn’t exist, a new file is created. Returns NULL,
          if unable to open file.

    “a” – Searches file. If the file is opened successfully fopen( )
          loads it into memory and sets up a pointer that points to the
          last character in it. If the file doesn’t exist, a new file is
          created. Returns NULL, if unable to open file.

    “r+” – Searches file. If is opened successfully fopen( ) loads
           it into memory and sets up a pointer which points to the
           first character in it. Returns NULL, if unable to open the file.

    “w+” – Searches file. If the file exists, its contents are overwritten.
           If the file doesn’t exist a new file is created. Returns NULL,
           if unable to open file.

    “a+” – Searches file. If the file is opened successfully fopen( ) loads
           it into memory and sets up a pointer which points to the last character in it.
           If the file doesn’t exist, a new file is created. Returns NULL,
           if unable to open file.

Opening of File -

		FILE *filePointer;
		So, the file can be opened as
		filePointer = fopen(“fileName.txt”, “w”)

Reading from a file -

        FILE * filePointer;
		filePointer = fopen(“fileName.txt”, “r”);
		fscanf(filePointer, "%s %s %s %d", str1, str2, str3, &year);

Closing a file-

		FILE *filePointer ;–
		filePointer= fopen(“fileName.txt”, “w”);
		---------- Some file Operations -------
		fclose(filePointer)

Writing in File-
		char dataToBeWritten[50] = "GeeksforGeeks-A Computer Science Portal for Geeks";

        if ( strlen (  dataToBeWritten  ) > 0 ){
            // writing in the file using fputs()
            fputs(dataToBeWritten, filePointer) ;
            fputs("\n", filePointer) ;
        }

Reading from file:

        FILE *filePointer ;
        char dataToBeRead[50];
        while( fgets ( dataToBeRead, 50, filePointer ) != NULL ){
            // Print the dataToBeRead
            printf( "%s" , dataToBeRead ) ;
         }

 ============================================================================
 */

/*  Code for Adding  sentence into the  newFile.txt file
 *  The Pointer will be set to starting point of the file
 *  So, it will start writing things from beginning
 *  It will create a file if the file doesn't exist
 *  else it will open the existing file */

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *outFile;
    char dataToBeWritten[1000] = "Searches file. If the file is opened successfully fopen loads it into memory and sets up a pointer that points to the last character in it. If the file doesn’t exist, a new file is created. Returns NULL, if unable to open file.";
    outFile = fopen("newTXT.txt", "w");
    fputs(dataToBeWritten, outFile) ;
    fputs("\n", outFile) ;
	return 0;
}
