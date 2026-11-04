// =====================================================================
//  UsuarioRonda.cpp - EJERCICIO 3
//  Hecho COMO USUARIO del TAD Ronda: solo la interfaz de Ronda.h.
//  NO se ven los nodos (ronda->current, next, prev...).
// =====================================================================

#include "UsuarioRonda.h"

// a)
// Eficiencia: O(N)
int* toArray(Ronda ronda) {
    int n = length(ronda);
    int* array = new int[n];

    for (int i = 0; i < n; i++) {
         array[i] = current(ronda);
         move(1, ronda);
    }
    return array;
}

// b)
// Eficiencia: O(N)
Ronda fromArray(int len, int* arra) {
    Ronda ron = mkRonda();
    for (int i = 0; i < len; i++) {
         insert(arra[i], ron);
    }
    move(1, ron);
    return ron;
}