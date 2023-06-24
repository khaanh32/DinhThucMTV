#include <iostream>
#include <vector>
//Phan Anh Kha 
// Lop:D21_TH06 || CaSang3,5,7 
using namespace std;

double detA(vector<vector<double>> matrix) {
    int n = matrix.size();
    double detA = 1;

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] == 0) {
            for (int j = i + 1; j < n; j++) {
                if (matrix[j][i] != 0) {
                    swap(matrix[i], matrix[j]);
                    detA *= -1;
                    break;
                }
            }
            if (matrix[i][i] == 0) {
                return 0;
            }
        }

        detA *= matrix[i][i];

        for (int j = i + 1; j < n; j++) {
            double coef = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++) {
                matrix[j][k] -= coef * matrix[i][k];
            }
        }
    }

    return detA;
}

int main() {
    int n;
    cout << "\nNhap kich thuoc ma tran vuong : ";
    cin >> n;

    vector<vector<double>> matrix(n, vector<double>(n));

    cout << "\nNhap cac phan tu cho ma tran : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    double d = detA(matrix);
    cout << "\n Dinh thuc cua ma tran  la : " << d << endl;

    return 0;
}
