#include <stdio.h>
#include<stdlib.h>

#include "Ordenacao.h"

//funcao  para trocar as posições #

 void swap(int *fp , int *sp){
    int aux;
    aux = *fp;
    *fp = *sp;
    *sp = aux;
    }
    //funçao auxilar do quicksort que faz a partição do vetor
    int partition(int *arr,int begin,int end){
        int q  =(begin-1);
        printf("%d\n",q);
        int v = arr[end];
        int i;
        for(i = begin; i <=end-1;i++){
            if(arr[i] <= v){
                    q++;
            swap(&arr[i],&arr[q]);
            
            }
        


        }
        swap(&arr[q+1],&arr[end]);
        return (q+1);

        }
// funcao auxilar do mergesort, junta dois sub vetores do vet[]
 int merge(int vet[],int inicio,int m,int fim){
        //printf("entrou no merge\n");
    int i,j,k;
    int n1 = (m-inicio)+1;
    int n2 = fim-m;

    int L[n1],R[n2];
    // copiar os dados do vet para os sub vetores
    for(i = 0 ; i<n1 ;++i)
    L[i] = vet[inicio + i];
    for(j = 0;j <n2; ++j)
    R[j] = vet[m+1+j];

    //printf("preencheu o sub-vetor\n");
    //merge os vetores temporario L e R
    j =0;
    i = 0; 
    k = inicio;

    while(i <n1 && j <n2){
    // printf("entra merge\n");
    if(L[i]<= R[j]){
        vet[k] = L[i];
        i++;
    }else{
        vet[k] = R[j];
        j++;
    }
    k++;
    }
    //printf("terminou o merge\n");
    //copia os elementos restantes de L para vet, se houver
    while(i < n1){
        vet[k] = L[i];
        i++;k++;
    }

    //copia os elementos restantes de R para vet, se houver
    while(j < n2){
        vet[k] = R[j];
        j++;k++;
    }

    }

void BubbleSort(int vetor[],int n){
    int i,j;
    printf("bubble");
    for(i = 0;i < n ; i++){
        for(j = n-1;j>= (i+1);j--) { 
            if(vetor[j]<vetor[j-1]){
            swap(&vetor[j],&vetor[j-1]);
            
            }
        }
    }
}

void SelectSort(int vetor[],int n){
    int i, j , small;
    for(i = 0 ;i<n;i++){
        small = i;
        for(j = i+1;j <n;j++){
            if(vetor[j] < vetor[small]){
                swap(&vetor[j],&vetor[small]);
            
            }  
        }
    }
}

void InsertSort(int vetor[],int n){
    int i,j,key;
    for(j =1;j <n;j++){
        key = vetor[j];
        i = j-1;
        while(i>=0 && vetor[i] > key){
            vetor[i+1] = vetor[i];
            i = i-1;
        }
        vetor[i+1] = key;
    }
}

void MergeSort(int vet[],int inicio,int fim){
        if(inicio <fim){
            int m  =inicio+(fim-inicio)/2;
            
            MergeSort(vet,inicio,m);
            MergeSort(vet,m+1,fim);
            
            merge(vet,inicio,m,fim);
    

        }
    
}

void quickSort(int arr[],int begin,int end){
    
    if(begin < end){
        int q = partition(arr,begin,end);
        quickSort(arr,begin,q-1);
        quickSort(arr,q+1,end);
    }
}