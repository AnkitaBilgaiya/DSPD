#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src, *dest;
    char source[30], target[30], ch;

    printf("Enter input file name: ");
    scanf("%s", source);
    printf("Enter output file name: ");
    scanf("%s", target);

    src = fopen(source, "r");
    if(src == NULL) {
        printf("Cannot open input file.\n");
        exit(0);
    }

    dest = fopen(target, "w");
    if(dest == NULL) {
        printf("Cannot create output file.\n");
        fclose(src);
        exit(0);
    }

    while((ch = fgetc(src)) != EOF)
        fputc(ch, dest);

    printf("File copied successfully!\n");
    fclose(src);
    fclose(dest);
    return 0;
}