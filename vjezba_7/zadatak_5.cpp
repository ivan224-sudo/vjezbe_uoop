#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

class Matrix {
public:
    vector<vector<double>> data;

    // operator []
    vector<double>& operator[](int i) {
        return data[i];
    }

    // operator <<
    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (auto& row : m.data) {
            for (double x : row) {
                out << x << " ";
            }
            out << endl;
        }
        return out;
    }

    // operator >> (učitavanje matrice iz redaka)
    friend istream& operator>>(istream& in, Matrix& m) {
        m.data.clear();
        string line;

        while (getline(in, line)) {
            if (line.empty()) break;

            stringstream ss(line);
            vector<double> row;
            double x;

            while (ss >> x) {
                row.push_back(x);
            }

            m.data.push_back(row);
        }

        return in;
    }

    // operator *
    friend Matrix operator*(const Matrix& a, const Matrix& b) {
        Matrix r;

        int n = a.data.size();
        int m = b.data[0].size();
        int k = b.data.size();

        r.data.resize(n, vector<double>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int t = 0; t < k; t++) {
                    r.data[i][j] += a.data[i][t] * b.data[t][j];
                }
            }
        }

        return r;
    }
};

int main() {

    // Učitavanje iz datoteke
    ifstream file("matrice.txt");

    Matrix A, B;

    file >> A >> B;

    cout << "Matrica A:\n" << A << endl;
    cout << "Matrica B:\n" << B << endl;

    Matrix C = A * B;

    cout << "A * B:\n" << C;

    return 0;
}
