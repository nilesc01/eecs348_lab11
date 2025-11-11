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
        vector<int> tempRow;
        string line;

        cout << "Enter elements of the matrix (rows separated by Enter, end with an empty line):\n";
        while (getline(cin, line) && !line.empty()) {
            tempRow.clear();
            stringstream ss(line);
            int num;
            while (ss >> num)
                tempRow.push_back(num);

            if (!data.empty() && tempRow.size() != data[0].size()) {
                cerr << "Error: rows must have the same number of columns." << endl;
                data.clear();
                return;
            }

            data.push_back(tempRow);
        }

        if (data.empty()) {
            cerr << "Error: empty matrix." << endl;
        }
    }

    void swapRows(int row1, int row2) {
        int rows = data.size();
        if (rows == 0 || row1 < 0 || row2 < 0 || row1 >= rows || row2 >= rows) {
            cerr << "Error: Invalid row indices." << endl;
            return;
        }

        swap(data[row1], data[row2]);

        cout << "\nMatrix after swapping row " << row1 << " and row " << row2 << ":\n";
        for (const auto& row : data) {
            for (int val : row)
                cout << setw(5) << val;
            cout << endl;
        }
    }

    bool isValid() const {
        return !data.empty();
    }
};

int main() {
    Matrix matrix;
    matrix.readMatrix();

    if (!matrix.isValid())
        return 1;

    int r1, r2;
    cout << "Enter two row indices to swap (starting at 0): ";
    cin >> r1 >> r2;

    matrix.swapRows(r1, r2);

    return 0;
}
