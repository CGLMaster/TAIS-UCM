/*
 * MUY IMPORTANTE: Solo se corregirón los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Carlos Gómez López
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
/*INCLUDES QUE HE AÑADIDO*/
#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;


/*@ <answer>

 El coste de la función en el peor de los casos es O(k*s), siendo k el numero de caras del dado, y s la suma a la que llegar.
 El coste en espacio adicional es O(s), ya que uso un vector en vez de una matriz

 Recursion del ejercicio:

 formas(i,j) : número máximo de formas para conseguir el número j considenrando los tipos de caras de 1 a i
                
             { formas(i,0) = 0
 formas(i,j) { formas(0,j) = 0
             { formas(i-1,j) si Ci > j
             { formas(i-1,j) + formas(i, j-Ci) si Ci <= j

 Casos Base:
  formas(i,0) = 0
     En el caso de que haya caras pero no haya un número al que querer alcanzar, se realizaran 0 formas
  formas(0,j) = 0
     En el caso de que se tenga un número al que querer alcanzar pero no caras, se realizaran 0 formas

 Casos Recursivos:
  formas(i,j) = formas(i-1,j) si Ci > j
    En el caso de que dicha cara ya no pueda restar mas a la cantidad alcanzable j, entonces se cambia de cara
  formas(i,j) = formas(i-1,j) + formas(i, j-Ci) si Ci <= j
    En el caso de que se pueda seguir tirando, se suma tanto el si se tira como si se cambia de cara
 @ </answer> */

 // ========================================================================
 // Escribe el código completo de tu solución debajo de la etiqueta <answer>
 // ========================================================================
 //@ <answer>

int numFormas(const int& k, int s) {
      
    vector<int> formas(s + 1, 0);
    formas[0] = 1;
    // calcular la matriz sobre el propio vector
    for (int i = 1; i <= k; ++i) {
        for (int j = i; j <= s; ++j) {
            formas[j] = formas[j] + formas[j - i];
        }
    }

    return formas[s];
}

void resuelveCaso() {

    int k, s;
    cin >> k >> s;

    auto sol = numFormas(k, s);

    cout << sol << "\n";

}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos2.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // system("PAUSE");
#endif
    return 0;
}
