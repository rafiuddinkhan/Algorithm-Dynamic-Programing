#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int matrix[100][100];
int picks[100][100];

int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++){
        for (j=0;j<=size;j++){
            if (weights[i-1]<=j){
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                    picks[i][j]=1;
                else
                    picks[i][j]=-1;
            }
            else{
                picks[i][j] = -1;
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][size];

}

void printPicks(int item, int size, int weights[]){

    while (item>0){
        if (picks[item][size]==1){
            printf("%d ",item-1);
            item--;
            size -= weights[item];
        }
        else{
            item--;
        }
    }

    printf("n");

return;
}

int main(){
    int i,a;
    int nItems;
    int knapsackSize;
    int weights[40];
    int values[40];

    while(1){
    printf("enter the no of items\n");
    scanf("%d",&nItems);

    printf("enter the knapsack size\n");
    scanf("%d",&knapsackSize);

    printf("enter the weights\n");
    for(i=0;i<nItems;i++){
        scanf("%d",&weights[i]);
    }

     printf("enter the price\n");
    for(i=0;i<nItems;i++){
        scanf("%d",&values[i]);
    }

    printf("Max value = %d",knapsack(nItems,knapsackSize,weights,values));
    printf("Picks were: ");
    printPicks(nItems,knapsackSize, weights);

    printf("\ndo you want to continue.Type (0) for no or (1) for yes");
    scanf("%d",&a);
    if(a==0){
    	exit(1);
    }
    else{
    	continue;
    }


    }

    return 0;
}
