#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void intercambiarLista(Lista<int> &lista1, Lista<int> &lista2){
    int tamanio1=lista1.getTamanio();
    int tamanio2=lista2.getTamanio();
    int aux;
    
    if(tamanio1==tamanio2){
        for(int i=0;i<tamanio1;i++){
            aux=lista1.getDato(i);
            lista1.remover(i);
            lista1.insertar(i,lista2.getDato(i));
            lista2.remover(i);
            lista2.insertar(i,aux);
        }
    }else{
            if(tamanio1 > tamanio2){
                for(int i = tamanio2; i < tamanio1; i++){
                    lista2.insertar(i, 0);
                    aux=lista1.getDato(i);
                    lista1.remover(i);
                    lista1.insertar(i,lista2.getDato(i));
                    lista2.remover(i);
                    lista2.insertar(i, aux);
                }
            } else if(tamanio2 > tamanio1){
                for(int i = tamanio1; i < tamanio2; i++){
                    lista1.insertar(i, 0);
                    aux=lista2.getDato(i);
                    lista2.remover(i);
                    lista2.insertar(i,lista1.getDato(i));
                    lista1.remover(i);
                    lista1.insertar(i,aux);

                }
            }

          
        }  
}   

int main() {

    Lista<int> Lista1;
    Lista<int> Lista2;
    int n,d;

    cout<<"Ingrese el tamanio de la lista 1: "<<endl;
    cin>>n;

    cout<<"Ingrese los valores de la lista: "<<endl;
    for(int i=0;i<n;i++){
        cin>>d;
        Lista1.insertarUltimo(d);
    }

    cout<<"Ingrese el tamanio de la lista 2: "<<endl;
    cin>>n;

    
    cout<<"Ingrese los valores de la lista: "<<endl;
    for(int i=0;i<n;i++){
        cin>>d;
        Lista2.insertarUltimo(d);
    }

    cout<<"Las listas originales son: "<<endl;
    Lista1.print();
    Lista2.print();

    intercambiarLista(Lista1,Lista2);

    cout<<"Las listas modificadas son: "<<endl;
    Lista1.print();
    Lista2.print();
}
