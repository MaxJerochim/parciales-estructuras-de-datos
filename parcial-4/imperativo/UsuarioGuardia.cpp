// =====================================================================
//  UsuarioGuardia.cpp - EJERCICIO 4
//  Hecho COMO USUARIO del TAD Guardia: solo la interfaz de Guardia.h.
//  NO se ven los nodos ni los arrays (g->primeros, sig...).
// =====================================================================

#include "UsuarioGuardia.h"

// Eficiencia O(g->cant)
int atenderHasta(string nombre, Guardia g) {
    int i = 0;
    while (atender(g) != nombre) {
           i++;
    }
    i++;
    return i;
}