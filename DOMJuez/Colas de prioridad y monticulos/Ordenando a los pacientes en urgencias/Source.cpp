
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos G�mez L�pez
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

/*@ <answer>

    A la hora de realizar el ejercicio he pensado en introducir en la cola un struct, llamado tPaciente, el cual va a contener
    el nombre del paciente, nivel de gravedad y la hora de entrada.
    A la hora de introducir los datos he hecho como en ejercicios anteriores, es decir push() del tPaciente en la cola prioritaria
    y luego para leerlo top() y pop() del tPaciente m�s prioritario.
    Para saber cu�l es m�s prioritario me baso en que tienen que ir m�s prioritario el que m�s gravedad tiene y despu�s en caso de
    que tengan las misma gravedad, lo compruebo con el momento de entrada del paciente.
    
    El coste de la funci�n en el caso peor es O(N*log(N)), donde N es el n�mero de pacientes en la cola.

 @ </answer> */


 // ================================================================
 // Escribe el c�digo completo de tu soluci�n aqu� debajo
 // ================================================================
 //@ <answer>

typedef struct {
    string nombre;
    int gravedad;
    int entrada;
}tPaciente;

bool operator<(tPaciente const& a, tPaciente const& b) {
    return a.gravedad < b.gravedad || (a.gravedad == b.gravedad && b.entrada < a.entrada);
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;
    priority_queue<tPaciente> pEsperando;
    string letra;
    for (int i = 0; i < n; i++) { // O(N) 
        cin >> letra;
        if (letra == "A") { // O(log(N))
            cout << pEsperando.top().nombre << "\n";
            pEsperando.pop();

        }
        else { // O(log(N))
            tPaciente p;
            cin >> p.nombre >> p.gravedad;
            p.entrada = i;
            pEsperando.push(p);
        }
    }
    cout << "---\n";
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
