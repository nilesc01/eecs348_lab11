#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Matrix {
private:
    int N;
    int **data;

public:
    Matrix(int size = 0) : N(size) {
        if (N > 0) {
            data = new int*[N];
            for (int i = 0; i < N; ++i)
                data[i] = new int[N];
        } else {
            data = nullptr;
        }
    }

    // copy constructor
    Matrix(const Matrix &m) : N(m.N) {
        data = new int*[N];
        for (int i = 0; i < N; ++i) {
            data[i] = new int[N];
            for (int j = 0; j < N; ++j)
                data[i][j] = m.data[i][j];
        }
    }

    // destructor
    ~Matrix() {
        if (data) {
            for (int i = 0; i < N; ++i)
                delete[] data[i];
            delete[] data;
        }
    }

    // read matrix values from file
    bool readFromFile(ifstream &fin) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!(fin >> data[i][j])) {
                    return false; // stop if file ends prematurely
                }
            }
        }
        return true;
    }

    // display the matrix
    void display(const string &title) const {
        cout << "\n" << title << " (" << N << "x" << N << "):\n";
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                cout << setw(5) << data[i][j];
            cout << endl;
        }
    }
};

int main() {
    string filename;
    cout << "Enter input filename: ";
    cin >> filename;

    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: cannot open file '" << filename << "'.\n";
        return 1;
    }

    int N;
    fin >> N;
    if (!fin || N <= 0) {
        cerr << "Error: invalid matrix size.\n";
        return 1;
    }

    vector<Matrix> matrices;
    while (true) {
        Matrix temp(N);
        if (!temp.readFromFile(fin)) break; // stop if incomplete
        matrices.push_back(temp);
    }

    if (matrices.empty()) {
        cerr << "No matrices found in file.\n";
        return 1;
    }

    // display all matrices
    for (size_t i = 0; i < matrices.size(); ++i) {
        matrices[i].display("Matrix " + to_string(i + 1));
    }

    fin.close();
    return 0;
}
