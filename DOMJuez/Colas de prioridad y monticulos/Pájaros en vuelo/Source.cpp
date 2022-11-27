
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gomez Lopez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

    Para plantear este problema, tienes que pensar que la punta de la flecha que forman los pájaros va a ser la mediana, por lo que por cada uno que introduzcas tendrás que comprobar
    si es una nueva mediana o no.
    Para ello he creado la clase Mediana, la cual esta compuesta por dos colas de prioridad, de las cuales una van a ser los números más pequeños que la mediana (izq) y la otra 
    los números más grandes que la mediana (der).
    A la hora de introducir el primer elemento, al no haber más va a ser la mediana, y la forma en la que lo planteo es que el top de der va a ser siempre la mediana.
    A medida que añades elementos, compruebas si son mayores o menores que la mediana (der.top()), en función de si el tamaño de cada una de las ramas esta descompensado, entonces se
    "reordena" y actualiza la mediana.
    Una vez introducida la pareja, se obtiene y muestra la mediana almacenada en el top de der.

    El coste de la función en el peor de los casos es O(P*(log(N)+log(M))), donde P es el número de parejas a recorrer, N el número de elementos en la cola de máximos y
    M el número de elementos en la cola de mínimos.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

class Mediana {
    private:
        priority_queue<int, vector<int>, greater<int>> der;
        priority_queue<int, vector<int>, less<int>> izq;
        
        void reordenar() {  // La función tiene coste O(log(N) + log(M))
            if (izq.size() == der.size() + 1) { 
                der.push(izq.top()); // O(log(N))
                izq.pop(); // O(log(M))
            }
            else if (izq.size() + 2 == der.size()) {
                izq.push(der.top()); // O(log(M))
                der.pop(); // O(log(N))
            }
        }

    public:
        void push(const int& x) { // La función tienen coste O(log(N) + log(M))
            if (der.empty()) der.push(x); // O(log(N))
            else {
                if (x > der.top()) der.push(x); // O(log(N))
                else izq.push(x); // O(log(M))
            }
            reordenar();
       }

        int mediana() { // La función tiene coste O(1)
            return der.top(); // O(1)
        }

};

 bool resuelveCaso() {

    int M, P;
    cin >> M >> P;
    if (M == 0 && P == 0) return false;
    Mediana m;
    m.push(M);
    for (int i = 0; i < P; i++) { // O(P*(log(N)+log(M)))
        int n1, n2;
        cin >> n1 >> n2;
        m.push(n1); m.push(n2);
        int mediana = m.mediana();
        cout << mediana;
        if (i != P - 1) std::cout << " ";
    }
    cout << "\n";

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
