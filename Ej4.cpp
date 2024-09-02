#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void cantVocales(Lista<char> &lista1, char v){
    int contador=0, tamanio=lista1.getTamanio();

    for(int i=0; i<tamanio; i++){
        if(lista1.getDato(i)==v){
            contador++;
        }
    }
    cout<<"La vocal "<<v<<" se repite "<<contador<<" veces en la palabra"<<endl;

}

int main(){
    Lista<char> lista1;
    string palabra;
    char v;

    cout<<"Ingrese una palabra: ";
    getline(cin, palabra);

    // Convertir la palabra a minúsculas
    for(int i=0; i<palabra.length(); i++){
        palabra[i]=tolower(palabra[i]);
    }
    
     for (char c : palabra) {
      lista1.insertarUltimo(c);
    } 

    do{
    cout<<"Ingrese la vocal de la cual desea saber cuantas veces se repite en la palabra: ";
    cin>>v;
    v=tolower(v);
    if(v != 'a' && v != 'e' && v != 'i' && v != 'o' && v != 'u'){
        cout<<"La vocal ingresada no es valida"<<endl;
      } 
    }while(v != 'a' && v != 'e' && v != 'i' && v != 'o' && v != 'u');

  cout<<"La lista es: ";
  lista1.print();
  cantVocales(lista1, v);

}

