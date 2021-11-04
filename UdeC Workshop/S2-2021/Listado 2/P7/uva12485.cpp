/*
Autor: KHvic
Perfect Choir - 12485
rrichards - 958045
Código obtenido de https://github.com/KHvic/uva-online-judge/blob/master/12485-Perfect%20Choir.cpp
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,v;
    while(scanf("%d",&n) != EOF){
        vector<int> members;
        //Inicializa una variable para obtener la suma de las notas de todos los miembros
        int sum = 0;
        for(int i=0;i<n;i++){
            cin >> v;
            members.push_back(v);
            //Realiza la suma de todos los miembros mientras lee
            sum += v;
        }
        //La suma dividida debe ser divisible entre todos los miembros
        //Ya que una cantidad que no es divisible, no permitirá que se
        //puedan acomodar todas las notas
        if(sum%n == 0){
            //Obtiene el promedio de todas las notas
            int avg = sum/n;
            int error = 0;
            //Obtiene la diferencia entre el miembro actual con el promedio, de esta manera
            //se obtiene la cantidad de veces que el miembro actual debe cambiar su nota
            for(auto& member : members) error += abs(avg-member); 
            //Se imprime 1+error/2 porque el error contempla las veces que un miembro debe cambiar su nota
            //pero cuando un miembro cambia su nota, otro también debe de hacerlo
            printf("%d\n",1+error/2);
        } 
        //Imprime -1 cuando no es posible acomodar las notas
        else printf("-1\n");
    }
}