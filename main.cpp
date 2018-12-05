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
int somar(int A[128],int B[128],int bits){
    int ac=0;
    int soma;
    int resp[128];
    emptyArray(resp,128);
//    printBinryStr(bits[0],A);
//    printBinryStr(bits[0],B);
//    cout<<bits[0];
    for(int i=0;i<bits;i++){
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
        return 1;
    } else{
        return 0;
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
    int ac= somar(A,um,bits);
    if(ac==1){
        bits++;
        A[bits+1]=1;
    }
    bits++;
    A[bits-1]=1;

    return  bits;
}
void alin(int A[128],int bites,int alingto) {
    int subs;
//    printf("\n%d\n",A[bites-1]);
//    printBinryStr(bites,A);
    if (A[bites-1]==0)
        subs = 0;
    else
        subs =1;

    for (int i = bites; i < alingto; i++) {
        A[i]=subs;
    }
//    printf("\n");
//    printBinryStr(alingto,A);
//    printf("\n\n");
}

int shift1R(int *bits,int n){
    int out=bits[0];
    if(bits[n-1]==0){
        bits[n]=0;
    } else{
        bits[n]=1;
    }
    for(int i=0;i<n;i++){
        bits[i]=bits[i+1];
    }

    return out;
}



int both(int *mdo_p, int *mdo_n, int *mdr, int bits){
    int ac[128];
    emptyArray(ac,128);
    int mdoPMU=0; //multiplicando Posição Menos Um
    int a=bits/2;
    for(int i=0;i<bits;i++){
        cout<<" ";
        if(i==a)
            cout<<"AC";
    }

    cout<<"\t\t";//espacio
    for(int i=0;i<bits;i++){
        cout<<" ";
        if(i==a)
            cout<<"Q";
    }
    cout<<"\t\tQ-1"<<"\tOP"<<"\tCOUNT"<<endl;


    for(int i=0;i<bits;i++){
        if((mdr[0]==0)&&(mdoPMU==1)){
            printBinryStr(bits,ac);
            printf("\t");
            printBinryStr(bits,mdr);
            printf("\t");
            printf("%d\tADD\n",mdoPMU);
            printBinryStr(bits,mdo_p);
            printf("\n");
            somar(ac,mdo_p,bits);
            for(int j=0;j<bits;j++)
                printf("-");
            printf("\n");

        } else if((mdr[0]==1)&&(mdoPMU==0)){
            printBinryStr(bits,ac);
            printf("\t");
            printBinryStr(bits,mdr);
            printf("\t");
            printf("%d\tSUB\n",mdoPMU);
            printBinryStr(bits,mdo_p);
            printf("\n");
            somar(ac,mdo_n,bits);
            for(int j=0;j<bits*2;j++)
                printf("-");
            printf("\n");

        }
        printBinryStr(bits,ac);
        printf("\t");
        printBinryStr(bits,mdr);
        printf("\t");
        printf("%d\tSHIFT\t%d\n",mdoPMU,i+1);


        int aux = shift1R(ac,bits);
        mdoPMU = shift1R(mdr,bits);
        mdr[bits-1]=aux;

        printBinryStr(bits,ac);
        printf("\t");
        printBinryStr(bits,mdr);
        printf("\t");
        printf("%d\t\n",mdoPMU);
        printf("\n\n");



    }
    printf("Resultado:");
    printBinryStr(bits,ac);
    printBinryStr(bits,mdr);

}

int main(){
    int mdo,mdr;
    cout<<endl<<"\t\t\tALGORITMO DE BOOTH";
    cout<<endl<<endl<<" ->> MULTIPLICANDO  :";
    cin>>mdo;
    cout<<endl<<" ->> MULTIPLICADOR  :";
    cin>>mdr;

    int mdo_bp[128];
    int mdo_bn[128];
    int mdr_b[128];
    int bites;

    int bitesmdo;
    int bitesmdr;


    if(mdo>=0){
        bitesmdo=tobinary(mdo,mdo_bp);
        mdo_bp[bitesmdo]=0;
        bitesmdo++;
        //printBinryStr(bitesmdr,mdr_bp);

        bitesmdo=tobinaryN(mdo,mdo_bn);


    }else{
        int aux=mdo;
        mdo=mdo*-1;

        bitesmdo=tobinary(mdo,mdo_bn);
        mdo_bn[bitesmdo]=0;
        bitesmdo++;
       // printBinryStr(bites,mdr_bn);

        bitesmdo=tobinaryN(mdo,mdo_bp);
        //printBinryStr(bites,mdr_bp);
        mdo=aux;

    }

    if(mdr>=0){
        bitesmdr=tobinary(mdr,mdr_b);
        mdr_b[bitesmdr]=0;
        bitesmdr++;

    } else{
        int aux=mdr;
        mdr=mdr*-1;
        bitesmdr=tobinaryN(mdr,mdr_b);
        mdr=aux;

    }

    printf("Mutiplicando(+M):");
    printBinryStr(bitesmdo,mdo_bp);
    printf("\n");
    printf("Mutiplicando(-M):");
    printBinryStr(bitesmdo,mdo_bn);
    printf("\n");
    printf("Muntiplicandor(Q):");
    printBinryStr(bitesmdr,mdr_b);
    printf("\n");

    if(bitesmdo>=bitesmdr){
        bites=bitesmdo;
        alin(mdr_b,bitesmdr,bites);
    } else if(bitesmdr>bitesmdo){
        bites=bitesmdr;
        alin(mdo_bp,bitesmdo,bites);
        alin(mdo_bn,bitesmdo,bites);
    }

    printf("Mutiplicando(+M):");
    printBinryStr(bites,mdo_bp);
    printf("\n");
    printf("Mutiplicando(-M):");
    printBinryStr(bites,mdo_bn);
    printf("\n");
    printf("Muntiplicandor(Q):");
    printBinryStr(bites,mdr_b);
    printf("\n");

    both(mdo_bp,mdo_bn,mdr_b,bites);

    int res = mdo*mdr;
    printf("\n%d * %d = %d =",mdo,mdr,res);
    int res_b[128];
    int bitesres=0;
    if(res>=0){
        bitesres=tobinary(res,res_b);
    } else{

        bitesres=tobinaryN(res*-1,res_b);
    }
    printBinryStr(bitesres,res_b);
    cout<<endl;



return 0;
}