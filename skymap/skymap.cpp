#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

/*
*
*  Weighted quick union implementation of union-find algotithm
*  with path compression
*
*  A reference implementation
*
*
*  Author: Jacek Marciniak
*  Date: 2015-11-07
*
*/

// Data
int cc;  // Number of components
int N;  // Number of elements
vector<int> id;  // id[i] = parent of i
vector<int> sz;  // sz[i] = number of elements in subtree rooted at i

// Initializes data structures
void init(int size) {
    cc = size;
    N = size;

    id.resize(size);
    sz.resize(size);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
}

// Gets component's identifier of the element
int find(int p) {
    int r = p;

    while (r != id[r]) {  // Find
        r = id[r];
    }

    while (p != r) {  // Path compression
        int n = id[p];
        id[p] = r;
        p = n;
    }

    return r;
}

// Check if 2 elements belongs to the same component
bool connected(int p, int q) {
    return find(p) == find(q);
}

// Connect components
void make_union(int p, int q) {
    int pid = find(p);
    int qid = find(q);

    if (pid == qid) return;

    // Make smaller root point to larger one
    if (sz[qid] < sz[pid]) {
        id[qid] = pid;
        sz[pid] += sz[qid];
    } else {
        id[pid] = qid;
        sz[qid] += sz[pid];
    }

    cc--;
}

// Print an array
void print_id() {
    cout << "[";
    for (int i = 0; i < N; i++) {
        cout << (i > 0 ? "," : "") << id[i];
    }
    cout << "]" << endl;
}

int main() {
    // Initialization of variables and 2D array
    size_t rows = 0, cols = 0;
    int n;
    cin >> n;
    init(n * n);

    rows = n;
    cols = rows;
    int** sky = new int* [rows];
    for (size_t i = 0; i < rows; i++) {
        sky[i] = new int[cols];
    }

    // Reading data into 2D array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sky[i][j];
        }
    }

    // Introduction of variable counting zeros and their counting
    int zero = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (sky[i][j] == 0) {
                zero++;
            }

            // Finding stars and creating connections between them
            else if (sky[i][j] == 1) {
                if (i < n - 1 && sky[i + 1][j] == 1) {
                    make_union(i * n + j, (i + 1) * n + j);
                }

                if (j < n - 1 && sky[i][j + 1] == 1) {
                    make_union(i * n + j, i * n + j + 1);
                }
            }
        }
    }

    // Searching for the largest constellation
    if (cc == zero) {
        cout << 0 << " " << 0;
        return 0;
    }
    int largest = 0;

    for (int i = 0; i < n * n; i++) {
        if (sz[i] > largest) {
            largest = sz[i];
        }
    }

    // Displaying the number of constellations and the number of stars in the largest of them
    cout << cc - zero << " " << largest << '\n';

    // Cleaning up memory
    for (size_t i = 0; i < rows; i++) {
        delete[] sky[i];
    }
    delete[] sky;
    return 0;
}
