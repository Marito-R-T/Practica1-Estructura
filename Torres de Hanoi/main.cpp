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


void agregarPila(DISCO1 *&, int);

int Jugada(int disco, int torre1, int torre2, int torre3, int& refmov, int total, DISCO1 *&pila1, DISCO1 *&pila2, DISCO1 *&pila3, int& refcomplejidad) {
    int a;
    refcomplejidad++;
    if (disco == 1) {
        sacarPila(pila1, a);
        agregarPila(pila3, disco);
        cout << "Mover disco " << a << " de la torre " << torre1 << " hacia la torre " << torre3 << endl;
        refmov++;
        refcomplejidad+=3;
    } else {
        Jugada(disco - 1, torre1, torre3, torre2, refmov, total, pila1, pila3, pila2, refcomplejidad);
        sacarPila(pila1, a);
        agregarPila(pila3, disco);
        cout << "Mover disco " << a << " de la torre " << torre1 << " hacia la torre " << torre3 << endl;
        refmov++;
        refcomplejidad+=3;
        Jugada(disco - 1, torre2, torre1, torre3, refmov, total, pila2, pila1, pila3, refcomplejidad);
    }
    return refmov;
}

int main(int argc, char** argv) {
    DISCO1 *pila1 = NULL;
    DISCO1 *pila2 = NULL;
    DISCO1 *pila3 = NULL;
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
    cout << Jugada(disco, torre1, torre2, torre3, refmov, total, pila1, pila2, pila3, refcomplejidad) << " Movimientos Realizados"<<endl;
    cout << complejidad << " Procesos realizados, \"Complejidad\""<< endl;
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


