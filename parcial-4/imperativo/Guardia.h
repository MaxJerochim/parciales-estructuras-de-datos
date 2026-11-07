// =====================================================================
//  Guardia.h - INTERFAZ del TAD Guardia
//  N = cantidad de pacientes en espera, P = cantidad de prioridades.
// =====================================================================

#ifndef GUARDIA_H
#define GUARDIA_H

#include <string>
using namespace std;

struct GuardiaStr;
typedef GuardiaStr* Guardia;

// Propósito: crea una guardia vacía con p niveles de prioridad (0 a p-1).
// Precondición: p > 0.
Guardia nuevaGuardia(int p);                      // O(P)

// Propósito: agrega al paciente al final de la espera de su prioridad.
// Precondiciones: 0 <= prio < P y el paciente no está en espera.
void llegar(string nombre, int prio, Guardia g);  // O(1)

// Propósito: quita de la espera al paciente que corresponde atender
//            y devuelve su nombre.
// Precondición: hay al menos un paciente en espera.
string atender(Guardia g);                        // O(P)

// Propósito: el paciente pasa a la prioridad inmediatamente más urgente,
//            al final de la espera de esa prioridad.
// Precondiciones: el paciente está en espera y su prioridad es mayor a 0.
void empeorar(string nombre, Guardia g);          // O(N)

// Propósito: indica cuántos pacientes hay esperando.
int enEspera(Guardia g);                          // O(1)

// Propósito: libera toda la memoria usada por la guardia.
void liberarGuardia(Guardia g);

// AUXILIAR PARA PROBAR (no es parte del parcial): muestra cada cola
// y quién figura como último en el array ultimos.
void mostrar(Guardia g);

#endif