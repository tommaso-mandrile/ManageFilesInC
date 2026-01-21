#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void numbersInFile(void) {
    FILE *fp = fopen("yourNumbers.txt", "w");
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

void listFile(void) {
    FILE *fp = fopen("info.csv", "r");
    int choice;
    int age;
    char BufferName[100], BufferSurname[100], toSearchName[100];
    bool found = false;

    while (fscanf(fp, "%s %s %d", BufferName, BufferSurname, &age) == 3) {
        printf("%s %s, %d\n", BufferName, BufferSurname, age);
    }
    rewind(fp); //resets fp cursor
    printf("Do you wanna search by NAME (type 1) or SURNAME (type 2)?\n");

    scanf("%d", &choice);
    do {
        if (choice == 1 || choice == 2) {
            break;
        }
        printf("Invalid choice. Choose between 1 or 2.\n");
        scanf("%d", &choice);
    }while (true);

    switch (choice) {
        case 1:
            printf("Write the NAME you want to know the age of:\n");
            scanf("%s", toSearchName);
            while (!found) {
                if (fscanf(fp, "%s %s %d", BufferName, BufferSurname, &age ) == 3) {

                    if (strcmp(toSearchName, BufferName) == 0) {
                        printf("%s %s's age has been found: %d years old\n", BufferName, BufferSurname, age);
                        found = true;
                    }
                }else {
                    printf("There isn't %s's name on the list\n", toSearchName);
                    break;
                }
            }
            break;
        case 2:
            printf("Write the SURNAME you want to know the age of:\n");
            scanf("%s", toSearchName);
            while (!found) {
                if (fscanf(fp, "%s %s %d", BufferName, BufferSurname, &age ) == 3) {
                    if (strcmp(toSearchName, BufferSurname) == 0) {
                        printf("%s %s's age has been found: %d years old\n", BufferName, BufferSurname, age);
                        found = true;
                    }
                }else {
                    printf("There isn't %s's surname on the list\n", toSearchName);
                    break;
                }
            }
            break;

        default:
            break;
    }
    fclose(fp);
}

int main(void) {
    printf("Menu: \n1 - Write numbers in a blank file\n2 - Read text from an existing file.\n3 - A little more complex program always about reading files\n");
    int choice = 0;

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            numbersInFile();
            break;
        case 2:
            readAFile();
            break;
        case 3:
            listFile();
            break;
        default:
            printf("This is not a choice from the menu.\n");
            break;
    }

    return 0;
}
