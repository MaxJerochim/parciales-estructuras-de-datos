// =====================================================================
//  JerarquiaBST.h - INTERFAZ del TAD JerarquiaBST
//  N = cantidad de personas, H = altura del BST,
//  J = profundidad de la jerarquía (cantidad de niveles de superiores).
// =====================================================================

#ifndef JERARQUIA_BST_H
#define JERARQUIA_BST_H

#include <string>
using namespace std;

struct JBSTStr;
typedef JBSTStr* JerarquiaBST;

// Propósito: crea la jerarquía, colocando a la persona p como presidente.
JerarquiaBST fundar(string p);

// Propósito: agrega a la persona nuevo como subordinado directo de superior.
// Precondiciones: existe una persona con el nombre superior, y
//                 no existe una persona con el nombre nuevo.
void insertar(string nuevo, string superior, JerarquiaBST t);

// Propósito: indica si empleado es subordinado (directo o indirecto)
//            de superior.
// Precondiciones: existen personas con los nombres empleado y superior.
bool esSubordinadoDe(string empleado, string superior, JerarquiaBST bst);

// AUXILIAR PARA PROBAR (no es parte del parcial): muestra cada persona,
// en orden alfabético, con su superior directo.
void mostrar(JerarquiaBST t);

#endif