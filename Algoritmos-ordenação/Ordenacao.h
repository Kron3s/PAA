#ifndef _ORDENACAO_H_
#define _ORDENACAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *fp , int *sp);
int partition(int *arr, int begin, int end, long  int conta[]);

void BubbleSort(int vetor[], int n, long int conta[]);
void SelectSort(int vetor[], int n, long  int[]);
void InsertSort(int vetor[], int n, long int[]);
void MergeSort(int vet[], int inicio, int fim, long  int conta[]);
void merge(int vet[], int inicio, int m, int fim, long  int conta[]);
void quickSort(int arr[], int begin, int end, long int conta[]);

void Preenche(int arr[], int n, int op);
void menu();
double Escolhe(int arr[], int n, int op, long  int conta[]);
void resultado(double cptime, long int conta[], int ordenacao, int tipo, int length);
void teste(int ordem, int tipo, int n);

#endif