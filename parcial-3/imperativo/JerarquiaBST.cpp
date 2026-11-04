// =====================================================================
//  JerarquiaBST.cpp - IMPLEMENTACIÓN del TAD JerarquiaBST
//  EJERCICIO 1: invariantes de representación (comentario de abajo).
//  EJERCICIO 2: implementar find, insertar y esSubordinadoDe.
//  ¡SIN RECURSIÓN! Todo iterativo (while / for).
// =====================================================================

#include <iostream>
#include "JerarquiaBST.h"

struct JBSTNodeStr {
    string name;            // Nombre de la persona
    JBSTNodeStr* left;      // Empleados con nombre menor a name
    JBSTNodeStr* right;     // Empleados con nombre mayor a name
    JBSTNodeStr* parent;    // Superior jerárquico directo de name
};

struct JBSTStr {
    JBSTNodeStr* root;
};

typedef JBSTStr* JerarquiaBST;

// =====================================================================
//  EJERCICIO 1: Invariantes de representación
// =====================================================================
/*
       1. root no es NULL (siempre hay al menos una persona: la presidente).

       2. Propiedad de BST: para todo nodo n, todos los nombres del subárbol
       izquierdo (n->left) son menores que n->name, y todos los del
       subárbol derecho (n->right) son mayores.
       (En consecuencia, no hay dos nodos con el mismo nombre.)

       3. root->parent es NULL, y la raíz es el ÚNICO nodo con parent NULL.

       4. Para todo nodo distinto de la raíz, parent apunta a un nodo que
       pertenece al árbol (alcanzable desde root por left/right).

       5. La jerarquía no tiene ciclos: partiendo de cualquier nodo y subiendo
       por parent, después de una cantidad finita de pasos se llega a root
       (nadie es su propio jefe, ni directa ni indirectamente).

*/

// =====================================================================
//  YA IMPLEMENTADA (dada)
// =====================================================================

JerarquiaBST fundar(string p) {
    JBSTNodeStr* pres = new JBSTNodeStr;
    pres->name = p;
    pres->left = nullptr;
    pres->right = nullptr;
    pres->parent = nullptr;

    JBSTStr* t = new JBSTStr;
    t->root = pres;
    return t;
}

// =====================================================================
//  EJERCICIO 2
// =====================================================================

// Propósito: describe el nodo donde está la persona de nombre dado, en la
//            jerarquía que comienza en el nodo t (nullptr si no está).
// Eficiencia: o(n) al no ser balanceado
JBSTNodeStr* find(string nombre, JBSTNodeStr* t) {
    if (t->name == nombre) {
        return t;
    } else {
        while (t->name != nombre) {
            if (t->name > nombre) {
                t = t->left;
            } else {
                t = t->right;
            }
        }

        return t;
    }
}

// Propósito: agrega a la persona nuevo como subordinado directo de superior.
// Precondiciones: existe superior y no existe nuevo.
// Eficiencia: O(H), siendo H la altura del BST: hace dos bajadas desde la
//             raíz (buscar al superior y buscar el lugar). Como el árbol
//             no está balanceado, en el peor caso H = N, o sea O(N)
void insertar(string nuevo, string superior, JerarquiaBST t) {
    JBSTNodeStr* nodoNuevo = new JBSTNodeStr;
    nodoNuevo->name = nuevo;
    nodoNuevo->right = nullptr;
    nodoNuevo->left = nullptr;

    JBSTNodeStr* actual = t->root;
    JBSTNodeStr* busqueda = t->root;

    if (actual->name == superior) {
        nodoNuevo->parent = actual;
    } else {
        while (actual->name != superior) {
            if (actual->name > superior) {
                actual = actual->left;
            } else {
                actual = actual->right;
            }
        }

        nodoNuevo->parent = actual;
    }
    
    bool colocado = false;
    while (!colocado) {
          if (busqueda->name > nuevo) {
              if (busqueda->left == nullptr) {
                busqueda->left = nodoNuevo;
                colocado = true;
              } else {
                busqueda = busqueda->left;
              }
          } else {
              if (busqueda->right == nullptr) {
                busqueda->right = nodoNuevo;
                colocado = true;
              } else {
                busqueda = busqueda->right;
              }
          }
    }
}

// Propósito: indica si empleado es subordinado (directo o indirecto)
//            de superior.
// Precondiciones: existen empleado y superior.
// Eficiencia: O(H + J): find baja por el BST (H = altura) y después
//             sube por los jefes (J = profundidad de la jerarquía).
//             En el peor caso, ambos son N: O(N)
bool esSubordinadoDe(string empleado, string superior, JerarquiaBST bst) {
    JBSTNodeStr* root = bst->root;
    JBSTNodeStr* e = find(empleado, root);
    
    if (e == root) {
        return false;
    }

    JBSTNodeStr* parent = e->parent;
    bool esSubordinado = false;
      
    if (parent->name == superior) {
        esSubordinado = true;
        return esSubordinado;
    }

    while (parent != nullptr && parent->name != superior) {
          parent = parent->parent;

          if (parent != nullptr && parent->name == superior) {
              esSubordinado = true;
          }
    }

    return esSubordinado;
}

// =====================================================================
//  AUXILIAR PARA PROBAR (no es parte del parcial, no la mires)
//  Usa recursión porque es solo para mostrar; vos no podés usarla.
// =====================================================================

void mostrarNodo(JBSTNodeStr* n) {
    if (n == nullptr) { return; }
    mostrarNodo(n->left);
    cout << n->name << " (jefe: "
         << (n->parent == nullptr ? "-" : n->parent->name) << ")" << endl;
    mostrarNodo(n->right);
}

void mostrar(JerarquiaBST t) {
    mostrarNodo(t->root);
}