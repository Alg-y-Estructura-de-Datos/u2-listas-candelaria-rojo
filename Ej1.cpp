#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void printLista(Lista<int> &lista, int p){

    int tamanio=lista.getTamanio();//averiguo el tamnio de la lista solo si es necesario
    
    //CONTROL
    if(p>=tamanio || p<0){
        cout<<"La posicion que ingreso es invalida"<<endl;
        return;
    }

    for(int i=p;i<tamanio;i++){
        cout<<lista.getDato(i)<<endl;
    }
    cout<<"NULL "<<endl;
}



int main() {
    Lista<int> Lista1;
    int n,d,p;

    cout<<"Ingrese el tamnio de la lista: "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingrese el valor de la lista en la posicion: "<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Ingrese la posicion que desea imprimir: "<<endl;
    cin>>p;

    printLista(Lista1,p);
}
