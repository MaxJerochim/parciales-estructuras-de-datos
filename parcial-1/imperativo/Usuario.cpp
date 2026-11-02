// =====================================================================
//  Usuario.cpp - EJERCICIO 4
//  Hecho COMO USUARIO del TAD Libreria: solo la interfaz de Libreria.h.
//  NO se ven los chunks (l->pri, cod, stk, ven...).
// =====================================================================

#include "Usuario.h"

bool todosConMasStockQueElMasVendido(Codigo cs[], int n, Libreria l) {
    Codigo elMasVendido = masVendido(l);
    int stockDelMasVendido = stockDe(elMasVendido, l);
    for (int i = 0; i < n; i++) {
         if (stockDe(cs[i], l) <= stockDelMasVendido) {
             return false;
         }
    }
    return true;
}

/*
  Eficiencia: O(n · N)
  siendo N la cantidad de libros de la librería
  y n la cantidad de códigos del array.

  - masVendido recorre los N libros una vez: O(N).
  - stockDe del más vendido busca entre los N libros una vez: O(N).
  - El for da n vueltas y en cada una hace stockDe, que es O(N): O(n · N).
  Total: O(N + N + n · N) = O(n · N).

  Comparación con el Ejercicio 1:
  allá era O((N + n) log N), porque los libros estaban en un Map
  (árbol ordenado) y stockDe buscaba en O(log N). Acá los libros están
  en chunks sin orden, así que stockDe tiene que recorrerlos uno por
  uno: O(N). Por eso esta versión es más lenta.
*/