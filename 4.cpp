#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    int N;

public:
    // constructor
    Matrix(int size = 0) : N(size), data(size, vector<int>(size)) {}

    // read matrix values
    void read() {
        cout << "Enter elements of the " << N << "x" << N << " matrix:\n";
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> data[i][j];
    }

    // compute and display diagonal sums
    void diagonalSum() const {
        if (N == 0) {
            cerr << "Error: empty matrix.\n";
            return;
        }

        int mainSum = 0, secondarySum = 0;

        for (int i = 0; i < N; ++i) {
            mainSum += data[i][i];
            secondarySum += data[i][N - i - 1];
        }

        cout << "\nSum of main diagonal elements: " << mainSum;
        cout << "\nSum of secondary diagonal elements: " << secondarySum << endl;
    }
};

int main() {
    int N;
    cout << "Enter matrix size N: ";
    cin >> N;

    if (N <= 0) {
        cerr << "Error: matrix size must be positive.\n";
        return 1;
    }

    Matrix A(N);
    A.read();
    A.diagonalSum();

    return 0;
}
