#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

void computeLPSArray(char *pat, int m, int *lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *pat, char *txt) {
    int n = strlen(txt);
    int m = strlen(pat);

    int *lps = (int*)malloc(m * sizeof(int));

    if (lps == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    computeLPSArray(pat, m, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((n - i) >= (m - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Found pattern at index %d\n", i - j);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    free(lps);
}

int main() {
    char *txt = (char *) malloc (MAX * sizeof(char));
    char *pat = (char *) malloc (MAX * sizeof(char));

    printf("Enter the text: ");
    scanf("%99s", txt);

    printf("Enter the pattern: ");
    scanf("%99s", pat);

    KMPSearch(pat, txt);

    free(txt);
    free(pat);

    return 0;
}