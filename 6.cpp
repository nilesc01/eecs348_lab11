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

    void swapColumns(int col1, int col2) {
        if (data.empty() || col1 < 0 || col2 < 0 ||
            col1 >= data[0].size() || col2 >= data[0].size()) {
            cerr << "Error: invalid column indices." << endl;
            return;
        }

        for (int i = 0; i < data.size(); ++i)
            swap(data[i][col1], data[i][col2]);

        cout << "\nMatrix after swapping column " << col1 << " and column " << col2 << ":\n";
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

    int c1, c2;
    cout << "Enter two column indices to swap (starting at 0): ";
    cin >> c1 >> c2;

    matrix.swapColumns(c1, c2);

    return 0;
}
