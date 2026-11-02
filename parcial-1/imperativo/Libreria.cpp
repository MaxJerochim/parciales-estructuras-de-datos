// =====================================================================
//  Libreria.cpp - IMPLEMENTACIÓN del TAD Libreria (lista de chunks)
//  EJERCICIO 5: invariantes de representación (comentario de abajo).
//  EJERCICIO 6: implementar registrar y masVendido.
// =====================================================================

#include "Libreria.h"

#define CAPACIDAD 8

struct ChunkStr {
    string cod[CAPACIDAD];  // códigos
    int stk[CAPACIDAD];     // stocks (paralelo a cod)
    int ven[CAPACIDAD];     // ventas (paralelo a cod)
    int cant;               // libros en este chunk
    ChunkStr* next;         // siguiente chunk
};
typedef ChunkStr* Chunk;

struct LibreriaStr {
    Chunk pri;  // primer chunk
    Chunk ult;  // último chunk
    int cant;   // total de libros registrados
};

// =====================================================================
//  EJERCICIO 5: Invariantes de representación
// =====================================================================
/*
  Nota: en esta implementación, nuevaLibreria arranca SIN chunks
  (pri y ult en NULL, cant en 0). Tenelo en cuenta para los invariantes.

  Invariantes de LibreriaStr:
  1. ?
  2. ?

  Invariantes de ChunkStr:
  1. ?
  2. ?

  (agregá los que hagan falta)
*/

// =====================================================================
//  EJERCICIO 6
// =====================================================================

// Propósito: incorpora el libro de código dado, con stock 0 y ventas 0.
// Precondición: el libro no está registrado.
// Eficiencia: O(1)  -- justificar
void registrar(Codigo c, Libreria l) {
    // TODO
}

// Propósito: describe el código del libro con más ventas acumuladas.
// Precondición: al menos un libro tiene ventas mayores a cero.
// Eficiencia: O(N)  -- justificar
Codigo masVendido(Libreria l) {
    // TODO
    return "";
}

// Subtareas que necesites para el Ejercicio 6 (con propósito,
// precondición y eficiencia):



// =====================================================================
//  FUNCIONES YA IMPLEMENTADAS (NO son parte del parcial)
//  Están para que puedas probar. Recorren los chunks buscando un libro,
//  así que se parecen a lo que necesitás en masVendido: si querés
//  hacerla sin ayuda, no las mires antes.
// =====================================================================

Libreria nuevaLibreria() {
    LibreriaStr* l = new LibreriaStr;
    l->pri = nullptr;
    l->ult = nullptr;
    l->cant = 0;
    return l;
}

// (más abajo, a propósito, para que no las veas sin querer)

// Busca el libro c. Deja en ch el chunk donde está y en i su posición.
// Precondición: el libro está registrado.
void buscarLibro(Codigo c, Libreria l, Chunk& ch, int& i) {
    ch = l->pri;
    while (ch != nullptr) {
        for (i = 0; i < ch->cant; i++) {
            if (ch->cod[i] == c) {
                return;
            }
        }
        ch = ch->next;
    }
}

void reponer(Codigo c, Cantidad n, Libreria l) {
    Chunk ch; int i;
    buscarLibro(c, l, ch, i);
    ch->stk[i] = ch->stk[i] + n;
}

void vender(Codigo c, Libreria l) {
    Chunk ch; int i;
    buscarLibro(c, l, ch, i);
    ch->stk[i]--;
    ch->ven[i]++;
}

int stockDe(Codigo c, Libreria l) {
    Chunk ch; int i;
    buscarLibro(c, l, ch, i);
    return ch->stk[i];
}