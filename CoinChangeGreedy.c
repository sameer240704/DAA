#include <stdio.h>
#include <stdlib.h>

int main() {
    int cost, coins, index = 0;
    printf("Enter total value: ");
    scanf("%d", &cost);

    printf("Enter the number of coins: ");
    scanf("%d", &coins);

    int *coins_value = (int*) malloc (coins * sizeof(int));
    int *coins_list = (int*) malloc (cost * sizeof(int));

    printf("\nEnter the coin values:\n");
    for(int i = 0 ; i < coins ; i++) 
        scanf("%d", &coins_value[i]);

    for(int i = coins - 1 ; i >= 0 ; i--) {
        while(cost >= coins_value[i]) {
            cost -= coins_value[i];
            coins_list[index++] = coins_value[i];
        }
    }

    printf("\nThe selected coins for cost %d are: ", cost);
    for(int i = 0 ; i < index ; i++) 
        printf("%d ", coins_list[i]);

    return 0;
}