#include <iostream>

using namespace std;

void printLista(int *lista,int n){
    int ii;
    for (ii = 0; ii < n; ii++) {
        cout << lista[ii] << endl;
    }
}


void copyList(int *listaOriginal, int *listaDestino,int ini, int fim,int kk){
    int ii;

    for(ii=ini; ii<fim; ii++){
        listaDestino[kk] = listaOriginal[ii];
        kk++;
    }
}


void algMerge(int *B, int *C, int *A, int *B_index, int *C_index, int *A_index, int p, int q){
    int ii=0,jj=0,kk=0;
    while((ii<p)&&(jj<q)){
        if(B[ii]<=C[jj]){
            A[kk] = B[ii];
            A_index[kk] = B_index[ii];
            ii++;
        }
        else{
            A[kk] = C[jj];
            A_index[kk] = C_index[jj];
            jj++;
        }
        kk++;
    }
    if(ii==p){
        copyList(C,A,jj,q,kk);
        copyList(C_index,A_index,jj,q,kk);
    }
    else{
        copyList(B,A,ii,p,kk);
        copyList(B_index,A_index,ii,p,kk);
    }

}

// algoritmo mergesort
void mergeSort(int *A, int* A_index, int n){
    int B[100]={0}, C[100]={0},tamC=n/2;
    int B_index[100]={0}, C_index[100]={0};
    if(n%2==1)
        tamC++;
    if(n>1){
       copyList(A,B,0,n/2,0);
       copyList(A_index,B_index,0,n/2,0);
       copyList(A,C,n/2,n,0);
       copyList(A_index,C_index,n/2,n,0);

       mergeSort(B,B_index,n/2);
       mergeSort(C,C_index,tamC);

       algMerge(B,C,A,B_index,C_index,A_index,n/2,tamC);
    }
}

int findMax(int *A, int n){
    int list_index[100] = {0}, ii;
    for (ii = 0; ii < n; ii++) {
        list_index[ii] = ii;
    }
    mergeSort(A,list_index,n);
    return list_index[n-1];
}


int main()
{
    int lista[100] = {102,102,20,55,30,1,9,10,99,35};
    int tamanho_lista = 10,ii,max_index;
    max_index = findMax(lista,tamanho_lista);
    cout << max_index << endl;
    return 0;
}
