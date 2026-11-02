// =====================================================================
//  Libreria.h - INTERFAZ del TAD Libreria (versión imperativa, C++)
//  N = cantidad de libros registrados.
// =====================================================================

#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <string>
using namespace std;

typedef string Codigo;
typedef int Cantidad;
struct LibreriaStr;
typedef LibreriaStr* Libreria;

// Propósito: describe una librería sin libros.
Libreria nuevaLibreria();                        // O(1)

// Propósito: incorpora el libro de código dado, con stock 0 y ventas 0.
// Precondición: el libro no está registrado.
void registrar(Codigo c, Libreria l);            // O(1)

// Propósito: suma la cantidad dada al stock del libro dado.
// Precondición: el libro está registrado, la cantidad es mayor que cero.
void reponer(Codigo c, Cantidad n, Libreria l);  // O(N)

// Propósito: descuenta una unidad del stock del libro dado e incrementa
//            en una unidad sus ventas acumuladas.
// Precondición: el libro está registrado y tiene stock mayor que cero.
void vender(Codigo c, Libreria l);               // O(N)

// Propósito: describe el stock disponible del libro dado.
// Precondición: el libro está registrado.
int stockDe(Codigo c, Libreria l);               // O(N)

// Propósito: describe el código del libro con más ventas acumuladas;
//            en caso de empate, cualquiera de los que tengan más ventas.
// Precondición: al menos un libro tiene ventas mayores a cero.
Codigo masVendido(Libreria l);                   // O(N)

#endif