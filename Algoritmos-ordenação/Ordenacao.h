#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

#include <stdio.h>
#include<stdlib.h>

void swap(int *fp , int *sp);
int partition(int *arr,int begin,int end);

void BubbleSort(int [],int);
void SelectSort(int vetor[],int n);
void InsertSort(int vetor[],int n);
void MergeSort(int vet[],int inicio,int fim);
int merge(int vet[],int inicio,int m,int fim);
void quickSort(int arr[],int begin,int end);




























#endif