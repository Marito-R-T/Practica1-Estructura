/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mari2bar
 *
 * Created on 16 de febrero de 2020, 10:57
 */


#include<iostream>
#include<cpio.h>
#include<stdlib.h>
using namespace std;

/*
 * 
 */

struct DISCO1 {
    int dato;
    DISCO1*siguiente;
};

//Prototipos de Funci�n
void agregarPila(DISCO1 *&, int);
void sacarPila(DISCO1 *&, int &);


string espacio = " ";
string disco = "*";
int numerodiscos = 0;

int EscribirDiscos(DISCO1 *&ref) {
    int a;
    int& ab = a;
    DISCO1 *pivote = NULL;
    cout<<endl<<endl;
    while (ref != NULL) {
        sacarPila(ref, ab);
        for (int i = a; i < 20; i++) {
            cout << " ";
        }
        for (int i = 0; i < a * 2 - a; i++) {
            cout << disco;
        }
        if (a != 0) {
            cout << a;
        }
        for (int i = 0; i < a * 2 - a; i++) {
            cout << disco;
        }
        for (int i = a; i < 20; i++) {
            cout << " ";
        }
        cout << endl;
        agregarPila(pivote, a);
    }
    for(int i = numerodiscos; i < 16; i++){
    cout<<" ";
    }
    for(int i = 0; i < numerodiscos*2+9; i++){
    cout<<"_";
    }
    for(int i = numerodiscos; i < 16; i++){
    cout<<" ";
    }
    cout<<endl<<endl<<endl;
    while (pivote != NULL) {
        sacarPila(pivote, ab);
        agregarPila(ref, a);
    }
}

int Moverse(DISCO1 *&pila1, DISCO1 *&pila2, DISCO1 *&pila3, int tor1, int tor2, int tor3) {
    int a;
    int& ab = a;
    sacarPila(pila1, ab);
    agregarPila(pila3, a);
    cout << "Mover disco " << a << " de la torre " << tor1 << " hacia la torre " << tor3 << endl;
    if (tor1 == 1) {
        EscribirDiscos(pila1);
    } else if (tor2 == 1) {
        EscribirDiscos(pila2);
    } else if (tor3 == 1) {
        EscribirDiscos(pila3);
    }
    cout << endl<<endl;
    if (tor1 == 2) {
        EscribirDiscos(pila1);
    } else if (tor2 == 2) {
        EscribirDiscos(pila2);
    } else if (tor3 == 2) {
        EscribirDiscos(pila3);
    }
    cout << endl<<endl;
    if (tor1 == 3) {
        EscribirDiscos(pila1);
    } else if (tor2 == 3) {
        EscribirDiscos(pila2);
    } else if (tor3 == 3) {
        EscribirDiscos(pila3);
    }
    return a;
}

int Jugada(int disco, int torre1, int torre2, int torre3, int& refmov, int total, DISCO1 *&pila1, DISCO1 *&pila2, DISCO1 *&pila3, int& refcomplejidad, int& tor1, int& tor2, int& tor3) {
    int a;
    refcomplejidad++;
    if (disco == 1) {
        a = Moverse(pila1, pila2, pila3, tor1, tor2, tor3);
        refmov++;
        refcomplejidad += 3;
    } else {
        Jugada(disco - 1, torre1, torre3, torre2, refmov, total, pila1, pila3, pila2, refcomplejidad, tor1, tor3, tor2);
        a = Moverse(pila1, pila2, pila3, tor1, tor2, tor3);
        refmov++;
        refcomplejidad += 3;
        Jugada(disco - 1, torre2, torre1, torre3, refmov, total, pila2, pila1, pila3, refcomplejidad, tor2, tor1, tor3);
    }
    return refmov;
}

int main(int argc, char** argv) {
    DISCO1 *pila1 = NULL;
    DISCO1 *pila2 = NULL;
    DISCO1 *pila3 = NULL;
    int tor1 = 1;
    int tor2 = 2;
    int tor3 = 3;
    int& torr1 = tor1;
    int& torr2 = tor2;
    int& torr3 = tor3;
    int movimientos = 0;
    int complejidad = 0;
    int total = 0;
    int& refmov = movimientos;
    int& refcomplejidad = complejidad;
    int torre1 = 1, torre2 = 2, torre3 = 3, disco = 0;
    cout << "Cuantos discos quiere que se Coloquen  ";
    cin>> disco;
    for (int i = disco; i > 0; i--) {
        agregarPila(pila1, i);
    }
    total = disco;
    numerodiscos = disco;
    EscribirDiscos(pila1);
    EscribirDiscos(pila2);
    EscribirDiscos(pila3);
    cout << Jugada(disco, torre1, torre2, torre3, refmov, total, pila1, pila2, pila3, refcomplejidad, torr1, torr2, torr3) << " Movimientos Realizados" << endl;
    cout << complejidad << " Procesos realizados, \"Complejidad\"" << endl;
    return 0;
}

void agregarPila(DISCO1 *&pila, int n) {
    DISCO1 *nuevo_nodo = new DISCO1();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void sacarPila(DISCO1 *&pila, int &n) {
    DISCO1 *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}


