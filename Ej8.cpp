/*Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista circular simplemente enlazada.
Requisitos:
1. Frases de Anuncios:
○ Cada frase de anuncio será un texto simple que el monitor debe mostrar por
vez.
2. Mostrar Circularmente:
○ Las frases deben mostrarse en un formato circular, es decir, una vez que se ha
mostrado la última frase, el monitor debe volver a mostrar la primera y así
infinitamente.
3. Implementación:
○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
y la visualización de las frases. La lista circular debe permitir el recorrido
continuo de los elementos.
4. Operaciones Básicas:
○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
○ Mostrar Frases: Implementa una función para mostrar las frases en el monitor
de manera continua, recorriendo circularmente la lista e infinitamente.
*/


#include <iostream>
#include <thread>
#include <chrono>
#include "Lista/CircList.h"
using namespace std;

void mostrarFrase(CircList<string> &lista1){
  
    if(lista1.esVacia())
    {
        cout << "No hay frases" << endl;
        return;
     }

    int tamanio=lista1.getTamanio();
    int i=0;
    while(true){
      cout<<lista1.getDato(i)<<endl;
      i++;
      if(i==tamanio){
        i=0;
      }
      this_thread::sleep_for(chrono::milliseconds(1000));
    }
        cout<<lista1.getDato(i)<<endl;
        i++;
        if(i==tamanio){
            i=0;
        }
    }


void agregarFrase(CircList<string> &lista1, string frase){
    lista1.insertarUltimo(frase);
}

int main(){
    CircList<string> lista1;
    string frase;
    int opcion;

    do{
        cout<<"1. Agregar frase"<<endl;
        cout<<"2. Eliminar frase"<<endl;
        cout<<"3. Mostrar frases (no se podran agregar frases nuevas)"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese la frase que desea agregar: ";
                cin.ignore();
                getline(cin, frase);
                agregarFrase(lista1, frase);
                break;
            case 2:
                cout<<"Ingrese la frase que desea eliminar: ";
                cin.ignore();
                getline(cin, frase);
                lista1.eliminarPorValor(frase);
                break;
            case 3:
                mostrarFrase(lista1);
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(opcion<4);
}

