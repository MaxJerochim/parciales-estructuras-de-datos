// =====================================================================
//  UsuarioGuardia.h - EJERCICIO 4
// =====================================================================

#ifndef USUARIO_GUARDIA_H
#define USUARIO_GUARDIA_H

#include "Guardia.h"

// Propósito: atiende pacientes hasta atender al de nombre dado (inclusive)
//            y devuelve cuántos pacientes fueron atendidos.
// Precondición: el paciente está en espera.
// Eficiencia: O(cant)
int atenderHasta(string nombre, Guardia g);

#endif