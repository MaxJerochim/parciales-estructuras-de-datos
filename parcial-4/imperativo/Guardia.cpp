// =====================================================================
//  Guardia.cpp - IMPLEMENTACIÓN del TAD Guardia
//  EJERCICIO 1: invariantes de representación.
//  EJERCICIO 2: llegar y atender.
//  EJERCICIO 3: empeorar (recorriendo con PacienteNode** pp).
//  EJERCICIO 5: liberarGuardia.
//  ¡SIN RECURSIÓN!
// =====================================================================

#include <iostream>
#include <cstddef>
#include "Guardia.h"

struct PacienteNode {
    string nombre;
    int prio;               // prioridad actual del paciente
    PacienteNode* sig;      // siguiente en la espera de SU prioridad
};

struct GuardiaStr {
    int P;                    // cantidad de niveles de prioridad
    PacienteNode** primeros;  // array de P punteros: primero de cada prioridad
    PacienteNode** ultimos;   // array de P punteros: último de cada prioridad
    int cant;                 // total de pacientes en espera
};

// =====================================================================
//  EJERCICIO 1: Invariantes de representación
// =====================================================================
/*
  1. P > 0, y primeros y ultimos son arrays de exactamente P casillas.

  2. Para toda prioridad i (0 <= i < P):
     primeros[i] es NULL si y solo si ultimos[i] es NULL
     (la cola i está vacía o tiene primero y último a la vez).

  3. Para toda prioridad i con cola no vacía: ultimos[i] es el último
     nodo de la cadena que empieza en primeros[i], es decir, se llega a
     él avanzando por sig desde primeros[i], y su sig es NULL.
     (La cadena es finita, sin ciclos.)

  4. Todo nodo que está en la cola i tiene prio == i.

  5. cant es igual a la cantidad total de nodos sumando todas las colas.

  6. No hay dos pacientes con el mismo nombre en toda la guardia, y
     ningún nodo aparece en más de una cola.
*/

// =====================================================================
//  YA IMPLEMENTADAS (dadas por el enunciado)
// =====================================================================

Guardia nuevaGuardia(int p) {
    Guardia g = new GuardiaStr;
    g->P = p;
    g->cant = 0;
    g->primeros = new PacienteNode*[p];
    g->ultimos  = new PacienteNode*[p];
    for (int i = 0; i < p; i++) {
        g->primeros[i] = NULL;
        g->ultimos[i]  = NULL;
    }
    return g;
}

int enEspera(Guardia g) {
    return g->cant;
}

// =====================================================================
//  EJERCICIO 2
// =====================================================================

// Propósito: agrega al paciente al final de la espera de su prioridad.
// Eficiencia: O(1)
void llegar(string nombre, int prio, Guardia g) {
    PacienteNode* nuevoPaciente = new PacienteNode;
    nuevoPaciente->nombre = nombre;
    nuevoPaciente->prio = prio;
    nuevoPaciente->sig = nullptr;

    PacienteNode* actualUltimo = *(g->ultimos + prio); // o g->ultimos[prio]

    if (actualUltimo == nullptr) {
        *(g->primeros + prio) = nuevoPaciente;
        *(g->ultimos + prio) = nuevoPaciente;
    } else {
        actualUltimo->sig = nuevoPaciente;
        *(g->ultimos + prio) = nuevoPaciente;
    }

    g->cant++;
}

// Propósito: quita al paciente que corresponde atender y devuelve su nombre.
// Eficiencia: O(P) en peor caso
string atender(Guardia g) {
    int n = g->P;
    g->cant--;
    string name = "";

    for (int i = 0; i < n; i++) {
        if ((*(g->primeros + i)) != nullptr) {
             if ((*(g->primeros + i)) == (*(g->ultimos + i))) {
                PacienteNode* aBorrar = *(g->primeros + i);
                name = aBorrar->nombre;
                *(g->primeros + i) = nullptr;
                *(g->ultimos + i) = nullptr;
                delete aBorrar;
                return name;
             } else {
                PacienteNode* aBorrar = *(g->primeros + i);
                *(g->primeros + i) = (*(g->primeros + i))->sig;
                name = aBorrar->nombre;
                delete aBorrar;
                return name;
             }
        }
    }
    return name;
}

// =====================================================================
//  EJERCICIO 3  (recorrer la cola con PacienteNode** pp)
// =====================================================================

// Propósito: el paciente pasa a la prioridad inmediatamente más urgente,
//            al final de la espera de esa prioridad.
// Eficiencia: O(P + N): recorre las P colas buscando al paciente (entre
//             todas, a lo sumo N nodos); moverlo es O(1) gracias a ultimos.
void empeorar(string nombre, Guardia g) {
    int n = g->P;

    for (int i = 0; i < n; i++) {
        PacienteNode* actual = *(g->primeros + i);
        PacienteNode* anterior = nullptr;

        while (actual != nullptr && actual->nombre != nombre) {
            anterior = actual;
            actual = actual->sig;
        }

        if (actual != nullptr) {
            if (anterior == nullptr) {
                *(g->primeros + i) = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }
            if (actual->sig == nullptr) {
                *(g->ultimos + i) = anterior;
            }

            PacienteNode* urgencia = actual;
            int prioridad = urgencia->prio - 1;
            urgencia->prio = prioridad;
            urgencia->sig = nullptr;

            if (*(g->ultimos + prioridad) == nullptr) {
                *(g->primeros + prioridad) = urgencia;
            } else {
                (*(g->ultimos + prioridad))->sig = urgencia;
            }
            *(g->ultimos + prioridad) = urgencia;

            return;
        }
    }
}

// =====================================================================
//  EJERCICIO 5
// =====================================================================

// Propósito: libera toda la memoria usada por la guardia.
// Eficiencia: O(PRIO * PAC)
void liberarGuardia(Guardia g) {
    int n = g->P;

    for (int i = 0; i < n; i++) {
        if ((*(g->primeros + i)) != nullptr) {
            while ((*(g->primeros + i)) != nullptr) {
                PacienteNode* aBorrar = *(g->primeros + i);
                *(g->primeros + i) = (*(g->primeros + i))->sig;
                delete aBorrar;
            } 
            *(g->primeros + i) = nullptr;
            *(g->ultimos + i) = nullptr;
        }
    }

    delete[] g->primeros;
    delete[] g->ultimos;
    delete g;
}

// =====================================================================
//  AUXILIAR PARA PROBAR (no es parte del parcial)
// =====================================================================

void mostrar(Guardia g) {
    for (int i = 0; i < g->P; i++) {
        cout << "  prio " << i << ": ";
        PacienteNode* a = g->primeros[i];
        while (a != NULL) {
            cout << a->nombre << " ";
            a = a->sig;
        }
        cout << "(ultimo: "
             << (g->ultimos[i] == NULL ? "NULL" : g->ultimos[i]->nombre)
             << ")" << endl;
    }
}