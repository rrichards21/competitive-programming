//Codigo comentado y sacado de https://github.com/IElgohary/Uva-solutions/blob/master/11961%20-%20DNA.cpp
#include <iostream>
#include <set>
#include <string>

using namespace std;

#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

int t , n , k;
//Set que contendrá las soluciones a las mutaciones de una sequencia
set<string> st;
//Esto contiene la secuencia a mutar
string a;

void genseq(string s , int num, int ind)
{
    //Retorna cuando se alcanza el limite de mutaciones posibles
	if (num > k ) return;
    //Añade a st (solution) el string generado actual y termina cuando se
    //alcanza la longitud de secuencia pedida (n)
	if (ind == n )
	{
		st.insert(s);
		return;
	}
    //Añade a la secuencia actual ('s') cada uno de los caracteres A,C,G,T
    //en primera instancia se va a generar el string AAA...A
    //luego se generarán los siguientes AAA...C, AAA...G
    //Esto verifica si la posicion (ind) actual es igual al caracter mutado
    //de esta manera se generarán todas las posibles mutaciones para la secuencia 'a'
	genseq(s+'A', (a[ind] == 'A')? num: num+1, ind+1);
	genseq(s+'C', (a[ind] == 'C')? num: num+1, ind+1);
	genseq(s+'G', (a[ind] == 'G')? num: num+1, ind+1);
	genseq(s+'T', (a[ind] == 'T')? num: num+1, ind+1);
}

int main()
{
	cin >> t;
	while ( t--)
	{
		st.clear();
		cin >> n >> k >> a;
        //Inicia el backtrack con un string vacio
		genseq("" , 0, 0);
		cout << st.size()<< endl;
        //Recorre la solucion y la imprime
		FOREACH(st){
			cout<<*it<<endl;
		}
	}
}