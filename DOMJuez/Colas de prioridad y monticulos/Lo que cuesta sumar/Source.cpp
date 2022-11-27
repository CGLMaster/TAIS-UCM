
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


/*@ <answer>
    
    A la hora de realizar la función, he pensado el ejercicio como que tienes que ordenarlo de menor a mayor, ya que así saldrán resultados más bajos.
    Para ello la forma en la que la he desarrollado ha sido obteniendo por cada vuelta del bucle los dos primeros valores de la cola y sumándolos, dicha suma la he sumado al total y
    he vuelto a guardar dicha suma obtenida en la cola.
    Este proceso se produce sucesivamente hasta que solo se encuentra un único valor en la cola, en cuyo caso ya se devuelve la suma total para mostrarse por pantalla.
    
    El coste de la función en el peor de los casos es O(log(N)*(N+M)), donde N es el número de elementos de la cola y M es el número de veces que la cola tiene más de 1 elemento

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

long long int suma(priority_queue<long long int, vector<long long int>, greater<long long int>>& cola) {
    long long int sum = 0, aux1, aux2;
    while (cola.size() > 1) { // O(M)
        aux1 = 0, aux2 = 0;
        aux1 += cola.top(); // O(1)
        cola.pop(); // O(log(N))
        aux2 += cola.top(); // O(1)
        cola.pop(); // O(log(N))

        aux1 += aux2;
        sum += aux1;
        cola.push(aux1); // O(log(N))
    }
    return sum;
}

bool resuelveCaso() {
    int num;
    cin >> num;
    if (num == 0) return false;
    priority_queue<long long int, vector<long long int>, greater<long long int>> cola;
    for (int i = 0; i < num; i++) { // O(N)
        long long int n;
        cin >> n;
        cola.push(n); // O(log(N))
    }
    long long int s = suma(cola);
    cout << s << "\n";
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
