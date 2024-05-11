#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int max(int a, int b) {
    return a > b ? a : b;
}

int longest_common_subsequence(char *str1, char *str2, char *lcs) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int **LCS = (int **) malloc ((len1 + 1) * sizeof(int *));
    for (int i=0 ; i<=len1 ; i++) {
        LCS[i] = (int *) malloc ((len2 + 1) * sizeof(int));
        if(LCS[i] == NULL) {
            printf("\nMemory allocation is not possible");
            exit(1);
        }
    }

    for(int i=0 ; i<=len1 ; i++) {
        for(int j=0 ; j<=len2 ; j++) {
            if(i==0 || j==0)
                LCS[i][j] = 0;
            else if(str1[i - 1] == str2[j - 1])
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }

    int index = LCS[len1][len2];
    lcs[index] = '\0';

    int i = len1, j = len2;
    while(i > 0 && j > 0) {
        if(str1[i - 1] == str2[j - 1]) {
            lcs[--index] = str1[i - 1];
            i--;
            j--;
        } 
        else if(LCS[i - 1][j] > LCS[i][j - 1])
            i--;
        else
            j--;
    }

    for (int i=0 ; i<=len1 ; i++) {
        free(LCS[i]);
    }
    free(LCS);

    return strlen(lcs);
}

int main() {
    char *str1, *str2, *lcs;

    str1 = (char *) malloc (MAX * sizeof(char));
    str2 = (char *) malloc (MAX * sizeof(char));
    lcs = (char *) malloc (MAX * sizeof(char));

    if(str1 == NULL || str2 == NULL || lcs == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    printf("Enter string 1: ");
    scanf("%99s", str1);

    printf("Enter string 2: ");
    scanf("%99s", str2);

    int lcs_length = longest_common_subsequence(str1, str2, lcs);
    printf("Length of longest common subsequence: %d\n", lcs_length);
    printf("Longest common subsequence: %s\n", lcs);

    free(str1);
    free(str2);
    free(lcs);

    return 0;
}
