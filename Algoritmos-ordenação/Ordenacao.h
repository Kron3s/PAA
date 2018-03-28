#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *fp , int *sp);
int partition(int *arr,int begin,int end);

void BubbleSort(int vetor[],int n,int conta[]);
void SelectSort(int vetor[],int n,int []);
void InsertSort(int vetor[],int n,int []);
void MergeSort(int vet[],int inicio,int fim);
int merge(int vet[],int inicio,int m,int fim);
void quickSort(int arr[],int begin,int end);

void Preenche(int arr[], int n, int op);
void menu();
void Escolhe(int arr[],int n,int op,int conta[]);




























#endif