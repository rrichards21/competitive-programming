//Codigo comentado y sacado de https://onlinejudgesolution.blogspot.com/2017/05/uva-solution-416-led-test-volume-4.html
#include <stdio.h>

//Digitos originales
char g[10][8] = {
"YYYYYYN",//0
"NYYNNNN",//1
"YYNYYNY",//2
"YYYYNNY",//3
"NYYNNYY",//4
"YNYYNYY",//5
"YNYYYYY",//6
"YYYNNNN",//7
"YYYYYYY",//8
"YYYYNYY",//9
};

int main() {
    int n, i, j, k;
    //Arreglo que contendrá el input
    char a[20][8];
    while(scanf("%d", &n) == 1 && n) {
        //Lee las secuencias del caso actual
        for(i = 0; i < n; i++)
            scanf("%s", &a[i]);
        int flag = 0;
        //Itera sobre la secuencia actual
        for(i = 9; i >= n-1; i--) {
            //Crea un arreglo "booleano" que contendrá los posibles leds defectuosos
            //inicialmente ninguno estará defectuoso
            int bad[10] = {};
            //Este for itera sobre los leds de la secuencia actual
            for(j = 0; j < n; j++) {
                //Este for prueba las posibles opciones de ser para el caracter (led) actual
                for(k = 0; k < 7; k++) {         
                    //Si el caracter actual se encuentra defectuoso (por iteraciones anteriores)
                    //y el input ingresado dice que está encendido, entonces se termina la iteracion           
                    if(bad[k] && a[j][k] == 'Y')
                        break;
                    //Marca el caracter actual como defectuoso 
                    if(a[j][k] == 'N' && g[i-j][k] == 'Y')
                        bad[k] = 1;
                    //Termina las iteraciones (k) si es que el caracter actual del input
                    //es distinto al caracter del digito original
                    else if(a[j][k] == 'Y' && g[i-j][k] == 'N')
                        break;
                }
                //Si se termina el 3er for sin haber probado todas sus posibilidades
                //entonces se termina el 2do for
                if(k != 7)  break;
            }
            //Si se lograron probar todas las opciones entonces se tiene un match
            if(j == n) {
                flag = 1;
                break;
            }
        }
        //Se imprime el resultado
        if(!flag)
            printf("MIS");
        puts("MATCH");
    }
    return 0;
}