/*Desarrolla un programa que simule el historial de páginas web visitadas en un navegador
utilizando una lista doblemente enlazada. El programa debe permitir al usuario retroceder y
avanzar entre las páginas visitadas, mostrando sus direcciones en pantalla.
Requisitos:
1. Estructura de Datos:
○ Usa el concepto de una lista doblemente enlazada para mantener el historial de
páginas web visitadas.
○ Cada nodo de la lista debe almacenar la URL de la página web visitada.
2. Funciones del Programa:
○ Añadir Página: Permite agregar una nueva URL al final del historial de
navegación.
○ Mostrar Histórico: Muestra todas las URLs del historial desde la más antigua a la
más reciente.
○ Retroceder: Permite al usuario retroceder a la página web visitada
anteriormente, mostrando la URL en pantalla.
○ Avanzar: Permite al usuario avanzar a la siguiente página web en el historial,
mostrando la URL en pantalla.
3. Interfaz del Usuario:
○ La interfaz debe ser de línea de comandos y debe permitir al usuario ingresar
URLs y navegar a través del historial usando comandos simples.
○ Implementa un menú para que el usuario pueda elegir entre las opciones
disponibles: añadir una página, mostrar el historial, retroceder, avanzar, y salir
del programa.
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "Lista/ListaDoble.h"
using namespace std;

void mostrarHistorial(ListaDoble<string> &lista1){
    if(lista1.esVacia())
    {
        cout << "No hay paginas en el historial" << endl;
        return;
    }
    cout<<"Historial de paginas visitadas: "<<endl;
    lista1.imprimir();
}
void MostrarPaginaActual(ListaDoble<string> &lista1, int pos){
    if(pos>=0 && pos<lista1.getTamanio()){
        cout<<"Pagina actual: "<<lista1.getDato(pos)<<endl;
    }else{
        cout<<"No hay paginas en el historial"<<endl;
    }
}

void retroceder(ListaDoble<string> &lista1, int &pos){
    if(pos>0){
    pos--;
    MostrarPaginaActual(lista1,pos);
    }else{
        cout<<"No hay paginas anteriores en el historial"<<endl;
    }
}

void avanzar(ListaDoble<string> &lista1, int &pos){
    if(pos>=0 && pos<lista1.getTamanio()-1){
    pos++;
    MostrarPaginaActual(lista1,pos);
    }else{
        cout << "No hay paginas siguientes en el historial." <<endl;
    }
}

void agregarPagina(ListaDoble<string> &lista1, string pagina){
    lista1.insertarUltimo(pagina);
}

int main(){
    ListaDoble<string> lista1;
    string pagina;
    int opcion, pos=-1;

    do{
        cout<<"1. Agregar pagina"<<endl;
        cout<<"2. Mostrar historial"<<endl;
        cout<<"3. Retroceder"<<endl;
        cout<<"4. Avanzar"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"Ingrese la pagina: ";
                cin>>pagina;
                agregarPagina(lista1, pagina);
                break;
            case 2:
                mostrarHistorial(lista1);
                break;
            case 3:
                retroceder(lista1, pos);
                break;
            case 4:
                avanzar(lista1, pos);
                break;
            case 5:
                cout<<"Saliendo del programa"<<endl;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
    }while(opcion!=5);
}




