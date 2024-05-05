#include <stdio.h>
#include <stdlib.h>

int main() {
    int length, total_weight, ctr = 0;
    float sum = 0;
    printf("Enter the length: ");
    scanf("%d", &length);

    printf("\nEnter the total weight: ");
    scanf("%d", &total_weight);

    float *weight = (float*) malloc (length * sizeof(float));
    float *profit = (float*) malloc (length * sizeof(float));
    int *index = (int*) malloc (length * sizeof(int));
    float *pw = (float*) malloc (length * sizeof(float));
    float *x = (float*) malloc (length * sizeof(float));

    printf("\nEnter the Profits:\n");
    for(int i = 0 ; i < length ; i++) {
        scanf("%f", &profit[i]);
        index[i] = i;
        x[i] = 0.0;
    }

    printf("\nEnter the Weights:\n");
    for(int i = 0 ; i < length ; i++) {
        scanf("%f", &weight[i]);
        pw[i] = profit[i] / weight[i];
    }

    for(int i = 0 ; i < length - 1 ; i++) {
        for(int j = 0 ; j < length - i - 1 ; j++) {
            if(pw[j] < pw[j+1]) {
                float temp = pw[j];
                pw[j] = pw[j+1];
                pw[j+1] = temp;
                
                temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;

                int temp1 = index[j];
                index[j] = index[j+1];
                index[j+1] = temp1;
            }
        }
    }

    int temp = total_weight;

    int i = 0;
    while(temp > 0) {
        if(weight[i] <= temp) {
            x[i] = 1;
            temp -= weight[i];
        }
        else {
            x[i] = temp / weight[i];
            temp = 0;
        }
        i++;
    }
    
    for(int i = 0 ; i < length ; i++) 
        sum += (x[i] * profit[i]);

    printf("\nMaximum Profit: %.4f", sum);

    free(weight);
    free(profit);
    free(index);
    free(pw);
    free(x);

    return 0;
}
