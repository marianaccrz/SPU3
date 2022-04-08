#include <stdlib.h>
#include <stdio.h>

void printFileList(char* path  ){
        FILE* file =  fopen(path, "r"); //Open the file from a path just to read
        char currentLine[10]; //String to store the current line

        while (  fscanf(  file, "%s", currentLine ) != EOF  ) //Loop to scan all line in a file.txt (EOF is End Of the File)
        {//file is the pointer of the file, %s the format to read, currentLine string to store the current line in loop
                printf("line: %s\n",currentLine ); //Just print the file
        }
        fclose(file); //Close the file
}
