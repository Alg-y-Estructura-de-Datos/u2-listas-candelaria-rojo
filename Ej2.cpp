#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void eliminarElemento(Lista<int> &lista, int n){
    int tamanio=lista.getTamanio();//averiguo el tamnio de la lista solo si es necesario

    for(int i=0;i<tamanio;i++){
        if(lista.getDato(i)==n){
            lista.remover(i);
            i--;
            tamanio--;
        }
    }
    
}

int main() {
    Lista<int> Lista1;
    int n,d,p;

     cout<<"Ingrese el tamanio de la lista: "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingrese el valor de la lista en la posicion: "<<endl;
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"La lista orginal es: ";
    Lista1.print();

    cout<<"Ingrese el elemento que desea eliminar: "<<endl;
    cin>>p;

    eliminarElemento(Lista1,p);

    cout<<"La lista modificada es: ";
    Lista1.print();


    
}
