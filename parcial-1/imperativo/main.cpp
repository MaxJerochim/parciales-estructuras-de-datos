// =====================================================================
//  main.cpp - Pruebas del Parcial Librería, Parte 2
//
//  Compilar:  g++ main.cpp Libreria.cpp Usuario.cpp -o libreria
//  Ejecutar:  ./libreria
// =====================================================================

#include <iostream>
#include "Libreria.h"
#include "Usuario.h"
using namespace std;

int main() {
    cout << "===== EJERCICIO 6 =====" << endl;
    // Descomentá las pruebas a medida que vayas terminando cada función.

    // Se registran 10 libros: con CAPACIDAD 8, los primeros 8 van al
    // primer chunk y L9, L10 a un segundo chunk.
    // Libreria l = nuevaLibreria();
    // Codigo codigos[10] = {"L1","L2","L3","L4","L5","L6","L7","L8","L9","L10"};
    // for (int i = 0; i < 10; i++) {
    //     registrar(codigos[i], l);
    // }
    // cout << stockDe("L1", l) << endl;          // 0
    // cout << stockDe("L10", l) << endl;         // 0  (está en el segundo chunk)

    // Stocks y ventas:
    //   L2:  repone 5, vende 1 -> stock 4,  ventas 1
    //   L10: repone 9, vende 3 -> stock 6,  ventas 3   (el más vendido, en el 2do chunk)
    //   L4:  repone 7          -> stock 7,  ventas 0
    //   L5:  repone 2          -> stock 2,  ventas 0
    // reponer("L2", 5, l);   vender("L2", l);
    // reponer("L10", 9, l);  vender("L10", l); vender("L10", l); vender("L10", l);
    // reponer("L4", 7, l);
    // reponer("L5", 2, l);
    // cout << stockDe("L10", l) << endl;         // 6
    // cout << masVendido(l) << endl;             // L10

    cout << endl << "===== EJERCICIO 4 =====" << endl;
    // El más vendido es L10, con stock 6.
    // Codigo a[1] = {"L4"};                      // stock 7 > 6
    // Codigo b[2] = {"L4", "L2"};                // L2 tiene stock 4, no supera a 6
    // cout << todosConMasStockQueElMasVendido(a, 1, l) << endl;   // 1
    // cout << todosConMasStockQueElMasVendido(b, 2, l) << endl;   // 0
    // cout << todosConMasStockQueElMasVendido(b, 0, l) << endl;   // 1 (array vacío: no hay contraejemplo)

    return 0;
}