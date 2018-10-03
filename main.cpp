#include<iostream>
using namespace std;

//conversão
int tobinary(int N,int A[128]){
    int bits=0;
    int aux[128];
    while (N!=0){
        aux[bits]=N%2;
        N=N/2;
        bits++;
    }
    for(int i=0;i<bits;i++){
        A[127-i]=aux[i];
    }
    return bits;
}
//somabinaria
void sumar(int A[128],int B[128],int *bits){
    int ac=0;
    int soma;
    int m=*bits;
    for(int i=127;i>=128-m;i--){
        soma=A[i]+B[i]+ac;
        cout<<ac<<" "<<A[i]<<" "<<B[i]<<" "<<soma<<endl;
        if(soma==0){
            A[i]=soma;
            ac=0;
        }
        if(soma==1){
            A[i]=soma;
            ac=0;
        }
        if(soma==2){
            A[i]=0;
            ac=1;
        }
        if(soma==3){
            A[i]=1;
            ac=1;
        }
    }
    if(ac==1){
        *bits=*bits+1;
        A[128-(*bits)]=1;
    }
}
//Conversão negativos
int tobinaryN(int N,int *A){
    int bits=0;
    bits=tobinary(N,A);
    for(int i=128-bits;i<128;i++){
        if(A[i]==0)
            A[i]=1;
        else
            A[i]=0;

    }

    int um[128];
    for(int i=128-bits;i<128;i++){
        if(i!=127)
            um[i]=0;
        else
            um[i]=1;
    }
    int *bitsp=&bits;
    sumar(A,um,bitsp);
    bits++;
    A[128-bits]=1;
    for(int i=128-bits;i<128;i++)
        cout<<A[i];
    cout<<endl;
    return  bits;
}
void alin(int A[128],int bites_01,int bites_10, bool maior0){
    for(int i=128-bites_01;i>128-bites_10;i--){
        if(maior0)
            A[i]=0;
        else
            A[i]=1;
    }
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
    int *bitesp;
    int bites1;
    int bites2;
    bites1=tobinary(mdo,mdo_01);
    bites2=tobinaryN(mdr,mdr_01);

//    for(int i=128-bites1;i<128;i++){
//        cout<<mdo_01[i];
//    }
//    cout<<endl;
//    for(int i=128-bites2;i<128;i++){
//        cout<<mdr_01[i];
//    }
//    cout<<endl;
    if(bites1>bites2){
        bites=bites1;
        if(mdr>0){
            alin(mdr_01,bites2,bites*2, true);
        } else{
            alin(mdr_01,bites2,bites*2, false);
        }
    }else if(bites2>bites1){
        if(mdo<0){
            alin(mdo_01,bites2,bites*2, true);
        } else{
            alin(mdo_01,bites2,bites*2, false);
        }
    }
    for(int i=128-bites*2;i<128;i++){
        cout<<mdo_01[i];
    }
    for(int i=128-bites*2;i<128;i++){
        cout<<mdr_01[i];
    }
    bites=bites*2;
    sumar(mdo_01,mdr_01,&bites);
    for(int i=128-bites;i<128;i++){
        cout<<mdo_01[i];
    }

return 0;
}