// =====================================================================
//  Usuario.h - EJERCICIO 4
// =====================================================================

#ifndef USUARIO_H
#define USUARIO_H

#include "Libreria.h"

// Propósito: indica si todos los libros del array cs (de n códigos) tienen
//            stock estrictamente mayor al del libro más vendido.
// Precondición: todos los códigos están registrados en la librería, y al
//               menos un libro tiene ventas mayores a cero.
// Eficiencia: O(n . N)
bool todosConMasStockQueElMasVendido(Codigo cs[], int n, Libreria l);

#endif