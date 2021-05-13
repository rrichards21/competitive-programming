#include <stdio.h>

int n, m, V[1000];
//Esta funcion probara si es que una determinada capacidad es una posible respuesta, pero no si es que es la correcta
int judge(int c) {
    int cap = 0, cnt = 0;
    int i = 0;
    for(i = 0; i < n; i++) {
        if(V[i] > c)    //Salimos de la funcion ya que estamos sobre la capacidad con la botella i
            return 1000000;
        if(cap < V[i]){
            cap = c, cnt++; //se cambia la capacidad actual ya que posee menos capacidad que la de la botella i
                            //tambien se cambia al siguiente contenedor (cnt)
        }
        cap -= V[i];    //Se le quita la capacidad de la botella i a la capacidad actual
                        //para simular que se vacio e la botella i sobre el contenedor actual.
    }
    return cnt; //se retorna la cantidad de contenedores utilizados
}

int main() {
    int i;
    while(scanf("%d %d", &n, &m) == 2) {
        for(i = 0; i < n; i++)
            scanf("%d", &V[i]);
        int left = 1, right = 1000000*n, mid;
        int r;
        //Se realiza busqueda binaria entre posibles capacidades de 1 - 1e6n
        //que se usara para encontrar la capacidad maxima requerida para el problema
        while(left < right) {
            mid = (left + right) >> 1;
            r = judge(mid); //Prueba la capacidad
            if(r > m)   //Si la cantidad de contenedores es mayor que m, se cambia el limite izquierdo para probar con una capacidad mayor.
                left = mid+1;
            else    //En el caso contrario se buscara una capacidad menor
                right = mid;
        }
        printf("%d\n", left);
    }
    return 0;
}