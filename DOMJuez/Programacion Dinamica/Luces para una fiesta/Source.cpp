
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez 
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "Matriz.h"  // propios o los de las estructuras de datos de clase
#include "EnterosInf.h"

/*@ <answer>

    bombilla(i,j) : n�mero de bombillas i que utilizas y j la carga que queda

                    { bombilla(0,j) = INF               si j > 0
    bombilla(i,j) = { bombilla(i,0) = 0
                    { bombilla(i,j) = bombilla(i-1,j)   si pi > j
                    { min(bombilla(i,j-pi) + ci, bombilla(i-1,j))

    Al final: for(k = Pmin; k <= Pmax; k++)
                    min(bombilla(i,k))

    El coste de la funci�n en tiempo en el peor de los casos es O(N*PMax), siendo N el n�mero de bombillas y PMax la potencia m�xima.
    El coste de la funci�n en espacio adicional es O(PMax).
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

typedef struct {
    int potencia;
    int coste;
}tBombilla;

int calculandoMinimo(vector<tBombilla> const& bombillas, vector<EntInf>& M, const int & Pmax, const int& Pmin) {
    int N = bombillas.size();
    M[0] = 0;   // Caso base bombilla(i,0) = 0
    for (int i = 1; i <= N; i++) {
        for (int j = bombillas[i - 1].potencia; j <= Pmax; j++)
            M[j] = min(M[j], M[j - bombillas[i - 1].potencia] + bombillas[i - 1].coste); // min(bombilla(i,j-pi) + ci, bombilla(i-1,j))
    }

    int val = Pmin;
    for (int k = Pmin; k <= Pmax; k++) {
        if (M[val] > M[k]) val = k; // min(bombilla(i,k))
    }

    return val;
}

bool resuelveCaso() {

    int N, Pmax, Pmin;
    cin >> N >> Pmax >> Pmin;
    if (!cin) return false;

    vector<tBombilla> bombillas(N);
    for (int i = 0; i < N; i++) cin >> bombillas[i].potencia;
    for (int i = 0; i < N; i++) cin >> bombillas[i].coste;

    vector<EntInf> M(Pmax + 1, Infinito);

    int s = calculandoMinimo(bombillas, M, Pmax, Pmin);

    if (M[s] != Infinito) cout << M[s] << " " << s << "\n";
    else cout << "IMPOSIBLE\n";
    
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
