
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

 Resolvemos el problema por programación dinámica basándonos en la siguiente
 recurrencia:

 disparos(i,j) = número de disparos para conseguir la puntuación j
                 si podemos utilizar los sectores del 1 al i

 Un caso básico es que queramos conseguir la puntuación 0, en ese caso
 no necesitamos disparos:

 disparos(i,0) = 0

 Otro caso básico es que no tengamos sectores que podamos utilizar y queramos
 conseguir una suma j > 0. En ese caso no hay solución, lo que representamos
 con infinito:

 disparos(0,j) = INF si j > 0

 En los casos recursivos distinguimos según podamos o no utilizar el sector i
 para conseguir la puntuación total j. Si puntos[i] > j entonces solamente
 podremos buscar soluciones que no utilicen el sector i, y lo hagan lo mejor
 posible con el resto de sectores, del 1 al i-1:

 disparos(i,j) = disparos(i-1, j)  si puntos[i] > j  // el sector i no se puede usar

 Si sí podemos utilizar el sector i, probamos las dos opciones, usarlo e intentar
 conseguir el resto (j - puntos[i]) con los mismos sectores (del 1 al i), habiendo
 sumado un disparo más, o intentar conseguir la puntución j sin utilizar el sector i.
 Nos quedamos con la mejor solución, la menor:

 disparos(i,j) = min(disparos(i-1, j), // no usamos el sector i
                     disparos(i, j - puntos[i]) + 1)  // sí usamos el sector i

 La llamada inicial sería disparos(S, V).

 Implementamos la función de manera ascendente rellenando una tabla de tamaño
 (S+1)*(V+1), de arriba abajo y de izquierda a derecha.

 Una vez rellena podemos reconstruir la solución retrocediendo desde la última casilla.

 La complejidad está en O(S*V) tanto en tiempo como en espacio, ya que utilizamos una
 matriz de ese tamaño que se recorre completamente y cada celda se calcula con un coste
 constante. La reconstrucción de la solución recorre la matriz retrocediendo siempre
 al menos una fila y una columna, por lo que su coste está en O(max(S,V)).

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

const int INF = 1000000000;

bool resuelveCaso() {
    int V, S;
    cin >> V >> S;
    if (!cin)
        return false;

    vector<int> puntos(S + 1); 
    for (int i = 1; i <= S; ++i) {
        cin >> puntos[i];
    }

    // las puntuaciones nos las dan ordenadas de menor a mayor,
    // si no habría que ordenarlas para recuperar la solución deseada

    vector<vector<int>> disparos(S + 1, vector<int>(V + 1, INF));
    // primera columna
    for (int i = 0; i <= S; ++i)
        disparos[i][0] = 0;
    // rellenar casos recursivos
    for (int i = 1; i <= S; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (puntos[i] > j)
                disparos[i][j] = disparos[i - 1][j];
            else
                disparos[i][j] = min(disparos[i - 1][j], disparos[i][j - puntos[i]] + 1);
        }
    }
    int valor = disparos[S][V];
    if (valor == INF) { // no es posible conseguir la puntuación V
        cout << "Imposible\n";
    }
    else {
        cout << valor << ':';
        // reconstruir solución, se prefieren puntuaciones altas
        int i = S, j = V;
        while (j > 0) {
            if (puntos[i] <= j && disparos[i][j] == disparos[i][j - puntos[i]] + 1) {
                // usamos un disparo más del sector i
                cout << ' ' << puntos[i];
                j -= puntos[i];
            }
            else { // descartamos el sector i
                --i;
            }
        }
        cout << '\n';
    }
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
