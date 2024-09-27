/* Descripción

Una secuencia de cuatro dígitos es simétrica si el primer dígito es igual al último y el segundo dígito es igual al tercero. Por ejemplo, la secuencia 1 2 2 1 es simétrica mientras que la secuencia 1 2 2 3 no lo es. Escribe un programa que lea una secuencia de cuatro dígitos y calcule si es o no simétrica.
Entrada

Cuatro enteros de un dígito separados por espacios.
Salida

El valor 1 si la secuencia dada es simétrica o el valor  0 en caso contrario.*/
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == d && b == c) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}