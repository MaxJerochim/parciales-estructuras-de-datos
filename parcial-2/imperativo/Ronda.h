// =====================================================================
//  Ronda.h - INTERFAZ del TAD Ronda
//  N = cantidad de elementos de la ronda.
// =====================================================================

#ifndef RONDA_H
#define RONDA_H

struct RondaStr;
typedef RondaStr* Ronda;

// Propósito: crea una ronda sin elementos.
Ronda mkRonda();

// Propósito: retorna el elemento actual de la ronda.
// Precondición: la ronda no está vacía.
int current(Ronda ronda);

// Propósito: mueve el elemento actual la cantidad indicada de posiciones
//            hacia adelante (pos > 0) o hacia atrás (pos < 0).
void move(int pos, Ronda ronda);

// Propósito: inserta un elemento como el nuevo elemento actual. Si la ronda
//            ya tiene elementos, el anterior valor actual queda en la
//            posición previa.
void insert(int value, Ronda ronda);

// Propósito: remueve el elemento actual; el valor anterior pasa a ser el
//            actual. Si la ronda está vacía, no hace nada.
void remove(Ronda ronda);

// Propósito: indica la cantidad de elementos de la ronda.
int length(Ronda ronda);

#endif