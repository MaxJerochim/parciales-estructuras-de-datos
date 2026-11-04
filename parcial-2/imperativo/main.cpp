// =====================================================================
//  main.cpp - Pruebas del Parcial Ronda
//
//  Compilar:  g++ main.cpp Ronda.cpp UsuarioRonda.cpp -o ronda
//  Ejecutar:  ./ronda
// =====================================================================

#include <iostream>
#include "Ronda.h"
#include "UsuarioRonda.h"
using namespace std;

// Auxiliar: muestra la ronda empezando por el actual, yendo hacia adelante.
// Usa length, así que necesita el Ejercicio 2 terminado.
void mostrar(Ronda r) {
    cout << "[";
    int n = length(r);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << ", ";
        }
        cout << current(r);
        move(1, r);
    }
    cout << "]" << endl;
}

int main() {
    cout << "===== EJERCICIO 2 =====" << endl;
    // Descomentá las pruebas a medida que vayas terminando cada función.

    // Ronda r = mkRonda();
    // cout << length(r) << endl;          // 0
    // remove(r);                          // vacía: no hace nada (no se rompe)
    // cout << length(r) << endl;          // 0

    // insert(1, r);
    // cout << length(r) << endl;          // 1
    // cout << current(r) << endl;         // 1

    // insert(2, r);
    // insert(3, r);
    // cout << length(r) << endl;          // 3
    // cout << current(r) << endl;         // 3
    // move(-1, r);
    // cout << current(r) << endl;         // 2  (el actual anterior quedó atrás)
    // move(1, r);
    // mostrar(r);                         // [3, 1, 2]

    // remove(r);                          // saca el 3; el anterior (2) pasa a ser actual
    // cout << current(r) << endl;         // 2
    // cout << length(r) << endl;          // 2
    // mostrar(r);                         // [2, 1]

    // remove(r);
    // remove(r);
    // cout << length(r) << endl;          // 0  (quedó vacía)

    cout << endl << "===== EJERCICIO 3 =====" << endl;

    // int xs[4] = {10, 20, 30, 40};
    // Ronda r2 = fromArray(4, xs);
    // cout << current(r2) << endl;        // 10  (el primero del array)
    // cout << length(r2) << endl;         // 4
    // mostrar(r2);                        // [10, 20, 30, 40]

    // int* ys = toArray(r2);
    // for (int i = 0; i < 4; i++) {
    //     cout << ys[i] << " ";           // 10 20 30 40
    // }
    // cout << endl;

    return 0;
}