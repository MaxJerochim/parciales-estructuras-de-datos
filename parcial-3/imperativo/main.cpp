// =====================================================================
//  main.cpp - Pruebas del Parcial BST con jerarquía
//
//  Compilar:  g++ main.cpp JerarquiaBST.cpp -o jerarquia
//  Ejecutar:  ./jerarquia
// =====================================================================

#include <iostream>
#include "JerarquiaBST.h"
using namespace std;

int main() {
    // Jerarquía de prueba (quién es jefe de quién):
    //
    //               Mara               <- presidente
    //             /      \             .
    //        Carlos      Tomas
    //        /    \          \         .
    //      Ana    Zoe        Pedro
    //       |
    //      Beto
    //
    // (Ojo: esto es la JERARQUÍA. El BST por nombres es otro árbol:
    //  cada uno se ubica a la izquierda o derecha según el orden alfabético.)

    JerarquiaBST t = fundar("Mara");

    cout << "===== INSERTAR =====" << endl;
    // insertar("Carlos", "Mara", t);
    // insertar("Tomas", "Mara", t);
    // insertar("Ana", "Carlos", t);
    // insertar("Pedro", "Tomas", t);
    // insertar("Beto", "Ana", t);
    // insertar("Zoe", "Carlos", t);
    mostrar(t);
    // Esperado (en orden alfabético):
    //   Ana (jefe: Carlos)
    //   Beto (jefe: Ana)
    //   Carlos (jefe: Mara)
    //   Mara (jefe: -)
    //   Pedro (jefe: Tomas)
    //   Tomas (jefe: Mara)
    //   Zoe (jefe: Carlos)

    cout << endl << "===== ES SUBORDINADO DE =====" << endl;
    // cout << esSubordinadoDe("Carlos", "Mara", t) << endl;    // 1 (directo)
    // cout << esSubordinadoDe("Beto", "Mara", t) << endl;      // 1 (indirecto: Beto -> Ana -> Carlos -> Mara)
    // cout << esSubordinadoDe("Beto", "Carlos", t) << endl;    // 1
    // cout << esSubordinadoDe("Zoe", "Carlos", t) << endl;     // 1
    // cout << esSubordinadoDe("Pedro", "Carlos", t) << endl;   // 0 (Pedro está bajo Tomas)
    // cout << esSubordinadoDe("Carlos", "Ana", t) << endl;     // 0 (al revés: Ana es subordinada de Carlos)
    // cout << esSubordinadoDe("Mara", "Tomas", t) << endl;     // 0 (la presidente no tiene jefe)

    return 0;
}