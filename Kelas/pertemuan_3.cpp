#include <iostream>
#include <iomanip>
using namespace std;

const int N = 3;

void gaussElimination(double mat[N][N+1]) {
    for (int i = 0; i < N; i++) {
        // Membuat pivot utama menjadi 1
        double pivot = mat[i][i];
        for (int j = 0; j <= N; j++) {
            mat[i][j] /= pivot;
        }

        // Eliminasi baris lain
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = mat[k][i];
                for (int j = 0; j <= N; j++) {
                    mat[k][j] -= factor * mat[i][j];
                }
            }
        }
    }

    // Menampilkan hasil
    cout << "Solusi SPL:\n";
    for (int i = 0; i < N; i++) {
        cout << "x" << i+1 << " = " << fixed << setprecision(2) << mat[i][N] << endl;
    }
}

int main() {
    // Augmented matrix dari SPL
    double matrix[N][N+1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    gaussElimination(matrix);

    return 0;
}
