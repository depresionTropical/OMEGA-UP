#include <iostream>
#include <stdint.h>
// #include <chrono> // Para medir el tiempo

using namespace std;

string cuter(int k, int cupCakes[], int totalSize, int totalSum){
    int s;
    for(int i = 0; i + k < totalSize; i++){
        s = 0;
        for(int j = i; j < i + k; j++){
            s += cupCakes[j];
        }
        if (s >= totalSum){
            return "NO";
        }
    }
    if(k == 0){
        return "YES";
    }
    return cuter(k-1, cupCakes, totalSize, totalSum);
}

int main()
{
    // // Inicia la medición del tiempo
    // auto start = chrono::high_resolution_clock::now();

    int t, n;
    cin >> t;
    string result[t];

    for(int i = 1; i <= t; i++)
    {
        while (1)
        {
            cin >> n;
            if (n >= 2)
                break;
        }
        int a[n], total = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            total += a[j];
        }
        result[i-1] = cuter(n-1, a, n, total);
    }
    for(int i = 0; i < t; i++){
        if(i == t-1){
            cout << result[i];
        } else {
            cout << result[i] << endl;
        }
    }

    // // Termina la medición del tiempo
    // auto end = chrono::high_resolution_clock::now();
    // chrono::duration<double> duration = end - start;

    // // Imprime el tiempo en segundos
    // cout << "\nTime taken: " << duration.count() << " seconds" << endl;

    return 0;
}
