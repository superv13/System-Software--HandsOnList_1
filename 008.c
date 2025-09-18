/*
..........................................................................................................................................
Name : 008.c
Author : SHRUTI VERMA
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
              Close the file when end of file is reached.
Date : 22 Aug 2025
..........................................................................................................................................
*/


#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>


int main() {
	FILE *f;
	char entered_char;
	char entered_to_continue;
	
	f = fopen("8.file", "r");
	if(f==NULL)
	perror("error opening file");
	
	while(1)
	{      
	        entered_char = fgetc(f);
	        if(entered_char==EOF)
	        break;
	        if(entered_char == '\n')        
	        { 
	          entered_to_continue = getchar();
	          if(entered_to_continue == '\n')
	          continue;
	        }
	        putchar(entered_char);
	        
	}
	fclose(f);
}	
  /* ----------------------------------OUTPUT--------------------------------------------
        
          vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/Learn/HoL-1$ gcc 008.c -o 008.0ut
          vumma@vumma-VivoBook-15-ASUS-Laptop-X507UF:~/Desktop/Learn/HoL-1$ ./008.0ut
          1 system software    
          2 algorithm
          3 machine learning
          4 mathematics for machine learning
          5 concrete mathematics

  
      
  
  
  */
