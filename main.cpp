#include<iostream>
using namespace std;

void emptyArray(int *array,int size){
//    cout<<size;
    for(int i=0;i<size;i++){
        array[i]=0;
    }
}

void printBinryStr(int n,int *a){
    for(int i=n-1;i>=0;i--){
        printf("%d ",a[i]);
    }
    printf("\n");
}

//conversão
int tobinary(int N,int A[128]){
    int bits=0;
    int aux[128];
    while (N!=0){
        A[bits]=N%2;
        N=N/2;
        bits++;
    }
    return bits;
}






//somabinaria
void somar(int A[128],int B[128],int *bits){
    int ac=0;
    int soma;
    int resp[128];
    emptyArray(resp,128);
//    printBinryStr(bits[0],A);
//    printBinryStr(bits[0],B);
//    cout<<bits[0];
    for(int i=0;i<bits[0];i++){
        soma=A[i]+B[i]+ac;
//        cout<<"AC:"<<ac<<" "<<"A:"<<A[i]<<" "<<"B:"<<B[i]<<" "<<"SOMA:"<<soma<<endl;
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
        bits[0]++;
        A[bits[0]+1]=1;
    }
}
//Conversão negativos
int tobinaryN(int N,int *A){
    int bits=0;
    bits=tobinary(N,A);
    for(int i=0;i<bits;i++){
        if(A[i]==0)
            A[i]=1;
        else
            A[i]=0;

    }
    int um[128];
    emptyArray(um,128);
    um[0]=1;

    somar(A,um,&bits);
    bits++;
    A[bits-1]=1;

    return  bits;
}
void alin(int A[128],int bites_01,int bites_10, bool maior0) {
    for (int i = 128 - bites_01; i > 128 - bites_10; i--) {
        if (maior0)
            A[i] = 0;
        else
            A[i] = 1;
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
    cin>>mdr;
    cout<<endl<<" ->> MULTIPLICADOR  :";
    cin>>mdo;

    int mdr_bp[128];
    int mdr_bn[128];
    int mdo_b[128];
    int bites;

    int bitesmdo;
    int bitesmdr;

    if(mdo>=0){
        bitesmdo=tobinary(mdo,mdo_b);
    } else{
        mdo=mdo*-1;
        bitesmdo=tobinaryN(mdo,mdo_b);
    }

    printf("Muntiplicando:");
    printBinryStr(bitesmdo,mdo_b);


    if(mdr>=0){
        int aux=0;
        aux=tobinary(mdr,mdr_bp);
        mdr_bp[aux]=0;
        aux++;
        printBinryStr(aux,mdr_bp);

        bites=tobinaryN(mdr,mdr_bn);
        printBinryStr(bites,mdr_bn);
    }else{
        mdr=mdr*-1;

        bites=tobinaryN(mdr,mdr_bp);
        printBinryStr(bites,mdr_bp);

        bites=tobinary(mdr,mdr_bn);
        mdr_bp[bites]=0;
        bites++;
        printBinryStr(bites,mdr_bn);


    }






//    bites1=tobinary(mdo,mdo_01);

//    bites2=tobinaryN(mdr,mdr_01);

//    for(int i=128-bites1;i<128;i++){
//        cout<<mdo_01[i];
//    }
//    cout<<endl;
//    for(int i=128-bites2;i<128;i++){
//        cout<<mdr_01[i];
//    }
//    cout<<endl;
//    if(bites1>bites2){
//        bites=bites1;
//        if(mdr>0){
//            alin(mdr_01,bites2,bites*2, true);
//        } else{
//            alin(mdr_01,bites2,bites*2, false);
//        }
//    }else if(bites2>bites1){
//        if(mdo<0){
//            alin(mdo_01,bites2,bites*2, true);
//        } else{
//            alin(mdo_01,bites2,bites*2, false);
//        }
//    }
//    for(int i=128-bites*2;i<128;i++){
//        cout<<mdo_01[i];
//    }
//    for(int i=128-bites*2;i<128;i++){
//        cout<<mdr_01[i];
//    }
//    bites=bites*2;
//    sumar(mdo_01,mdr_01,&bites);
//    for(int i=128-bites;i<128;i++){
//        cout<<mdo_01[i];
//    }

return 0;
}