#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represent each row of the text.txt file
typedef struct row {
    // string
    char column0[10];
    // column two and three
    int column1;
    int column2;
    // column four
    double column3;
} Row;

int main() {
    // Array of struct to represent the whole text.txt file
    Row rows[10];
    // Opening the file pointer
    FILE *fp;
    // Line buffer size
    size_t len = 0;
    // Get row value into this variable
    char *line;
    // Opening the file and assigning it into file pointer fp
    fp = fopen("../text.txt", "r");

    // Track current line
    int i = 0;
    // Read the whole file
    while (getline(&line, &len, fp) != -1) {
        printf("%s\n", line);
        char *token;
        // Tokenizing the line and assigning it into particulate row
        token = strtok(line, " ");
        strcpy(rows[i].column0, token);
        rows[i].column1 = atol(strtok(NULL, " "));
        rows[i].column2 = atol(strtok(NULL, " "));
        rows[i].column3 = atof(strtok(NULL, " "));
        i++;
    }
    // Closing the file pointer
    fclose(fp);
    return 0;
}
