#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Ordenacao.h"

//funcao  para trocar as posições #

 void swap(int *fp , int *sp){
    int aux;
    aux = *fp;
    *fp = *sp;
    *sp = aux;
    }
    ///funçao auxilar do quicksort que faz a partição do vetor
    int partition(int *arr,int begin,int end, long int conta []){
        int i;
        int p;
        int firsthigh;
        p = end;
        firsthigh = begin;
        for(i = 1;i< end;i++){
            conta[0]++;
          if(arr[i]< arr[p]){
              conta[1]++;
              swap(&arr[i],&arr[firsthigh]);
              firsthigh++;
          }
        

        }
        conta[1]++;
        swap(&arr[p],&arr[firsthigh]);
        return (firsthigh);

        }
        
// funcao auxilar do mergesort, junta dois sub vetores do vet[]
 void  merge(int vet[],int inicio,int m,int fim,long int conta[]){
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
        conta[1]++;
    }else{
        vet[k] = R[j];
        j++;
        conta[1]++;
    }
    conta[0]++;
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

void BubbleSort(int vetor[],int n,long  int conta[]){
    int i,j;
   
    for(i = 0;i < n ; i++){
        for(j = n-1;j>= (i+1);j--) { 
            conta[0]++;
            if(vetor[j]<vetor[j-1]){
            swap(&vetor[j],&vetor[j-1]);
             conta[1]++;
            }
        }
    }
}

void SelectSort(int vetor[],int n,long int conta[]){
    int i, j , small;
    for(i = 0 ;i<n;i++){
        small = i;
        for(j = i+1;j <n;j++){
            conta[0]++;
            if(vetor[j] < vetor[small]){
                swap(&vetor[j],&vetor[small]);
                conta[1]++;
            
            }  
        }
    }
}

void InsertSort(int vetor[],int n,long int conta[]){
    int i,j,key;
    for(j =1;j <n;j++){
        key = vetor[j];
        i = j-1;
        conta[0]++;
        while(i>=0 && vetor[i] > key){
            vetor[i+1] = vetor[i];
            i = i-1;
            conta[1]++;
        }
        vetor[i+1] = key;
    }
}

void MergeSort(int vet[],int inicio,int fim,long int conta[]){
        if(inicio <fim){
            int m  =inicio+(fim-inicio)/2;
            
            MergeSort(vet,inicio,m,conta);
            MergeSort(vet,m+1,fim,conta);
            
            merge(vet,inicio,m,fim,conta);
    

        }
    
}

void quickSort(int arr[],int left,int right,long  int conta []){
    
        int i, j, x, y;

        i = left;
        j = right;
        x = arr[(left + right) / 2];

        while (i <= j)
        {
            while (arr[i] < x && i < right)
            {
                i++;
            }
            while (arr[j] > x && j > left)
            {
                j--;
            }
            if (i <= j)
            {
                y = arr[i];
                arr[i] = arr[j];
                arr[j] = y;
                i++;
                j--;
                conta[1]++;
            }
            conta[0]++;
        }

        if (j > left)
        {
            quickSort(arr, left, j,conta);
        }
        if (i < right)
        {
            quickSort(arr, i, right,conta);
        }
    }

    //cria vetor ordenado
    void InsereVetorOrdenado(int *arr, int n)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
}
// cria vetor invertido exp: 100,99,98,97...
void InsereVetorInverso(int *arr,int n){
    int i;
    for(i =n-1 ;i>=0;i--){
        arr[i]=n-i;
    }
}
// cria vetor desordenado
void Insere_desordenado(int *arr,int n){
    int i;
    srand(time(NULL));
    for(i = 0;i<n;i++){
        arr[i] = rand()%1000;
    }
}
// funcao para escolher qual dos algoritmos de ordenaçao usar
double Escolhe(int arr[],int n,int op,long  int conta[]){
    clock_t start,end;
    double cpu_time;
   start = clock();
    switch(op){
        case 1:        BubbleSort(arr,n,conta);
                        break;
        case 2:        SelectSort(arr,n,conta);
                        break;
        case 3:        InsertSort(arr,n,conta);                 
                        break;
        case 4:        MergeSort(arr,0,(n-1),conta);
                        break;

        case 5:        quickSort(arr,0,(n-1),conta);
                        break;
        default :      printf("opcao invalida\n");                        


    }

    end = clock();
    cpu_time = ((double)(end - start))/CLOCKS_PER_SEC;
    //printf("o tempo de execução foi: %f\n ", cpu_time);
   // printf("quantidade de comparacao %d\n",conta[0]);
   return cpu_time;
}
//funcao para escolhar o tipo do vetor : ordenado,desordenado,invertido
void Preenche(int arr[], int n, int op){
     switch(op){
         case 1:    InsereVetorOrdenado(arr,n); break;

         case 2:    Insere_desordenado(arr,n); break;

         case 3:    InsereVetorInverso(arr,n); break;
         
         default:   printf("opicao invalida\n");
     }   

}

// op1 é o algoritmo escolhido , op2 é o é tipo do vetor escolhido
void teste(int ordem,int tipo, int n){
   // printf("entrou no teste");
    int vet[n];
   long  int conta[2];  // conta[0] comparações  conta[1] trocas
    conta[0] =0;
    conta[1] = 0;
    double cpu_time ;
    Preenche(vet, n, ordem);
   // int j;
    /*if (n <= 100)
    {
        for (j = 0; j < n; j++)
            printf("%d\n", vet[j]);
    }*/
    //puts("\n");
    cpu_time = Escolhe(vet, n, tipo, conta);
    
   /*  if (n <= 100)
    {
        for (j = 0; j< n; j++)
            printf("%d\n", vet[j]);
    }*/
    //printf("tempo de cpu %lf",cpu_time);
    resultado(cpu_time,conta,ordem,tipo,n);

}
    

void resultado(double cptime, long  int conta[],  int ordenacao,int tipo,int length){
   char algoritmo[100];
   char ordem[100];
   char filename[200];
   strcpy(filename, "");
   switch(tipo){
       case 1: strcpy(algoritmo,"BubbleSort");
                break;
       
       case 2:
                  strcpy(algoritmo, "SelectSort");
           break;
       case 3:
           strcpy(algoritmo, "InsertSort");
            break;
       case 4:
           strcpy(algoritmo, "MergeSort");
           break;

       case 5:
           strcpy(algoritmo, "QuickSort");
            break;
       default: puts("opcao invalida");     
           
   }
   

   switch (ordenacao)
   {
   case 1:
       strcpy(ordem, "/resultado/ordenado/");
       break;
      

    case 2 : strcpy(ordem, "/resultado/desordenado/");
       break;
   case 3:
       strcpy(ordem, "/resultado/decrescente/");
       break;
   default:
       puts("opcao invalida");
                  
}


strcat(filename,ordem);
strcat(filename,algoritmo);

//printf("%s\n",);
// tempo de execução
char file_time[200];
char cwd[1024];
getcwd(cwd,sizeof(cwd));

strcpy(file_time,"");
strcpy(file_time,cwd);
strcat(file_time,filename);
strcat(file_time,"Time.txt");

//printf("%s\n",file_time);

FILE *ft  = fopen(file_time,"a+");
if(ft != NULL){
   
   fprintf(ft, "%d\t %lf\n", length, cptime);
    
}
fclose(ft);
//printf("%s\n", file_time);
//comparacao e trocas
char file_trocas[200];
strcpy(file_trocas,"");
strcpy(file_trocas,cwd);
strcat(file_trocas, filename);
strcat(file_trocas, "TrocasComparacao.txt");
//printf("%s",file_trocas);
char aux2[100];
FILE * ftc = fopen(file_trocas, "a+");
if(ftc != NULL){
    fgets(aux2,100,ftc);
    if(strcmp(aux2,"#comparacoes\t trocas\n")!=0)
        fprintf(ftc, "#comparacoes\t trocas\n");
    fprintf(ftc," %d\t %ld\t %ld\n",length,conta[0],conta[1]);
}
fclose(ftc);

}  

void menu(){

 int ordem;
 int metodo;
 int op;
 printf("######################################\n");
 printf("|1 testa os algoritmos |2  Graficos do cpu-time |3 Graficos de Comparacoes |4 Grafico de Trocas \n");
 scanf("%d",&op);
switch(op){

case 1:
printf("escolha o tipo do vetor: 1:Ordenado |2: Desordenado |3:Decrescente\n");
scanf("%d",&ordem);
printf("\nescolha o metodo de ordenação: 1: BubbleSort|2: SelectSort |3: InsertSort|4: MergeSort|5: QuickSort\n");

scanf("%d",&metodo);
puts("\n");
//printf("depois de pegar o valor %d",metodo);
 // para contar a quantidade de comparações 
// para contar as trocas
//Preenche(array,n,op1);
//Escolhe(array,n,op2,conta);

teste(ordem,metodo,100);
teste(ordem,metodo,500);
teste(ordem,metodo,1000);
teste(ordem,metodo,2000);
teste(ordem,metodo,3000);
teste(ordem,metodo,5000);
teste(ordem,metodo,10000);
teste(ordem,metodo,20000);
teste(ordem,metodo,30000);
teste(ordem,metodo,50000);
teste(ordem,metodo,100000);
teste(ordem,metodo,200000);
teste(ordem,metodo,300000);
teste(ordem,metodo,500000);
teste(ordem,metodo,1000000);
break;

case 2: 
    system("gnuplot-x11 -p scripts/timeOrdenado.gp ");
    system("gnuplot-x11 -p scripts/timeRandom.gp ");
    system("gnuplot-x11 -p scripts/timeDecrescente.gp ");
    break;

case 3:
    system("gnuplot-x11 -p scripts/comparacao-Ordenado.gp ");
    system("gnuplot-x11 -p scripts/comparacao-Random.gp ");
    system("gnuplot-x11 -p scripts/comparacao-Decrescente.gp ");
    break;
case 4:
    system("gnuplot -p scripts/trocas-Ordenado.gp ");
    system("gnuplot -p scripts/trocas-Random.gp ");
    system("gnuplot -p scripts/trocas-Decrescente.gp ");
    break;
  default:  puts("opcao invalida");  
  }
}

 


 


