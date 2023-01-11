
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

/*@ <answer>

    El coste de la funci�n en el peor de los casos es O(N*log(N)), siendo N el n�mero de esquiadores y esquis a emparejar. Este coste viene de la funci�n sort(),
    la cual tiene coste O(N*log(N)).

    Para resolver el ejercicio he empleado un algoritmo voraz V, el cual consiste en ir asignando esquis a esquiadores con una altura, para ello he ordenado ambos
    vectores de menor a mayor, y asi se ha ido asignando los esquis de menor tama�o a los esquiadores con menor altura, provocando una minimizaci�n de suma
    las diferencias entre ambos.

    Comprobaci�n del algoritmo voraz:

    Supongamos la altura de los esquiadores de forma que i <= j --> a[i] <= a[j]
    Supongamos el tama�o de los esquis de forma que i <= j --> e[i] <= e[j]

    Recorremos los esquiadores de menor a mayor altura y el algoritmo voraz V selecciona los esquis de menor tama�o que le proporciona la menor suma de diferencias.
    
    Por tanto, el aspecto de la soluci�n voraz es una secuencia creciente de asignacion de esquis.

    ** AQUI IRIA TODA LA EXPLICACION A TRAVES DE UN EJEMPLO Y DEMOSTRANDO CADA CASO A TENER EN CUENTA **


 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
