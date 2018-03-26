#include "Ordenacao.h"















int main(){

int vet[10] = {9,8,10,5,4,8,5,7,2,3};
int n =10;
//BubbleSort(vet,10);
//SelectSort(vet,10);
//InsertSort(vet,10);
//MergeSort(vet,0,n-1);
 quickSort(vet,0,n-1);


int i;


for( i = 0;i < n;i++)
  printf(" %d",vet[i]);   


return 0;
}