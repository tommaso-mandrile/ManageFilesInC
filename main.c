#include <stdio.h>
#include <stdbool.h>


void numbersInFile(void) {
    FILE *fp = fopen("sas.txt", "w");
    int n = 0;
    int count = 1;
    printf("Write numbers to add to the file (-1 exits): ");
    while (true) {
        scanf("%d\n", &n);
        if (n == -1) break;
        fprintf(fp, "Number %d: %d\n",count, n);
        count ++;
    }
    fclose(fp);
}

void readAFile(void) {
    FILE *fp;
    fp = fopen("2choiceFile.txt", "r");
    char Buffer[100];
    fgets(Buffer, 100, fp);

    printf("%s\n", Buffer);

    fclose(fp);
}

int main(void) {

    printf("Menu: \n1 - Write numbers in a blank file\n2 - Read text from an existing file.\n");
    int choice = 0;

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            numbersInFile();
            break;
        case 2:
            readAFile();
            break;
        default:
            printf("This is not a choice from the menu.");
            break;
    }

    return 0;
}
