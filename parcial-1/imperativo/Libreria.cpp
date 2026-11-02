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
  1. pri es NULL si y solo si ult es NULL, si y solo si cant es 0
     (o la librería está vacía y no hay chunks, o hay al menos uno).
  2. Si hay chunks, ult es el último chunk de la cadena que empieza en
     pri, es decir, ult->next es NULL.
  3. cant es igual a la suma de los cant de todos los chunks.
  4. Un mismo código no aparece dos veces en toda la librería
     (ni en el mismo chunk ni en chunks distintos).
  5. Todos los chunks, menos ult, están llenos (cant == CAPACIDAD).

  Invariantes de ChunkStr:
  1. 1 <= cant <= CAPACIDAD (no hay chunks vacíos ni pasados de capacidad).
  2. Para toda posición i entre 0 y cant-1:
     stk[i] >= 0 y ven[i] >= 0.
  3. Las posiciones válidas son de 0 a cant-1; lo que haya desde cant
     en adelante no se considera.

*/

// =====================================================================
//  EJERCICIO 6
// =====================================================================

// Propósito: incorpora el libro de código dado, con stock 0 y ventas 0.
// Precondición: el libro no está registrado.
// Eficiencia: O(1)
void registrar(Codigo c, Libreria l) {
    if (l->pri == nullptr) {
        Chunk chu = new ChunkStr;
        chu->cod[0] = c;
        chu->stk[0] = 0;
        chu->ven[0] = 0;
        chu->cant = 1;
        chu->next = nullptr;
        l->pri = chu;
        l->ult = chu;
    } else if (l->pri != nullptr && l->pri == l->ult) {
        if (l->ult->cant == 8) {
            Chunk chu = new ChunkStr;
            chu->cod[0] = c;
            chu->stk[0] = 0;
            chu->ven[0] = 0;
            chu->cant = 1;
            chu->next = nullptr;

            l->ult->next = chu;
            l->ult = chu;
        } else {
            l->pri->cod[l->pri->cant] = c;
            l->pri->stk[l->pri->cant] = 0;
            l->pri->ven[l->pri->cant] = 0;
            l->pri->cant++;
        }
    } else if (l->pri != nullptr && l->pri != l->ult) {
        if (l->ult->cant == 8) {
            Chunk chu = new ChunkStr;
            chu->cod[0] = c;
            chu->stk[0] = 0;
            chu->ven[0] = 0;
            chu->cant = 1;
            chu->next = nullptr;

            l->ult->next = chu;
            l->ult = chu;
        } else {
            l->ult->cod[l->ult->cant] = c;
            l->ult->stk[l->ult->cant] = 0;
            l->ult->ven[l->ult->cant] = 0;
            l->ult->cant++;
        }
    }

    l->cant++;
}

// Propósito: describe el código del libro con más ventas acumuladas.
// Precondición: al menos un libro tiene ventas mayores a cero.
// Eficiencia: O(N)
Codigo masVendido(Libreria l) {
    Codigo mejor = "";
    int maxVentas = -1;
    Chunk ch = l->pri;
    while (ch != nullptr) {
        for (int i = 0; i < ch->cant; i++) {
            if (ch->ven[i] > maxVentas) {
                maxVentas = ch->ven[i];
                mejor = ch->cod[i];
            }
        }
        ch = ch->next;
    }
    return mejor;
}

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