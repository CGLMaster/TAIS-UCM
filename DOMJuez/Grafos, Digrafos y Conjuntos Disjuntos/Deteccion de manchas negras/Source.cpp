
/*@ <answer>
 *
 * Nombre y Apellidos: Carlos Gómez López
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


/*@ <answer>

    El coste de la función en el peor de los casos es O(F * C), donde F es el número de filas de la matriz y C el número de columnas.

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

using Mapa = vector<string>;

class Manchas {
public:
    Manchas(Mapa const& M) : F(M.size()), C(M[0].size()), visit(F, vector <bool>(C, false)), num(0), maxim(0) {
        for (int i = 0; i < F; i++) {
            for (int j = 0; j < C; j++) {
                if (!visit[i][j] && M[i][j] == '#') { // se recorre una nueva mancha
                    num++;
                    int nuevotam = dfs(M, i, j);
                    maxim = max(maxim, nuevotam);
                }
            }
        }
    }

    int numero() const { return num; }
    int maximo() const { return maxim; }

private:
    int F, C;
    vector<vector<bool>> visit;
    int num;
    int maxim;

    bool correcta(int i, int j) const {
        return 0 <= i && i < F && 0 <= j && j < C;
    }

    const vector<pair<int, int>> dirs = { {1,0},{0,1},{-1,0},{0,-1} };

    int dfs(Mapa const& M, int i, int j) {          // O(F * C)
        visit[i][j] = true;
        int tam = 1;
        for (auto d : dirs) { //Comprueba los vértices adyacentes
            int ni = i + d.first, nj = j + d.second;
            //Compruebas que las coordenadas sean correctas, sea negro y no esta visitado
            if (correcta(ni, nj) && M[ni][nj] == '#' && !visit[ni][nj]) {
                tam += dfs(M, ni, nj);
            }
        }
        return tam;
    }

};

bool resuelveCaso() {   // O(F * C)

    int F, C;
    cin >> F >> C;

    if (!cin) return false;

    Mapa m(F);

    for (string& linea : m) cin >> linea;

    Manchas manchas(m);
    cout << manchas.numero() << " " << manchas.maximo() << "\n";

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
