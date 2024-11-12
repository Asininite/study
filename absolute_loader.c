#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp1, *fp2;
int i, j, hexaddr;
char ch, line[50], addr[10];

void main(){
    fp1 = fopen("input.txt", "r");

    do {
        fscanf(fp1, "%s", line);
        if(line[0] == 'T'){
            for(i=1, j=0; i<=6; i++, j++){
                addr[j] = line[i];
            }

            addr[j] = '\0';
        }

        fp2 = fopen("temp.txt", "r+");
        fprintf(fp2, "%s", addr);
        rewind(fp2);
        fscanf(fp2, "%x", &hexaddr);
        fclose(fp2);

        i = 9;
        while(line[i]!='\0'){
            printf("%x \t %c%c", hexaddr, line[i], line[i+1]);
            hexaddr += 1;
            i += 2;
        }
    }

    while(!feof(fp1));
    fclose(fp1);
}