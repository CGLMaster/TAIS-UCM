/*
 * MUY IMPORTANTE: Solo se corregir�n los comentarios y el c�digo
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificaci�n fuera de esas etiquetas no ser� corregida.
 */

 /*@ <answer>
  *
  * Indicad el nombre completo y usuario del juez de quienes hab�is hecho esta soluci�n:
  * Estudiante 1: Carlos G�mez L�pez TAIS45
  * Estudiante 2: Clara Sotillo Sotillo TAIS96
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "Matriz.h";

/*@ <answer>
    
    El coste en tiempo de la funci�n en el peor de los casos es O(N*P), siendo N el n�mero de festivales distintos que ha
    seleccionado Sergio y P el presupuesto del que dispones Sergio.
    El coste en espacio en el peor de los casos es O(P), siendo P el presupuesto del que dispones Sergio.

    Primero lo que hemos hecho ha sido pensar en la recurrencia del ejercicio, obteniendo lo siguiente:

    conciertos(i,j) = es el n�mero de conciertos de i festivales que podemos ver con el presupuesto j

                        { conciertos(i,0) = 0
    conciertos(i,j) =   { conciertos(0,j) = 0
                        { conciertos(i-1,j)                                                     si precio[i] < j
                        { max(conciertos(i-1,j), conciertos(i,j-precio[i]) + grupos[i])         si precio[i] >= j

    Tenemos dos casos bases:

     - El primero es el caso en el que tiene festivales seleccionados, pero no tiene presupuesto para ver ninguno, en ese caso
       no necesitamos ver conciertos:

       conciertos(i,0) = 0

     - El segundo es el caso en el que tiene presupuesto para ver festivales, pero no tiene ning�n festival seleccionado,
       entonces no necesitariamos ver conciertos:

       conciertos(0,j) = 0

    Dentro de los casos recursivos podemos distinguir otros dos:

     - Si el precio de dicho festival es menor que el dinero del que dispone, entonces solo podremos buscar
       soluciones que no utilicen el festival i, y lo hagan mejor posible con el resto de festivales, del 1 al i-1:

       conciertos(i,j) = conciertos(i-1,j)  si precio[i] < j

     - Si el precio de dicho festival es mayor o igual que el dinero del que dispone, probamos dos opciones:
        Intentar ver el m�ximo n�mero de festivales con el presupuesto j, sin ver el festival i
                                                    �
        Usarlo e intentar conseguir el resto (j - precio[i]) con los mismos festivales (del 1 al i), habiendo sumado el n�mero
        de grupos que participan en el festival i (grupos[i]).

        Nos quedamos con la menjor soluci�n, la mayor:

        conciertos(i,j) = max(conciertos(i-1,j), conciertos(i,j-precio[i]) + grupos[i])   si precio[i] >= j


    Implementamos la funci�n de manera ascendente rellenando la tabla de tama�o (N+1)(P+1), de arriba a abajo y de izquierda a derecha.
    Es ascendente ya que recorres de los que tienen menor presupuesto a los que m�s tienen.

    Una vez rellena podemos reconstruir la soluci�n retrocediendo desde la �ltima casilla.
        

 @ </answer> */

 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo (despu�s de la marca)
 //@ <answer>

typedef struct {
    int grupos;
    int precio;
}tFestival;


void gruposAVisitar(vector<tFestival> festivales, int N, int P) {

    /* MATRIZ */

   /* Matriz<int> visitar(N + 1, P + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= P; j++) {
            if (j >= festivales[i - 1].precio) visitar[i][j] = max(visitar[i - 1][j], visitar[i - 1][j - festivales[i - 1].precio] + festivales[i - 1].grupos);
            else visitar[i][j] = visitar[i - 1][j];
        }
    }

    cout << visitar[N][P] << "\n";*/

    /* VECTOR */

    vector<int> visitar(P + 1, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = P; j >= festivales[i - 1].precio; j--) {
            visitar[j] = max(visitar[j], visitar[j - festivales[i - 1].precio] + festivales[i - 1].grupos);
        }
    }

    cout << visitar[P] << "\n";

}

bool resuelveCaso() {

    int P, N;
    cin >> P >> N;  // presupuesto y n�mero de festivales

    if (!cin) return false;

    vector<tFestival> festivales(N);
    for (int i = 0; i < N; i++) cin >> festivales[i].grupos >> festivales[i].precio;

    gruposAVisitar(festivales, N, P);

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
