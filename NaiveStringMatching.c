#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void naive_string(char *text, char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    int j;

    for(int i=0 ; i<=n-m ; i++) {
        for(j=0 ; j<m ; j++) {
            if(text[i+j] != pattern[j])
                break;
        }
        if(j == m)
            printf("Pattern found at index %d", i);
    }
}

int main() {
    char *text = (char *) malloc (MAX * sizeof(char));
    char *pattern = (char *) malloc (MAX * sizeof(char));

    printf("Enter the text string: ");
    scanf("%99s", text);
    printf("Enter the input string: ");
    scanf("%99s", pattern);

    naive_string(text, pattern);

    return 0;
}