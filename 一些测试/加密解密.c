#include <stdio.h>
#include <stdlib.h>

 int main()
 {

     FILE* fp1 = fopen("D:\\data\\origin.txt", "r");
     FILE* fp2 = fopen("D:\\data\\obj.txt", "w");
     FILE* fp3 = fopen("D:\\data\\obj.txt", "r");
     FILE* fp4 = fopen("D:\\data\\answer.txt", "w");
     int ch;

     if (!fp1 || !fp2) {

         return -1;
     }

     while ((ch = fgetc(fp1)) != -1) {

         ch++;
         fputc(ch, fp2);
     }

     fclose(fp1);
     fclose(fp2);

     while ((ch = fgetc(fp3)) != -1) {

         ch--;
         fputc(ch, fp4);
     }

     fclose(fp3);
     fclose(fp4);

     return(0);
 }
