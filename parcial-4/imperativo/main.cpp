// =====================================================================
//  main.cpp - Pruebas del Parcial Guardia con prioridades
//
//  Compilar:  g++ main.cpp Guardia.cpp UsuarioGuardia.cpp -o guardia
//  Ejecutar:  ./guardia
// =====================================================================

#include <iostream>
#include "Guardia.h"
#include "UsuarioGuardia.h"
using namespace std;

int main() {
    Guardia g = nuevaGuardia(3);   // prioridades 0, 1 y 2

    cout << "===== LLEGAR =====" << endl;
    // llegar("Beto", 2, g);
    // llegar("Ana", 0, g);
    // llegar("Caro", 2, g);
    // llegar("Dani", 2, g);
    // llegar("Eva", 1, g);
    // mostrar(g);
    //   prio 0: Ana (ultimo: Ana)
    //   prio 1: Eva (ultimo: Eva)
    //   prio 2: Beto Caro Dani (ultimo: Dani)
    // cout << enEspera(g) << endl;                // 5

    cout << endl << "===== EMPEORAR =====" << endl;
    // Dani es el ÚLTIMO de la prio 2: ultimos[2] tiene que pasar a ser Caro.
    // empeorar("Dani", g);
    // mostrar(g);
    //   prio 0: Ana (ultimo: Ana)
    //   prio 1: Eva Dani (ultimo: Dani)
    //   prio 2: Beto Caro (ultimo: Caro)

    // Si ultimos[2] quedó mal, esto se rompe o Fede no aparece:
    // llegar("Fede", 2, g);

    // Beto es el PRIMERO de la prio 2 (el caso que pp resuelve sin if):
    // empeorar("Beto", g);
    // mostrar(g);
    //   prio 0: Ana (ultimo: Ana)
    //   prio 1: Eva Dani Beto (ultimo: Beto)
    //   prio 2: Caro Fede (ultimo: Fede)

    // Eva es la primera de la prio 1, y pasa a la 0:
    // empeorar("Eva", g);
    // mostrar(g);
    //   prio 0: Ana Eva (ultimo: Eva)
    //   prio 1: Dani Beto (ultimo: Beto)
    //   prio 2: Caro Fede (ultimo: Fede)

    cout << endl << "===== ATENDER =====" << endl;
    // cout << atender(g) << endl;                 // Ana
    // cout << atender(g) << endl;                 // Eva
    // cout << atender(g) << endl;                 // Dani
    // mostrar(g);
    //   prio 0: (ultimo: NULL)      <- al vaciarse, ultimos[0] vuelve a NULL
    //   prio 1: Beto (ultimo: Beto)
    //   prio 2: Caro Fede (ultimo: Fede)

    cout << endl << "===== ATENDER HASTA (ej. 4) =====" << endl;
    // cout << atenderHasta("Caro", g) << endl;    // 2 (atiende a Beto y a Caro)
    // cout << enEspera(g) << endl;                // 1 (queda Fede)

    cout << endl << "===== LIBERAR (ej. 5) =====" << endl;
    // llegar("Gina", 0, g);
    // llegar("Hugo", 1, g);
    // liberarGuardia(g);                          // no debe romperse
    // cout << "liberada" << endl;

    return 0;
}