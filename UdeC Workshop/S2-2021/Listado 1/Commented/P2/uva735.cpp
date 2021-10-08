//Código comentado y sacado de https://github.com/ksaveljev/UVa-online-judge/blob/master/735.cpp
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;

#define pow2(i) (1<<i)
#define bit(i) (1<<i)
#define isOdd(i) (i&1)
#define isEven(i) (!(i&1))
#define sz(i) i.size()
#define REP(i, b, n) for (int i = b; i < n; i++)
#define REPI(i, b, n) for (int i = b; i <= n; i++)
#define rep(i, n) REP(i, 0, n)
#define repi(i, n) REPI(i, 0, n)

int main(void) {
    int n;
    set<int> scores;
    //Arreglo para ver las combinaciones posibles
    bool taken[61][61][61];

    scores.insert(50);

    //Genera los posibles scores dependiendo de donde cae el dardo
    //Son entre 1 y 20 y pueden duplicarse (i*2) o triplicar (i*3)
    //Bullseye (score 50) también se encuentra dentro de las opciones (i = 15 * 2)
    repi (i, 20) {
        scores.insert(i);
        scores.insert(i*2);
        scores.insert(i*3);
    }

    vector<int> values(scores.begin(), scores.end());

    while (cin >> n) {
        if (n <= 0) {
            cout << "END OF OUTPUT" << endl;
            break;
        }

        //Marca el arreglo de combinaciones como falso para poder marcar las posibles combinaciones de las permutaciones encontradas
        memset(taken, false, sizeof(taken));

        int combinations = 0, permutations = 0;

        //Genera todas las permutaciones de los scores para los 3 dardos
        rep (i, values.size()) {
            rep (j, values.size()) {
                rep (k, values.size()) {
                    //Verifica si es que es posible generar el score (n) con la permutación actual
                    if (values[i] + values[j] + values[k] != n) continue;
                    //Si fue posible suma al contador de permutaciones
                    permutations++;

                    //Verifica si la permutación actual no ha sido ingresada todavía dentro del arreglo de combinaciones
                    //Si no ha sido ingresada, marca las posibles combinaciones de la permutación para que no puedan ser
                    //ingresadas a futuro, de manera que las permutaciones que sean iguales pero con otra disposicion de posiciones
                    //se marquen como ocupadas 
                    if (!taken[values[i]][values[j]][values[k]]) {
                        taken[values[i]][values[j]][values[k]] = true;
                        taken[values[i]][values[k]][values[j]] = true;
                        taken[values[j]][values[i]][values[k]] = true;
                        taken[values[j]][values[k]][values[i]] = true;
                        taken[values[k]][values[i]][values[j]] = true;
                        taken[values[k]][values[j]][values[i]] = true;
                        combinations++;
                    }
                }
            }
        }

        //Imprime el resultado final dependiendo de si fue posible encontrar alguna combinación y permutaciones posibles
        if (combinations == 0 && permutations == 0) {
            cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        } else {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << combinations << "." << endl;
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << permutations << "." << endl;
        }
        cout << "**********************************************************************" << endl;
    }

    return 0;
}