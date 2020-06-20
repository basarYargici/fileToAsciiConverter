/*
 * Write a C program including necessary functions to convert a binary
 * file to a text file. Finally, your program will write the bit representation
 * of each byte in the binary file to the text file in a way that there will be
 * 8 ‘1’ or ‘0’ characters at each line. You will not modify the binary file.
 * Prove by examples that your algorithm works well.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 255

void valueToBinary(char *);

char *getChar(char *);

int main() {
    char *getStr;
    getStr = (char *) malloc(maxSize);//255 byte-character
    char fileName[] = "homework";
    FILE *f;
    f = fopen(fileName, "w");
    //getStr = (char*)malloc(sizeof(char));//8 byte-character
    printf("Enter the character to find binary value(ASCII value): ");
    scanf("%s", getStr);

    fprintf(f, "%s", getStr);
    fclose(f);

    printf("ASCII Binary : ");
    valueToBinary(fileName);

    printf("Done!\n");
    system("Pause");

    return 0;
}

void valueToBinary(char *fileName) {
    char *ch;
    ch = (char *) malloc(2 * sizeof(char *));
    //int k = 0;
    FILE *fptr, *fptr2;
    fptr = fopen(fileName, "r");
    fptr2 = fopen("temp.txt", "w");
    while (fscanf(fptr, "%s", ch) != EOF) {
        strcpy(ch, getChar(ch));
        for (int i = 0; i < strlen(ch); i++) {
            for (int j = 7; j >= 0; --j) {
                fputc((ch[i] & (1 << j)) ? '1' : '0', fptr2);
                putchar((ch[i] & (1 << j)) ? '1' : '0');
            }
            fputc('\n', fptr2);
            putchar('\n');
        }
    }
    fclose(fptr);
    fclose(fptr2);
}

char *getChar(char *c) {
    int lenght = strlen(c);
    while (lenght--) {
        if (c[lenght] == '\n')
            c[lenght] = '\0';
    }
    return c;
}
