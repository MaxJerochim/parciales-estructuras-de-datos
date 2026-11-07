// =====================================================================
//  Planilla.h - INTERFAZ del TAD Planilla (matriz dispersa)
//  K = cantidad de celdas guardadas en la fila involucrada.
// =====================================================================

#ifndef PLANILLA_H
#define PLANILLA_H

struct PlanillaStr;
typedef PlanillaStr* Planilla;

// Propósito: crea una planilla de f filas y c columnas, todo en 0.
Planilla nuevaPlanilla(int f, int c);                      // O(F)

// Propósito: indican las dimensiones de la planilla.
int filas(Planilla p);                                     // O(1)
int columnas(Planilla p);                                  // O(1)

// Propósito: indica el valor de la celda (f, c).
// Precondición: la celda existe en la planilla.
int valor(int f, int c, Planilla p);                       // O(K)

// Propósito: la celda (f, c) pasa a valer v (si v es 0, deja de guardarse).
// Precondición: la celda existe en la planilla.
void asignar(int f, int c, int v, Planilla p);             // O(K)

// Propósito: suma la fila origen a la fila destino (celda a celda).
//            La fila origen no se modifica.
// Precondición: ambas filas existen y son distintas.
void sumarFila(int origen, int destino, Planilla p);       // O(Korigen + Kdestino)

// Propósito: indica cuántas celdas distintas de 0 tiene la planilla.
int cantNoNulos(Planilla p);                               // O(1)

// Propósito: libera toda la memoria usada por la planilla.
void liberarPlanilla(Planilla p);

// AUXILIAR PARA PROBAR (no es parte del parcial): muestra las celdas
// guardadas de cada fila como (columna,valor).
void mostrar(Planilla p);

#endif