#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;

public:
    // read a matrix interactively
    void readMatrix(const string &name = "Matrix") {
        data.clear();
        string line;
        cout << "Enter elements of " << name
             << " (rows separated by Enter, end with an empty line):\n";

        while (true) {
            getline(cin, line);
            if (line.empty()) break;

            istringstream iss(line);
            vector<int> row;
            int val;
            while (iss >> val)
                row.push_back(val);

            if (!data.empty() && row.size() != data[0].size()) {
                cerr << "Error: all rows must have the same number of columns.\n";
                data.clear();
                return;
            }

            if (!row.empty())
                data.push_back(row);
        }

        if (data.empty())
            cerr << "Warning: no data entered for " << name << ".\n";
    }

    int rows() const { return data.size(); }
    int cols() const { return data.empty() ? 0 : data[0].size(); }

    // display matrix (format matches first procedural version)
    void display(const string &title) const {
        cout << "\n" << title << ":\n";
        for (const auto &r : data) {
            for (int val : r)
                cout << setw(6) << val;
            cout << endl;
        }
    }

    // overload * for matrix multiplication
    Matrix operator*(const Matrix &m) const {
        if (cols() != m.rows()) {
            throw runtime_error("Error: invalid matrix dimensions for multiplication.");
        }

        Matrix result;
        result.data.assign(rows(), vector<int>(m.cols(), 0));

        for (int i = 0; i < rows(); ++i)
            for (int j = 0; j < m.cols(); ++j)
                for (int k = 0; k < cols(); ++k)
                    result.data[i][j] += data[i][k] * m.data[k][j];

        return result;
    }
};

int main() {
    Matrix A, B;

    cout << "Enter Matrix A:\n";
    A.readMatrix("Matrix A");

    cout << "\nEnter Matrix B:\n";
    B.readMatrix("Matrix B");

    if (A.rows() == 0 || B.rows() == 0) {
        cerr << "Invalid input: One or both matrices are empty.\n";
        return 1;
    }

    if (A.cols() != B.rows()) {
        cerr << "Error: Matrix multiplication cannot be performed (A.cols != B.rows).\n";
        return 1;
    }

    // perform multiplication
    Matrix C = A * B;
    C.display("A * B");

    return 0;
}
