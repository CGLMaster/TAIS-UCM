/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Clara Sotillo Sotillo TAIS96
 * Estudiante 2: Carlos Gómez López    TAIS45
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>
 
 A la hora de empezar el ejercicio, hemos guardado todas las cajas en la prority_queue, utilizando i del for para guardar su
 identificador de caja.
 Seguido empezamos a introducir los tiempos de espera de cada cliente, en función del cliente anterior, sumandole a su tiempo el del anterior.
 De esta forma siempre obtendremos el más prioritario, o el que el tiempo sea menor.
 Finalmente se muetra el cajero al que debería ir Ismael.

 El coste de la función en el peor de los casos es O((log(N)*N)+(log(N)*C)), donde N es el número de cajeros y C es el número de clientes.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

typedef struct {
    int tiempo;
    int caja;
}tPersona;

bool operator<(tPersona const& a, tPersona const& b) {
    return b.tiempo < a.tiempo || (b.tiempo == a.tiempo && b.caja < a.caja);
}

bool resuelveCaso() {
  
  // leemos la entrada
  int N, C;
  cin >> N >> C;
  if (N == 0)
    return false;
  
  // leer el resto del caso y resolverlo
  
  priority_queue<tPersona> atendiendo;
  for (int i = 0; i < N; i++) { // O(N*log(N))
      tPersona p;
      p.caja = i + 1;
      p.tiempo = 0;
      atendiendo.push(p);
  }
  for (int i = 0; i < C; i++) {
      int t;
      cin >> t;
      tPersona p = atendiendo.top();
      atendiendo.pop(); 
      atendiendo.push({ t + p.tiempo,p.caja });
  }

  cout << atendiendo.top().caja << "\n";
  
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
  
  // Resolvemos
  while (resuelveCaso());
  
  // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
