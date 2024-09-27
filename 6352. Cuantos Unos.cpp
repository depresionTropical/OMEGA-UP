/*
Un número en base 2 contiene sólo 1's y 0's. Por ejemplo el número 6 en base 2 se escribe como 110
Escribe un programa que dado un número en base 10, escriba cuantos 1's tiene al escribirlo en base 2.
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // Leer el número en base 10
    int count = __builtin_popcount(n);  // Contar la cantidad de 1's en la representación binaria
    cout << count << endl;  // Imprimir el resultado
    return 0;
}
