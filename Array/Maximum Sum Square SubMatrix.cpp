#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int computeMax(vector<vector<int>>& prefixSumMatrix, int gridSize) {
    int answer = INT_MIN;
    int n = (int) prefixSumMatrix.size();

    for (int i = gridSize - 1; i < n; i++) {
        for (int j = gridSize - 1; j < n; j++) {

            int sum = prefixSumMatrix[i][j];

            // if the prefixSumMatrix row size gets bigger than the grid row size
            if (i - gridSize >= 0) {
                sum -= prefixSumMatrix[i - gridSize][j];
            }

            if (j - gridSize >= 0) {
                sum -= prefixSumMatrix[i][j - gridSize];
            }

            if (i - gridSize >= 0 && j - gridSize >= 0) {
                sum += prefixSumMatrix[i - gridSize][j - gridSize];
            }

            answer = max(sum, answer);
        }
    }
    return answer;
}

int maximumSumGrid(vector<vector<int>> matrix, int gridSize) {
    int n = (int) matrix.size();
    vector<vector<int>> prefixSumMatrix(n, vector<int>(n, 0));
    // building the prefixSumMatrix
    // (0, 0)
    prefixSumMatrix[0][0] = matrix[0][0];
    // (col = 0),
    for (int i = 1; i < n; i++) {
        prefixSumMatrix[0][i] = matrix[0][i] + prefixSumMatrix[0][i - 1];
    }
    // (row = 0),
    for (int j = 1; j < n; j++) {
        prefixSumMatrix[j][0] = matrix[j][0] + prefixSumMatrix[j - 1][0];
    }
    // when sum(i, j) = sum(i - 1, j) + this_element + sum(i - 1, j) - sum(i - 1, j - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            prefixSumMatrix[i][j] = prefixSumMatrix[i - 1][j] + prefixSumMatrix[i][j - 1] + matrix[i][j] - prefixSumMatrix[i - 1][j - 1];
        }
    }
    // validate the data computed!
    // printMatrix(prefixSumMatrix, n);
    // finding the maximum sub matrix sum using prev computed prefixSumMatrix
    return computeMax(prefixSumMatrix, gridSize);
}


int main() {
    vector<vector<int>> matrix = {
                            {1, 1, 1, 1, 1},
                            {2, 2, 2, 2, 2},
                            {3, 8, 6, 7, 3},
                            {4, 4, 4, 4, 4},
                            {5, 5, 5, 5, 5},
                            };
    int gridSize = 3;
    cout << maximumSumGrid(matrix, gridSize) << endl;
    return 0;
}
