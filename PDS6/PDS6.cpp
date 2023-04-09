#include <fstream>
#include <iostream>

using namespace std;

int n, m;
int** f_line;

void printIncidenceMatrix(string filename) {
    //"incidence_matrix.txt"
    ofstream fout(filename);
    int** incidence_matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        incidence_matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            incidence_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = f_line[i][0];
        int v = f_line[i][1];
        incidence_matrix[u - 1][i] = 1;
        incidence_matrix[v - 1][i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << incidence_matrix[i][j] << " ";
            fout << incidence_matrix[i][j] << " ";
        }
        cout << endl;
        fout << endl;
    }
    fout.close();
    for (int i = 0; i < n; i++) {
        delete[] incidence_matrix[i];
    }
    delete[] incidence_matrix;
}

void printAdjacencyMatrix(string filename) {
    //"adjacency_matrix.txt"
    ofstream fout(filename);
    int** adjacency_matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        adjacency_matrix[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u = f_line[i][0];
        int v = f_line[i][1];
        adjacency_matrix[u - 1][v - 1] = 1;
        adjacency_matrix[v - 1][u - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjacency_matrix[i][j] << " ";
            fout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
        fout << endl;
    }
    fout.close();
    for (int i = 0; i < n; i++) {
        delete[] adjacency_matrix[i];
    }
    delete[] adjacency_matrix;
}


int main() {
    ifstream fin("input.txt");
    fin >> n >> m;
    f_line = new int* [m];

    for (int i = 0; i < m; i++) {
        f_line[i] = new int[2];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        f_line[i][0] = u;
        f_line[i][1] = v;
    }
    fin.close(); 
    string IncidenceFileName, AdjacencyFileName;
    cout << "Enter Incidence matrix file name: ";cin >> IncidenceFileName;
    cout << "Enter Adjacency matrix file name: ";cin >> AdjacencyFileName;
    printIncidenceMatrix(IncidenceFileName);
    printAdjacencyMatrix(AdjacencyFileName);
    
    for (int i = 0; i < m; i++) {
        delete[] f_line[i];
    }
}