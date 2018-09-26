#include<iostream>
using namespace std;

//*******************FUNCION PARA NUMERO POSITIVO A BINARIO********//
void binariopos(int N,int A[128],int n){
    int aux[128];
    int i=0,j=0;
    int bits;
    //ALMACENA EL REIDUO EN EL VECTOR AUX
    if(N<0)
        N=N*(-1);
    do{
        aux[i]=N%2;
        N=N/2;
        i++;
    }while(N!=0);
    bits=i;
//Pasa los elementos del vector aux al vector A
    for(i=0;i<bits;i++)
        A[i]=aux[i];

    for(i=bits;i<n;i++)
        A[i]=0;

    for(int i=n-1;i>=0;i--){
        aux[j]=A[i];
        j++;
    }

    for(int i=0;i<n;i++)
        A[i]=aux[i];
}
//*****************************************************************//

//*******************FUNCION PARA NUMERO NEGATIVO A BINARIO********//
void binarioneg(int N,int A[128],int n){
    int aux[128];
    int i=0,j=0;
    int bits;
    int N1=N;
    if(N<0)
        N=N*(-1)-1;
    else
        N=N-1;
// ALMACENA EL REIDUO EN EL VECTOR AUX
    do{
        aux[i]=N%2;
        N=N/2;
        i++;
    }while(N!=0);

    bits=i;

    for(i=0;i<bits;i++)
        A[i]=aux[i];

    for(i=bits;i<n;i++)
        A[i]=0;

    for(int i=0;i<n;i++){
        if(A[i]==0)
            A[i]=1;
        else
            A[i]=0;
    }


    for(int i=n-1;i>=0;i--){
        aux[j]=A[i];
        j++;
    }
    for(int i=0;i<n;i++)
        A[i]=aux[i];

    if(N1==0)
        for(int i=0;i<n;i++)
            A[i]=0;

}


//*******************SUMA DOS NUMEROS EN BINARIO*******************//
void sumar(int A[128],int B[128],int bits){
    int acarreo=0;
    int suma;
    int m=bits;

    for(int i=0;i<m;i++)
    {
        suma=A[m-(1+i)]+B[m-(1+i)]+acarreo;

        if(suma==0)
        {
            A[m-(1+i)]=suma;
            acarreo=0;
        }

        if(suma==1)
        {
            A[m-(1+i)]=suma;
            acarreo=0;
        }

        if(suma==2)
        {
            A[m-(1+i)]=(suma-2);
            acarreo=1;
        }

        if(suma==3)
        {
            A[m-(1+i)]=(suma-2);
            acarreo=1;
        }

    }
}

//---------------------------------------------------------------//
//***************************PROGRAMA PRINCIPAL******************//
//---------------------------------------------------------------//
int main(){

        int mdo,mdr;               //*****Numeros Ingresados****//
        int MDO_10[128];           //***MDO EN BINARIO***//
        int MDO_01[128];           //***MDO EN BINARIO***//
        int MDR[128];              //***MDR EN BINARIO***//
        int Aux[128];              //**AUXILIAR PARA NUMERO BINARIO**//
        int aux1,aux2,aux;         //**AUXILIARES PARA LOS BITS**//
        int bits1=0,bits2=0,bits;  //**BITS DE CADA NUMERO**//
        int AC[128];               //*REGISTROS ACUMULADOR*//
        int QN=0;                  //*BIT ADICIONAL*//

        cout<<endl<<"\t\t\tALGORITMO DE BOOTH";
        cout<<endl<<endl<<" ->> MULTIPLICANDO  :";
        cin>>mdo;
        aux=mdo;//NUMERO DE BITS DEL MDO
        do{
            aux=aux/2;
            bits1++;
        }while(aux!=0);
        cout<<endl<<" ->> MULTIPLICADOR  :";
        cin>>mdr;
        aux=mdr;//NUMERO DE BITS DEL MDO
        do{
            aux=aux/2;
            bits2++;
        }while(aux!=0);
        //MAYOR NUMERO BITS
        if(bits1>bits2)
            bits=bits1;
        else
            bits=bits2;

        bits=bits+1;

//*******MUESTRA EL VALOR DEL MDO DEPENDIENDO DEL SIGNO***********//
        cout<<endl<<endl<<endl<<" ->> MULTIPLICANDO  :";
        if(mdo<0){
            binarioneg(mdo,MDO_01,bits);
            //*** PASO A BINARIO EL MDO_01 ***//
            for(int i=0;i<bits;i++)
                cout<<MDO_01[i];
        }
        else{
            binariopos(mdo,MDO_10,bits);
            //*** PASO A BINARIO EL MDO_10 ***//
            for(int i=0;i<bits;i++)
                cout<<MDO_10[i];
        }
//**************************************************//




//***TRUCO :MACENA EL MDO EN BINARIO DEPENDIENDO DEL SIGNO***//
        if(mdo<0){
            binariopos(mdo,MDO_10,bits);
            binarioneg(mdo,MDO_01,bits);
        }
        else{
            binariopos(mdo,MDO_01,bits);
            binarioneg(mdo,MDO_10,bits);
        }

//***MUESTRA EL VALOR DEL MDR DEPENDIENDO DEL SIGNO***********//
        cout<<endl<<endl<<" ->> MULTIPLICADOR  :";
        if(mdr<0)
            binarioneg(mdr,MDR,bits);
        else
            binariopos(mdr,MDR,bits);

        for(int i=0;i<bits;i++)
            cout<<MDR[i];

//**********LLENA EL REGISTRO ACUMULADOR DE 0**********//
        for(int i=0;i<bits;i++)
            AC[i]=0;

//**************MUESTRA TITULOS DE BOOTH*********//
        int a;
        a=bits/2;

        cout<<endl<<endl<<endl;
        cout<<"              ";
        for(int i=0;i<bits;i++){
            cout<<" ";
            if(i==a)
                cout<<"AC";
        }
        cout<<"   ";//espacio
        for(int i=0;i<bits;i++){
            cout<<" ";
            if(i==a)
                cout<<"QR";
        }
        cout<<"    QN";//espacio
        cout<<"    SC";//espacio
        cout<<endl;
        cout<<"               ";
        for(int i=0;i<bits;i++)
            cout<<"_";

        cout<<"     ";//espacio
        for(int i=0;i<bits;i++)
            cout<<"_";

        cout<<"     __";//espacio
        cout<<"    __";//espacio


//****************************DESARROLLO DE BOTH*****************//
        for(int SC=bits;SC>=0;SC--){
//****************MUESTRA DE DESARROLLO DE BOOTH**************//
            cout<<endl<<endl;
            cout<<"               ";//espacio

            for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                cout<<AC[i];
            cout<<"     ";//espacio
            for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                cout<<MDR[i];
            cout<<"     ";//espacio
            cout<<QN;
            cout<<"     ";//espacio
            cout<<SC;
            if(SC>0){
//***********CASO CUANDO LOS BITS SON IGUALES**************//
                if(MDR[bits-1]==QN){
                    //*****************ASHR*****************//
                    for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                        Aux[i]=AC[i];

                    aux1=AC[bits-1];
                    for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                        AC[i+1]=Aux[i];

                    for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                        Aux[i]=MDR[i];

                    aux2=MDR[bits-1];
                    for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                        MDR[i+1]=Aux[i];

                    MDR[0]=aux1;
                    QN=aux2;
                }
//***********CASO CUANDO LOS BITS SON 0 Y 1***********//
                else if(MDR[bits-1]==0 && QN==1){
                    //********MUESTRA LA SUMA************//
                    cout<<endl<<"             ";//espacio
                    cout<<"+ ";
                    for(int i=0;i<bits;i++)
                        cout<<MDO_01[i];
                    cout<<endl<<"               ";//espacio
                    for(int i=0;i<bits;i++)
                        cout<<"_";

                    //****SUMA DE MDO MAS AC*****//
                    sumar(AC,MDO_01,bits);

                    //********MUESTRA RESULTADO*************//
                    cout<<endl<<"               ";//espacio
                    for(int i=0;i<bits;i++)
                        cout<<AC[i];

                    //*********************************ASHR******************//
                    for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                        Aux[i]=AC[i];

                    aux1=AC[bits-1];
                    for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                        AC[i+1]=Aux[i];

                    for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                        Aux[i]=MDR[i];

                    aux2=MDR[bits-1];
                    for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                        MDR[i+1]=Aux[i];

                    MDR[0]=aux1;
                    QN=aux2;
                }

//**********CASO CUANDO LOS BITS SON 1 Y 0*************//
                else if(MDR[bits-1]==1 && QN==0){
                    //********MUESTRA LA RESTA************//
                    cout<<endl<<"             ";//espacio
                    cout<<"- ";
                    for(int i=0;i<bits;i++)
                        cout<<MDO_01[i];
                    cout<<endl<<"               ";//espacio
                    for(int i=0;i<bits;i++)
                        cout<<"_";

                    //****RESTA DE MDO MENOS AC*****//
                    sumar(AC,MDO_10,bits);

                    //********MUESTRA RESULTADO*************//
                    cout<<endl<<"               ";//espacio
                    for(int i=0;i<bits;i++)
                        cout<<AC[i];

                    //*************ASHR************//
                    for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                        Aux[i]=AC[i];

                    aux1=AC[bits-1];
                    for(int i=0;i<bits;i++)//AC CANTIDAD DE 0000000////
                        AC[i+1]=Aux[i];

                    for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                        Aux[i]=MDR[i];

                    aux2=MDR[bits-1];
                    for(int i=0;i<bits;i++)//MDR - MULTIPLICADOR///////
                        MDR[i+1]=Aux[i];

                    MDR[0]=aux1;
                    QN=aux2;
                }
            }
        }

//*********COMPROBACION DE BOOTH****************//
        cout<<endl<<endl<<endl;
        int mult,MULT[128];
        mult=mdr*mdo;
        if(mult<0)
            binarioneg(mult,MULT,2*bits);
        else
            binariopos(mult,MULT,2*bits);
        cout<<"->>>  "<<mdo<<" * "<<mdr<<" = "<<mdo*mdr<<" = ";
        for(int i=0;i<2*bits;i++)
            cout<<MULT[i];
        cout<<endl<<endl;
    return 0;
}