#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
using namespace std;

class Matrix {
private:
    vector<vector<int>> data;

public:
    void readMatrix() {
        data.clear();
        string line;
        cout << "Enter the matrix (one row per line, empty line to finish):\n";

        while (getline(cin, line)) {
            if (line.empty()) break;
            stringstream ss(line);
            vector<int> row;
            int val;
            while (ss >> val)
                row.push_back(val);

            if (!data.empty() && row.size() != data[0].size()) {
                cerr << "Error: rows must be same length." << endl;
                data.clear();
                return;
            }
            if (!row.empty())
                data.push_back(row);
        }

        if (data.empty())
            cerr << "No matrix data entered." << endl;
    }

    bool isValid() const {
        return !data.empty();
    }

    void updateValue(int row, int col, int newVal) {
        int numRows = data.size();
        int numCols = (numRows > 0) ? data[0].size() : 0;

        if (row < 0 || col < 0 || row >= numRows || col >= numCols) {
            cerr << "Error: Invalid row or column index." << endl;
            return;
        }

        data[row][col] = newVal;

        cout << "\nMatrix after updating element at (" << row << ", " << col << "):\n";
        for (const auto& r : data) {
            for (int val : r)
                cout << setw(5) << val;
            cout << endl;
        }
    }
};

int main() {
    Matrix matrix;
    matrix.readMatrix();

    if (!matrix.isValid())
        return 1;

    int row, col, newVal;
    cout << "Enter row index, column index, and new value (0 indexing): ";
    cin >> row >> col >> newVal;

    matrix.updateValue(row, col, newVal);

    return 0;
}
