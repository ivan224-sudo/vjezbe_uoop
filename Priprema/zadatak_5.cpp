#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

template <typename T>
class Matrix {
public:
    vector<vector<T>> e;

    vector<T>& operator[](int i) {
        return e[i];
    }

    const vector<T>& operator[](int i) const {
        return e[i];
    }
};

template <typename T>
ostream& operator<<(ostream& out, const Matrix<T>& m) {
    int r = m.e.size();
    int s = m.e[0].size();
    for (int j = 0; j < r; j++) {
        for (int i = 0; i < s; i++) {
            out << m.e[j][i] << " ";
        }
        out << endl;
    }
    out << endl;
    return out;
}

template <typename T>
istream& operator>>(istream& in, Matrix<T>& m) {
    string linija;
    while (getline(in, linija) && linija != "") {
        stringstream ss(linija);
        T temp;
        vector<T> redak;
        while (ss >> temp) {
            redak.push_back(temp);
        }
        m.e.push_back(redak);
    }
    return in;
}

template <typename T>
Matrix<T> operator*(Matrix<T>& m1, Matrix<T>& m2) {
    Matrix<T> result;
    for (int r = 0; r < m1.e.size(); r++) {
        vector<T> redak;
        for (int s = 0; s < m2[0].size(); s++) {
            T sum = 0;
            for (int k = 0; k < m1[0].size(); k++) {
                sum += m1[r][k] * m2[k][s];
            }
            redak.push_back(sum);
        }
        result.e.push_back(redak);
    }
    return result;
}

template <typename T>
void ucitajIIspisi(const string& filename) {
    ifstream f(filename);
    Matrix<T> m1, m2;
    f >> m1 >> m2;
    cout << "Matrica 1:" << endl << m1;
    cout << "Matrica 2:" << endl << m2;
    cout << "Umnozak:" << endl << m1 * m2 << endl;
}

int main() {
    cout << "=== INT MATRICE ===" << endl;
    ucitajIIspisi<int>("intMatrix.txt");

    cout << "=== UNSIGNED INT MATRICE ===" << endl;
    ucitajIIspisi<unsigned int>("unsignedMatrix.txt");

    cout << "=== DOUBLE MATRICE ===" << endl;
    ucitajIIspisi<double>("doubleMatrix.txt");

    return 0;
}
