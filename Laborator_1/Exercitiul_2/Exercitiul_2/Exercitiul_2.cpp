#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996)

int main() {
    char  str[100];
    scanf("%[^\n]s", &str);

    char* pch;
    char word_list[100][40];
    int n = 0;
    pch = strtok(str, " ");

    while (pch != NULL) {
        strcpy(word_list[n++], pch);
        pch = strtok(NULL, " ");
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strlen(word_list[j]) < strlen(word_list[j + 1])) {
                char aux[40];
                strcpy(aux, word_list[j]);
                strcpy(word_list[j], word_list[j + 1]);
                strcpy(word_list[j + 1], aux);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        printf("%s\n", word_list[i]);
    }
    return 0;
}