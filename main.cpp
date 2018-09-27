#include<iostream>
using namespace std;

//somabinaria
void sumar(int A[128],int B[128],int bits)
{
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
    if(N<0)
        N=N*(-1);

    bits=tobinary(N,aux);
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
    for(int i=0;i<bits;i++)
        cout<<A[i];

    cout<<endl;

    for(int i=0;i<bits-1;i++){
        aux[i]=0;
    }
    cout<<endl;
    aux[bits-1] = 1;
    sumar(A,aux,bits);
    if(A[0]==0)
        A[0]=1;

    return bits;
}

//*******************SUMA DOS NUMEROS EN BINARIO*******************//
void sumar(int A[128],int B[128],int bits){
    int acarreo=0;
    int suma;
    int m=bits;
    for(int i=0;i<m;i++){
        suma=A[m-(1+i)]+B[m-(1+i)]+acarreo;
        if(suma==0){
            A[m-(1+i)]=suma;
            acarreo=0;
        } else if(suma==1){
            A[m-(1+i)]=suma;
            acarreo=0;
        } else if(suma==2){
            A[m-(1+i)]=(suma-2);
            acarreo=1;
        } else if(suma==3){
            A[m-(1+i)]=(suma-2);
            acarreo=1;
        }

    }
}

//***************************PROGRAMA PRINCIPAL******************//
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
        cout<<endl<<" ->> MULTIPLICADOR  :";
        cin>>mdr;



//*******MUESTRA EL VALOR DEL MDO DEPENDIENDO DEL SIGNO***********//
        int b;
        if(mdo<0){
            b=tobinary(mdo,MDO_10);
            bits1=tobinaryN(mdo,MDO_01);
            if(b>bits1)
                bits1=b;
        }else{
            b=tobinary(mdo,MDO_01);
            bits1=tobinaryN(mdo,MDO_10);
            if(b>bits1)
                bits1=b;
        }

        if(mdr<0){
            bits2 =tobinaryN(mdr,MDR);

        }else {
            bits2 = tobinary(mdr, MDR);
        }

        if(bits1>bits2)
            bits=bits1;
        else
            bits=bits2;

        bits=bits+1;


        cout<<endl<<endl<<endl<<" ->> MULTIPLICANDO  :";
        for(int i=0;i<bits;i++){
            if(i>bits1){
                MDO_01[i]=0;
                MDO_10[i]=1;
            }
            if(mdo<0){
                cout<<MDO_10[i];
            } else {
                cout<<MDO_01[i];
            }
        }

        cout<<endl<<endl<<" ->> MULTIPLICADOR  :";
        for(int i=0;i<bits;i++)
            cout<<MDR[i];

        // AC <- 0
        for(int i=0;i<bits;i++)
            AC[i]=0;

        //Cabeçalho
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
        cout<<"    SI";//espacio
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

                }else if(MDR[bits-1]==1 && QN==0){

//**********CASO CUANDO LOS BITS SON 1 Y 0*************//

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
        int mc=0;
        mult=mdr*mdo;
        if(mult<0)
            mc=tobinaryN(mult,MULT);
        else
            mc=tobinary(mult,MULT);
        cout<<"->>>  "<<mdo<<" * "<<mdr<<" = "<<mdo*mdr<<" = ";
        for(int i=0;i<mc;i++)
            cout<<MULT[i];
        cout<<endl<<endl;
    return 0;
}