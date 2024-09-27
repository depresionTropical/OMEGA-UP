#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Estructura del árbol de segmentos
struct SegmentTree {
    vector<int> minTree, maxTree;
    int size;

    SegmentTree(const vector<int>& arr) {
        size = arr.size();
        minTree.resize(4 * size);
        maxTree.resize(4 * size);
        build(arr, 0, 0, size - 1);
    }

    // Construcción del Segment Tree
    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            minTree[node] = arr[start];
            maxTree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        }
    }

    // Actualización en una posición
    void update(int idx, int value, int node, int start, int end) {
        if (start == end) {
            minTree[node] = value;
            maxTree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(idx, value, 2 * node + 1, start, mid);
            } else {
                update(idx, value, 2 * node + 2, mid + 1, end);
            }
            minTree[node] = min(minTree[2 * node + 1], minTree[2 * node + 2]);
            maxTree[node] = max(maxTree[2 * node + 1], maxTree[2 * node + 2]);
        }
    }

    // Consulta de rango para obtener el mínimo y máximo
    pair<int, int> query(int l, int r, int node, int start, int end) {
        if (r < start || l > end) {
            return {INT_MAX, INT_MIN}; // Valor fuera de rango
        }
        if (l <= start && end <= r) {
            return {minTree[node], maxTree[node]};
        }
        int mid = (start + end) / 2;
        auto left = query(l, r, 2 * node + 1, start, mid);
        auto right = query(l, r, 2 * node + 2, mid + 1, end);
        return {min(left.first, right.first), max(left.second, right.second)};
    }

    // Funciones wrapper
    void update(int idx, int value) {
        update(idx, value, 0, 0, size - 1);
    }

    pair<int, int> query(int l, int r) {
        return query(l, r, 0, 0, size - 1);
    }
};

int main() {
    int N, M;
    cin >> N >> M; // Leer N (tamaño del arreglo) y M (número de consultas)
    int total[M][2];
    vector<int> S(N); // El arreglo de enteros
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    SegmentTree segTree(S); // Construir el Segment Tree con el arreglo inicial

    for (int i = 0; i < M; i++) {
        char type;
        cin >> type;
        if (type == 'C') {
            int l, r;
            cin >> l >> r;
            auto result = segTree.query(l - 1, r - 1); // Realizar consulta de mínimo y máximo
            // cout << result.first << " " << result.second << endl;
            total[i][0] = result.first;
            total[i][1] = result.second;
        } else if (type == 'A') {
            int idx, value;
            cin >> idx >> value;
            segTree.update(idx - 1, value); // Actualizar el valor en el índice dado
        }
    }
    for (int i = 0; i < M; i++)
    {
        cout << total[i][0] << " " << total[i][1] << endl;
    }
    
    return 0;
}
