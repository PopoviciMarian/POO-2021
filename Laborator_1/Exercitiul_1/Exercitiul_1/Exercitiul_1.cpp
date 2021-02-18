#include <stdio.h>
#pragma warning(disable:4996)

int my_atoi(char s[20]) {
    int result = 0;
    int i = 0;;
    while (s[i] != '\n' && s[i] != '\0') {
        result = result * 10 + s[i] - '0';
        i++;
    }
    return result;
}

int main() {
    FILE* file;
    int sum = 0;
    char strNr[20];
    file = fopen("in.txt", "r");

    while (true) {
        fgets(strNr, 20, file);
        sum += my_atoi(strNr);

        if (feof(file)) {
            break;
        }
    }
    printf("%d", sum);
    fclose(file);
    return(0);
}