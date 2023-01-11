
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

    El coste de la función en el peor de los casos es O(N*log(N)), siendo N el número de esquiadores y esquis a emparejar. Este coste viene de la función sort(),
    la cual tiene coste O(N*log(N)).

    Para resolver el ejercicio he empleado un algoritmo voraz V, el cual consiste en ir asignando esquis a esquiadores con una altura, para ello he ordenado ambos
    vectores de menor a mayor, y asi se ha ido asignando los esquis de menor tamaño a los esquiadores con menor altura, provocando una minimización de suma
    las diferencias entre ambos.

    Comprobación del algoritmo voraz:

    Supongamos la altura de los esquiadores de forma que i <= j --> a[i] <= a[j]
    Supongamos el tamaño de los esquis de forma que i <= j --> e[i] <= e[j]

    Recorremos los esquiadores de menor a mayor altura y el algoritmo voraz V selecciona los esquis de menor tamaño que le proporciona la menor suma de diferencias.
    
    Por tanto, el aspecto de la solución voraz es una secuencia creciente de asignacion de esquis.

    ** AQUI IRIA TODA LA EXPLICACION A TRAVES DE UN EJEMPLO Y DEMOSTRANDO CADA CASO A TENER EN CUENTA **


 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) return false;

    vector<int> alturas(N), esquis(N);

    for (int i = 0; i < N; i++) cin >> alturas[i];
    for (int i = 0; i < N; i++) cin >> esquis[i];
   
    sort(alturas.begin(), alturas.end(), less<int>());
    sort(esquis.begin(), esquis.end(), less<int>());

    int minDiferencia = 0;

    for (int i = 0; i < N; i++) {
        minDiferencia += abs(alturas[i] - esquis[i]);
    }

    cout << minDiferencia << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
