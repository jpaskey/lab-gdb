#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *openFile(char *name) {
    FILE *f = fopen(name, "r");
    if(f == NULL) {
        printf("Cannot open %s\n", name);
        exit(1);
    }
    return f;
}

int copyFile(FILE *f, char *target[], int maxLineCnt) {
    int i;
    char temp[100];
    for(i = 0; i < maxLineCnt; i++) {
        if(fgets(temp, 100, f) == NULL) break;
        target[i]=malloc(strlen(temp)+1);
        strcpy(target[i], temp);
    }
    return i + 1;
}

int main() {
    char *lines[20];
    int lineCnt;
    FILE *file = openFile("Sunset.txt");
    lineCnt = copyFile(file, lines, 20);
    fclose(file);
    printf("Total of lines: %d\n", lineCnt);
    return 0;
}
