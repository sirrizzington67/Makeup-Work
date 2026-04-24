#include "denoise.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

int clamp(int val) {
    if (val < 0)   return 0;
    if (val > 255) return 255;
    return val;
}

Matrix loadMatrix(const string& filename) {
    ifstream fin(filename);
    if (!fin)
        throw runtime_error("Cannot open input file: " + filename);

    int rows, cols;
    fin >> rows >> cols;

    Matrix m(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            fin >> m[i][j];
            m[i][j] = clamp(m[i][j]);
        }
    return m;
}

void saveMatrix(const Matrix& m, const string& filename) {
    ofstream fout(filename);
    if (!fout)
        throw runtime_error("Cannot open output file: " + filename);

    int rows = m.size();
    int cols = m[0].size();
    fout << rows << " " << cols << "\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fout << m[i][j];
            if (j < cols - 1) fout << " ";
        }
        fout << "\n";
    }
}

// Applies one pass of 3x3 mean filter with clamp border policy
static Matrix meanFilterOnce(const Matrix& m) {
    int rows = m.size();
    int cols = m[0].size();
    Matrix out(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int sum = 0;
            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    // Clamp border: replicate edge pixels
                    int ni = max(0, min(i + di, rows - 1));
                    int nj = max(0, min(j + dj, cols - 1));
                    sum += m[ni][nj];
                    count++;
                }
            }
            out[i][j] = clamp(sum / count);
        }
    }
    return out;
}

Matrix meanFilter(const Matrix& m, int k) {
    Matrix result = m;
    for (int i = 0; i < k; i++)
        result = meanFilterOnce(result);
    return result;
}

void printStats(const Matrix& m, const string& label) {
    int mn = 255, mx = 0, sum = 0, count = 0;
    for (auto& row : m)
        for (int val : row) {
            if (val < mn) mn = val;
            if (val > mx) mx = val;
            sum += val;
            count++;
        }
    cout << label << " -- Min: " << mn
         << "  Max: " << mx
         << "  Avg: " << sum / count << "\n";
}