#include<cstdio>
#include<stack>
 
using namespace std;
 
void marshal(int N) {
    int c;
    for(;;) {
        stack<int> cars;
        int j = 0;
        for(int i = 0; i < N; i++) {
            //Lee el valor de un carro
            scanf("%d", &c);
            //Termina el caso
            if(c == 0) return;

            //Se deben agregan todos los carros anteriores hasta c,
            //luego c debe salir de la estacion (quitandolo del stack), y así con todos 
            //los carros que siguen.
            //Asi, cualquier carro solicitado que se encuentre debajo de otro carro en el stack
            //no permitira la reorganizacion, por lo que sera imposible ordenar los carros.
            while(j < N && j != c) {
                //Aqui se agrega solo hasta el valor c, si es que no se ha llegado al 
                //largo del tren aun
                if(cars.size() > 0 && cars.top() == c) break;
                j++;
                cars.push(j);
            }

            //Se saca de la estacion el carro c, es decir su organizacion inicial fue valida.
            if(cars.top() == c) cars.pop();
        }
        //Si el stack está vacio, quiere decir que fue posible organizar
        //los carros dado el orden inicial.
        if(cars.size() == 0) printf("Yes\n");
        //En el caso contrario quiere decir que alguno de los carros,
        //quedo en la estacion debido a que la organizacion inicial no era valida.
        else printf("No\n");
    }
}
 
int main() {
    int N;
    for(;;) {
        //Lee el largo del tren
        scanf("%d", &N);
        //Termina el algoritmo
        if(N == 0) break;
 
        marshal(N);
        //Imprime un salto de linea para mostrar el output del siguiente caso
        printf("\n");
    }
}