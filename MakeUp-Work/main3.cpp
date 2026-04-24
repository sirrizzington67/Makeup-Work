#include "denoise.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: denoise <input.txt> <output.txt> [filter] [iterations]\n";
        return 1;
    }

    string inputFile  = argv[1];
    string outputFile = argv[2];
    string filter     = (argc >= 4) ? argv[3] : "mean";
    int    iterations = (argc >= 5) ? stoi(argv[4]) : 1;

    try {
        Matrix noisy = loadMatrix(inputFile);
        printStats(noisy, "Before");

        Matrix clean;
        if (filter == "mean")
            clean = meanFilter(noisy, iterations);
        else {
            cout << "Unknown filter: " << filter << ". Using mean.\n";
            clean = meanFilter(noisy, iterations);
        }

        printStats(clean, "After ");
        saveMatrix(clean, outputFile);
        cout << "Output written to " << outputFile << "\n";

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}