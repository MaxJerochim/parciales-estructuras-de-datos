// =====================================================================
//  UsuarioRonda.h - EJERCICIO 3
// =====================================================================

#ifndef USUARIO_RONDA_H
#define USUARIO_RONDA_H

#include "Ronda.h"

// Propósito: construye un array con todos los valores de la ronda dada.
// Eficiencia: ?
int* toArray(Ronda ronda);

// Propósito: construye una ronda con todos los valores del array dado.
//            El elemento actual del resultado es el primero del array.
// Eficiencia: ?
Ronda fromArray(int len, int* arra);

#endif