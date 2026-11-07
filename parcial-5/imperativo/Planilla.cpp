// =====================================================================
//  Planilla.cpp - IMPLEMENTACIÓN del TAD Planilla
//  EJERCICIO 1: invariantes de representación.
//  EJERCICIO 2: valor.
//  EJERCICIO 3: asignar (recorriendo con CeldaNode** pp).
//  EJERCICIO 4: sumarFila (merge, sin usar asignar).
//  EJERCICIO 6: liberarPlanilla.
//  ¡SIN RECURSIÓN!
// =====================================================================

#include <iostream>
#include <cstddef>
#include "Planilla.h"
using namespace std;

struct CeldaNode {
    int col;            // columna de la celda
    int val;            // valor de la celda
    CeldaNode* sig;     // siguiente celda guardada de la MISMA fila
};

struct PlanillaStr {
    int F;              // cantidad de filas
    int C;              // cantidad de columnas
    CeldaNode** filas;  // array de F punteros: lista de celdas de cada fila
    int noNulos;        // cantidad total de celdas guardadas
};

// =====================================================================
//  EJERCICIO 1: Invariantes de representación
// =====================================================================
/*
  1. ?

  2. ?

  (agregá los que hagan falta)
*/

// =====================================================================
//  YA IMPLEMENTADAS (dadas por el enunciado)
// =====================================================================

Planilla nuevaPlanilla(int f, int c) {
    Planilla p = new PlanillaStr;
    p->F = f;
    p->C = c;
    p->noNulos = 0;
    p->filas = new CeldaNode*[f];
    for (int i = 0; i < f; i++) {
        p->filas[i] = NULL;
    }
    return p;
}

int filas(Planilla p)       { return p->F; }
int columnas(Planilla p)    { return p->C; }
int cantNoNulos(Planilla p) { return p->noNulos; }

// =====================================================================
//  EJERCICIO 2
// =====================================================================

// Propósito: indica el valor de la celda (f, c).
// Eficiencia: O(K), siendo K las celdas guardadas en la fila f:
//             en el peor caso recorre toda la fila.
int valor(int f, int c, Planilla p) {
    int valor = 0;
    CeldaNode* fila = *(p->filas + f);
    
    if (fila == nullptr) {
        return 0;
    } else {
        while (fila != nullptr && fila->col < c) {
            fila = fila->sig;
        }

        if (fila != nullptr && fila->col == c) {
            valor = fila->val;
        }
    }
    return valor;
}

// =====================================================================
//  EJERCICIO 3  (recorrer la fila con CeldaNode** pp)
// =====================================================================

// Propósito: la celda (f, c) pasa a valer v (si v es 0, deja de guardarse).
// Eficiencia: O(K) siendo K la cant de celdas de esa fila
void asignar(int f, int c, int v, Planilla p) {
    CeldaNode* fila = *(p->filas + f);

    while (fila != nullptr && fila->col < c) {
            fila = fila->sig;
    }

    if (fila != nullptr && fila->col == c) {
            fila->val = v;
    }
}

// =====================================================================
//  EJERCICIO 4  (merge: una sola pasada por cada fila, sin usar asignar)
// =====================================================================

// Propósito: suma la fila origen a la fila destino (celda a celda).
// Eficiencia: ?  -- justificar
void sumarFila(int origen, int destino, Planilla p) {
    // TODO
}

// =====================================================================
//  EJERCICIO 6
// =====================================================================

// Propósito: libera toda la memoria usada por la planilla.
// Eficiencia: ?  -- justificar
void liberarPlanilla(Planilla p) {
    // TODO
}

// =====================================================================
//  AUXILIAR PARA PROBAR (no es parte del parcial)
// =====================================================================

void mostrar(Planilla p) {
    for (int i = 0; i < p->F; i++) {
        cout << "  fila " << i << ":";
        CeldaNode* a = p->filas[i];
        while (a != NULL) {
            cout << " (" << a->col << "," << a->val << ")";
            a = a->sig;
        }
        cout << endl;
    }
}