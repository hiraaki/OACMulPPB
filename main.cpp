#include<iostream>
using namespace std;

//somabinaria
void sumar(int A[128],int B[128],int bits){
    int acarreo=0;
    int suma;
    int m=bits;
    for(int i=0;i<m;i++){
        suma=A[m-(1+i)]+B[m-(1+i)]+acarreo;
        if(suma==0){
            A[m-(1+i)]=suma;
            acarreo=0;
        }
        if(suma==1){
            A[m-(1+i)]=suma;
            acarreo=0;
        }
        if(suma==2){
            A[m-(1+i)]=(suma-2);
            acarreo=1;
        }
        if(suma==3){
            A[m-(1+i)]=(suma-2);
            acarreo=1;
        }
    }
}
//conversão
int tobinary(int N,int A[128]){
    int aux[128];
    int i=0;
    int bits;
    if(N<0)
        N=N*(-1);
    do{
        aux[i]=N%2;
        N=N/2;
        i++;
    }while(N!=0);
    bits = i;
    for(i=0;i<=bits;i++)
        A[i]=0;

    for(i=0;i<bits;i++){
        A[i]=aux[bits -1-i];
    }
    return bits;
}

//Conversão negativos
int tobinaryN(int N,int A[128]){
    int aux[128];
    int bits;
    int n;
    if(N<0)
        n=N*(-1);

    bits=tobinary(n,aux);
    for(int i=0;i<bits;i++){
        cout<<aux[i];
    }
    cout<<endl;
    bits+=1;
    for(int i=1;i<=bits;i++){
        if(aux[i-1]==0){
            A[i]=1;
        }else{
            A[i]=0;
        }
    }
    for(int i=0;i<bits-1;i++){
        aux[i]=0;
    }
    cout<<endl;
    aux[bits-1] = 1;
    sumar(A,aux,bits);
    if(N<0)
        A[0]=1;
    else
        A[0]=0;

    return bits;
}

//int *both(int *mdo_01, int *mdo_01, int mdr, int bytes){
//
//    for(int i=0;i<bytes;i++){
//
//    }
//}

//***************************PROGRAMA PRINCIPAL******************//
int main(){
    int mdo,mdr;
    cout<<endl<<"\t\t\tALGORITMO DE BOOTH";
    cout<<endl<<endl<<" ->> MULTIPLICANDO  :";
    cin>>mdo;
    cout<<endl<<" ->> MULTIPLICADOR  :";
    cin>>mdr;

    int mdo_01[128];
    int mdr_01[128];
    int bites;
    int bites1;
    int bites2;
    bites1=tobinary(mdo,mdo_01);
    bites2=tobinary(mdr,mdr_01);
    for(int i=0;i<bites1;i++){
        cout<<mdo_01[i];
    }
    cout<<endl;
    for(int i=0;i<bites1;i++){
        cout<<mdr_01[i];
    }
    cout<<endl;
    if(bites1>bites2)
        bites=bites1;
    else
        bites=bites2;

    int aux[128];
    if(bites==bites2){
        for(int i=0;i<bites1;i++){
            aux[i-1-bites1]=mdr_01[i];
        }
        for (int i = bites1; i < bites; ++i) {
            if(mdr<0){
                mdr_01[bites1]=1;
            } else{
                mdr_01[bites1]=0;
            }
        }
        for(int i=0;i<bites1;i++){
            mdr_01[i-1-bites1]=aux[i];
        }
    } else {
        for(int i=0;i<bites1;i++){
            aux[i-1-bites1]=mdr_01[i];
        }
        for (int i = bites2; i < bites; ++i) {
            if(mdo<0){
                mdo_01[bites1]=1;
            } else{
                mdo_01[bites1]=0;
            }
        }
        for(int i=0;i<bites1;i++){
            mdr_01[i-1-bites1]=aux[i];
        }
    }
    sumar(mdo_01,mdr_01,bites);
    for(int i=0;i<bites;i++){
       cout<<mdo_01[i];
    }

return 0;
}