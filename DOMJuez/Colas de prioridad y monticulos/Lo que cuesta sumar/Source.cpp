
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;


/*@ <answer>
    
    A la hora de realizar la funci�n, he pensado el ejercicio como que tienes que ordenarlo de menor a mayor, ya que as� saldr�n resultados m�s bajos.
    Para ello la forma en la que la he desarrollado ha sido obteniendo por cada vuelta del bucle los dos primeros valores de la cola y sum�ndolos, dicha suma la he sumado al total y
    he vuelto a guardar dicha suma obtenida en la cola.
    Este proceso se produce sucesivamente hasta que solo se encuentra un �nico valor en la cola, en cuyo caso ya se devuelve la suma total para mostrarse por pantalla.
    
    El coste de la funci�n en el peor de los casos es O(log(N)*(N+M)), donde N es el n�mero de elementos de la cola y M es el n�mero de veces que la cola tiene m�s de 1 elemento

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
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
