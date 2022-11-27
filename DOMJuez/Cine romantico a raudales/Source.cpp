
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

/*@ <answer>

    El coste de la funci�n en tiempo en el peor de los casos es O(N^2), donde N es el n�mero de pel�culas posibles para ver.
    El coste de la funci�n en espacio adicional es O(N).

    Recurrencia:

    cine(i) : mayor tiempo que tengo para ver pel�culas de la i a la N - 1
    
    cine(i) =   { cine(i) = 0   si i = N 
                { max(cine(i + 1), di + cine(j))        di: duraci�n de la pel�cula i
                                                        j : es la primera pel�cula que puedes ver tras ver la i
 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

typedef struct {
    int ini;
    int dur;
    int fin;
}tPelicula;

bool operator<(tPelicula const& a, tPelicula const& b) {
    return a.ini < b.ini || (a.ini == b.ini && a.dur < b.dur);
}

bool resuelveCaso() {

    int N;
    cin >> N;
    if (N == 0) return false;
    int h, m, d;
    char c;
    vector<tPelicula> peliculas(N);
    for (int i = 0; i < N; i++) {
        cin >> h >> c >> m >> d;
        peliculas[i] = { h * 60 + m, d ,  h * 60 + m + d };
    }

    sort(peliculas.begin(), peliculas.end());

    vector<int> tiempo(N + 1, 0);
    tiempo[N] = 0;
    for (int i = N - 1; i >= 0; i--) {
        auto j = lower_bound(peliculas.begin(), peliculas.end(), tPelicula{ peliculas[i].fin + 10, 0 , 0 }) - peliculas.begin();
        tiempo[i] = max(tiempo[i + 1], peliculas[i].dur + tiempo[j]);
    }

    cout << tiempo[0] << "\n";
    

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
