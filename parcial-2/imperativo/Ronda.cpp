// =====================================================================
//  Ronda.cpp - IMPLEMENTACIÓN del TAD Ronda (lista circular doble)
//  EJERCICIO 1: invariantes de representación (comentario de abajo).
//  EJERCICIO 2: implementar insert, remove y length.
// =====================================================================

#include <cstddef>
#include "Ronda.h"

struct RondaNode {
    int value;
    RondaNode* next;
    RondaNode* prev;
};

struct RondaStr {
    RondaNode* current;
};

// =====================================================================
//  EJERCICIO 1: Invariantes de representación
// =====================================================================
/*
    1. Si current es NULL, la ronda está vacía. Si no, current apunta a un
     nodo de la ronda.

  2. Para todo nodo de la ronda, next y prev no son NULL.

  3. Para todo nodo n de la ronda: n->next->prev == n y n->prev->next == n
     (los enlaces de ida y vuelta son coherentes).

  4. La ronda es circular: partiendo de current y avanzando por next,
     después de una cantidad finita de pasos se vuelve a current, y se
     pasa por todos los nodos de la ronda.
     (Si hay un solo nodo, su next y su prev son él mismo.)
*/

// =====================================================================
//  FUNCIONES YA IMPLEMENTADAS (dadas por el enunciado)
// =====================================================================

Ronda mkRonda() {
    RondaStr* ronda = new RondaStr;
    ronda->current = NULL;
    return ronda;
}

int current(Ronda ronda) {
    return ronda->current->value;
}

void move(int pos, Ronda ronda) {
    if (ronda->current == NULL) { return; }
    if (pos > 0) {
        for (int i = 0; i < pos; i++) {
            ronda->current = ronda->current->next;
        }
    } else {
        for (int i = 0; i > pos; i--) {
            ronda->current = ronda->current->prev;
        }
    }
}

// =====================================================================
//  EJERCICIO 2
// =====================================================================

// Propósito: inserta un elemento como el nuevo elemento actual. Si la ronda
//            ya tiene elementos, el anterior valor actual queda en la
//            posición previa.
// Eficiencia: O(1)
void insert(int value, Ronda ronda) {
    RondaNode* node = new RondaNode;
    node->value = value;

    if (ronda->current == nullptr) {
        ronda->current = node;
        node->next = node;
        node->prev = node;
    } else {
        RondaNode* proxAlActual = ronda->current->next;
        node->next = proxAlActual;
        node->prev = ronda->current;
        proxAlActual->prev = node;
        ronda->current->next = node;
        ronda->current = node;
    }
}

// Propósito: remueve el elemento actual; el valor anterior pasa a ser el
//            actual. Si la ronda está vacía, no hace nada.
// Eficiencia: O(1)
void remove(Ronda ronda) {
    if (ronda->current == nullptr) {
        return;
    }

    if (ronda->current == ronda->current->next) {
        RondaNode* aBorrar = ronda->current;
        ronda->current = nullptr;
        delete aBorrar;
    } else {
        RondaNode* aBorrar = ronda->current;
        RondaNode* proxABorrar = ronda->current->next;
        RondaNode* prevABorrar = ronda->current->prev;

       ronda->current = prevABorrar;
       prevABorrar->next = proxABorrar;
       proxABorrar->prev = prevABorrar;
       delete aBorrar; 
    }
}

// Propósito: indica la cantidad de elementos de la ronda.
// Eficiencia: O(N)
int length(Ronda ronda) {
    if (ronda->current == nullptr) {
        return 0;
    }

    int l = 0;
    RondaNode* primero = ronda->current;
    RondaNode* actual = ronda->current->next;
    while (actual != primero) {
        actual = actual->next;
        l++;
    }
    return l + 1;
}