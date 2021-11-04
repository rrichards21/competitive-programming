/*
Autor: Steven Kester Yuwono
The Trip, 2007 - 11100
rrichards - 958045
Código obtenido de https://github.com/yulonglong/UVa-Solutions/blob/master/11100.cpp
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10100
using namespace std;

int store[MAX];

int main() {
	int n;
    //Lee la cantidad (N) de equipajes
	while ((scanf("%d",&n)==1) && (n>0)) {
		memset(store,0,sizeof(store));
        //Lee los N equipajes
		for(int i=0;i<n;i++){
			scanf("%d",&store[i]);
		}
        //Realiza un sort para poder ordenar en los for de la línea 38
		sort(store,store+n);

		//Encuentra el máximo número de equipajes que tienen las mismas dimensiones
		int maxLug = -1;
        //Asume un equipaje siempre
		int curr = 1;
		for(int i=0;i<n;i++){
            //Si el actual con el siguiente tienen la misma dimensión
            //Suma a curr y continua con el for
			if(store[i] == store[i+1]) {
				curr++;
				continue;
			}
            //Si encuentra un máximo lo almacena en maxLug
			if (curr > maxLug) maxLug = curr;
            //Reinicia para encontrar los posibles máximos que siguen
			curr = 1;
		}

		// Output with the max num of same sized bags interval
		printf("%d\n",maxLug);
        //Itera por todos los equipajes
		for (int i=0;i<maxLug;i++){
            //Esto sirve para imprimir un espacio entre cada equipaje del input,
            //para cada persona
			bool first = true;
            //Itera desde el equipaje actual y salta maxLug equipajes, de esta manera
            //es no tomará los equipajes que son iguales al actual y solo tomará
            //los equipajes que tengan mayor dimensión que el actual (por el sort de línea 22)
			for (int j=i;j<n;j+=maxLug) {
                //Si es el primer equipaje de una colección de equipajes para una persona
                //no imprime espacio, luego empieza a imprimirlos
				if (first) first = false;
				else  printf(" ");
                //Imprime el equipaje para la respuesta actual
				printf("%d",store[j]);
			}
			printf("\n");
		}
	}
	return 0;
}