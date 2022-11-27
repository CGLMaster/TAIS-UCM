
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

 Resolvemos el problema por programaci�n din�mica bas�ndonos en la siguiente
 recurrencia:

 disparos(i,j) = n�mero de disparos para conseguir la puntuaci�n j
                 si podemos utilizar los sectores del 1 al i

 Un caso b�sico es que queramos conseguir la puntuaci�n 0, en ese caso
 no necesitamos disparos:

 disparos(i,0) = 0

 Otro caso b�sico es que no tengamos sectores que podamos utilizar y queramos
 conseguir una suma j > 0. En ese caso no hay soluci�n, lo que representamos
 con infinito:

 disparos(0,j) = INF si j > 0

 En los casos recursivos distinguimos seg�n podamos o no utilizar el sector i
 para conseguir la puntuaci�n total j. Si puntos[i] > j entonces solamente
 podremos buscar soluciones que no utilicen el sector i, y lo hagan lo mejor
 posible con el resto de sectores, del 1 al i-1:

 disparos(i,j) = disparos(i-1, j)  si puntos[i] > j  // el sector i no se puede usar

 Si s� podemos utilizar el sector i, probamos las dos opciones, usarlo e intentar
 conseguir el resto (j - puntos[i]) con los mismos sectores (del 1 al i), habiendo
 sumado un disparo m�s, o intentar conseguir la puntuci�n j sin utilizar el sector i.
 Nos quedamos con la mejor soluci�n, la menor:

 disparos(i,j) = min(disparos(i-1, j), // no usamos el sector i
                     disparos(i, j - puntos[i]) + 1)  // s� usamos el sector i

 La llamada inicial ser�a disparos(S, V).

 Implementamos la funci�n de manera ascendente rellenando una tabla de tama�o
 (S+1)*(V+1), de arriba abajo y de izquierda a derecha.

 Una vez rellena podemos reconstruir la soluci�n retrocediendo desde la �ltima casilla.

 La complejidad est� en O(S*V) tanto en tiempo como en espacio, ya que utilizamos una
 matriz de ese tama�o que se recorre completamente y cada celda se calcula con un coste
 constante. La reconstrucci�n de la soluci�n recorre la matriz retrocediendo siempre
 al menos una fila y una columna, por lo que su coste est� en O(max(S,V)).

 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
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
    // si no habr�a que ordenarlas para recuperar la soluci�n deseada

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
    if (valor == INF) { // no es posible conseguir la puntuaci�n V
        cout << "Imposible\n";
    }
    else {
        cout << valor << ':';
        // reconstruir soluci�n, se prefieren puntuaciones altas
        int i = S, j = V;
        while (j > 0) {
            if (puntos[i] <= j && disparos[i][j] == disparos[i][j - puntos[i]] + 1) {
                // usamos un disparo m�s del sector i
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
//  Lo que se escriba debajo de esta l�nea ya no forma parte de la soluci�n.

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
