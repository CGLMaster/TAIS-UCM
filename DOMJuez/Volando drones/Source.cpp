
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

    A la hora de plantear el ejercicio, he decidido crear un struct tDron, el cual es un dron que va a almacenar los dos tipos de pila.
    Empezamos rellenando cada una de las colas de prioridad de los distintos tipos de pilas.
    Una vez tenemos dichas colas, vamos a recorrer por cada sábado quelos drones puedan volar, es decir siempre y cuando tenga de ambos tipos de pilas disponibles.
    Seguido introducimos las pilas que podamos a cada uno de los drones disponibles (no siempre tendría porque todos los drones tener pilas), y al introducir dichas pilas
    se eliminan de sus colas.
    Por último recorremos los drones disponibles, averiguando cuanto es el tiempo mínimo que tiene cada uno de vuelo, y dicho tiempo acumulandolo para sacarlo por pantalla.
    En función de que pila dure menos, la que dure más se verá reducida del tiempo que haya estado volando y se volverá a añadir a su respectiva cola de prioridad.

    El coste de la función en el peor de los casos es O(max(A,B) * (N * (log(A) + log(B) + N))), donde A es el número de pilas de 9V, B el número de pilas de 1.5V y N el número
    de drones disponibles.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

//Creo una clase para cada dron
typedef struct {
    int pila9;
    int pila15;
}tDron;

bool resuelveCaso() {
    int N, A, B;
    cin >> N >> A >> B;
    if (!cin) return false;

    // Cola para las pilas 9V
    priority_queue <int> V9;
    // Cola para las pilas 1.5V
    priority_queue<int> V15;

    int x;
    //Introducimos las pilas 9V
    for (int i = 0; i < A; i++) {           //O(log(A))
        cin >> x;
        V9.push(x);
    }
    //Introducimos las pilas 1.5V
    for (int i = 0; i < B; i++) {           //O(log(B))
        cin >> x;
        V15.push(x);
    }

    //Recorro los sábados que puedan volar los drones, es decir aquellos que tengan pilas de ambos voltajes disponibles
    while (!V9.empty() && !V15.empty()) {      //O(max(A,B) * (N * (log(A) + log(B) + N)))
        vector<tDron> drones;
        int i = 0;

        //Introducimos las pilas a los drones, y quitamos dichas pilas de sus colas
        while (!V9.empty() && !V15.empty() && i < N) {         //O(N * (log(A) + log(B) + N))
            tDron d;
            d.pila9 = V9.top();             //O(1)
            V9.pop();                       //O(log(A))
            d.pila15 = V15.top();          //O(1)
            V15.pop();                     //O(log(B))
            drones.push_back(d);            //O(N)
            i++;
        }

        int tiempo = 0;

        //Recorro cada uno de los drones
        for (int j = 0; j < drones.size(); j++) {               //O(N * (log(A) + log(B)))
            if (drones[j].pila9 > drones[j].pila15) { // Si la pila de 9V dura más horas que la pila 1.5V
                //El tiempo máximo de ese dron va a ser el de la pila que lo restringe en este caso la pila 1.5V
                tiempo += drones[j].pila15;
                //El tiempo restante de la pila 9V se vuelve a introducir en su cola para utilizarse otra vez hasta acabarlo
                V9.push((drones[j].pila9 - drones[j].pila15));      //O(log(A))
            }
            else if (drones[j].pila9 < drones[j].pila15) { // Si la pila de 1.5V dura más horas que la pila 9V
                //El tiempo máximo de ese dron va a ser el de la pila que lo restringe en este caso la pila 9V
                tiempo += drones[j].pila9;
                //El tiempo restante de la pila 1.5V se vuelve a introducir en su cola para utilizarse otra vez hasta acabarlo
                V15.push((drones[j].pila15 - drones[j].pila9));    //O(log(B))
            }
            else tiempo += drones[j].pila9; // En este caso ambas pilas duran el mismo tiempo, luego al acabarse a la vez, ninguna vuelve a su respectiva cola
        }
        //Se muestra las horas totales en las que vuelan los drones
        cout << tiempo << " ";
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
