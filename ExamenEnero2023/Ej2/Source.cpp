/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Nombre y Apellidos: Carlos G�mez L�pez
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits>
/*INCLUDES QUE HE A�ADIDO*/
#include "Matriz.h"
#include "EnterosInf.h"
using namespace std;


/*@ <answer>

 El coste de la funci�n en el peor de los casos es O(k*s), siendo k el numero de caras del dado, y s la suma a la que llegar.
 El coste en espacio adicional es O(s), ya que uso un vector en vez de una matriz

 Recursion del ejercicio:

 formas(i,j) : n�mero m�ximo de formas para conseguir el n�mero j considenrando los tipos de caras de 1 a i
                
             { dados(i,0) = 0
 formas(i,j) { dados(0,j) = 0
             { dados(i-1,j) si Ci > j
             { dados(i-1,j) + dados(i, j-Ci) si Ci <= j

 Casos Base:
  dados(i,0) = 0
     En el caso de que haya caras pero no haya un n�mero al que querer alcanzar, se realizaran 0 formas
  dados(0,j) = 0
     En el caso de que se tenga un n�mero al que querer alcanzar pero no caras, se realizaran 0 formas

 Casos Recursivos:
  dados(i,j) = dados(i-1,j) si Ci > j
    En el caso de que dicha cara ya no pueda restar mas a la cantidad alcanzable j, entonces se cambia de cara
  dados(i,j) = dados(i-1,j) + dados(i, j-Ci) + 1 si Ci <= j
    En el caso de que se pueda seguir tirando, se suma tanto el si se tira como si se cambia de cara
 @ </answer> */

 // ========================================================================
 // Escribe el c�digo completo de tu soluci�n debajo de la etiqueta <answer>
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
//  Lo que se escriba dejado de esta l�nea ya no forma parte de la soluci�n.

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
