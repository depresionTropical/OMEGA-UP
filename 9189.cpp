#include <iostream>
#include <cmath> // Para la función abs()

using namespace std;

int main() {
    int N;
    cin >> N; // Leer el número de consultas
    
    // Procesar cada consulta
    int salida[N];
    for (int i = 0; i < N; i++) {
        int P, C;
        cin >> P >> C; // Leer los valores de P y C
        
        // Calcular los dos múltiplos más cercanos
        int Q1 = (P / C) * C;  // Múltiplo de C más cercano que es menor o igual a P
        int Q2 = ((P / C) + 1) * C;  // Múltiplo de C más cercano que es mayor que P
        
        // Si el múltiplo más cercano es exactamente igual a P, ese es el resultado
        if (Q1 == P) {
            // cout << Q1 << endl;
            salida[i] = Q1;
        } else {
            // Comparar las distancias entre P y los múltiplos Q1 y Q2
            int dist1 = abs(P - Q1);
            int dist2 = abs(P - Q2);
            
            // Elegir el múltiplo más cercano (y el más pequeño si las distancias son iguales)
            if (dist1 <= dist2) {
                // cout << Q1 << endl;
                salida[i] = Q1;
            } else {
                // cout << Q2 << endl;
                salida[i] = Q2;

            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << salida[i] << endl;
    }
    return 0;
}
