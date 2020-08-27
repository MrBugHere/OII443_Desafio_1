// C++ program to find number of bins required using 
// First Fit algorithm. 
#include <iostream>
#include <algorithm>

// Returns number of bins required using first fit 
// online algorithm 
int firstFit(int weight[], int n, int c) {
    // Initialize result (Count of bins) 
    int res = 0;

    // Create an array to store remaining space in bins 
    // there can be at most n bins 
    int* bin_rem;
    bin_rem = new int[n];

    // Place items one by one 
    for (int i = 0; i < n; i++) {
        // Find the first bin that can accommodate 
        // weight[i] 
        int j;
        for (j = 0; j < res; j++) {
            if (bin_rem[j] >= weight[i]) {
                bin_rem[j] = bin_rem[j] - weight[i];
                break;
            }
        }

        // If no bin could accommodate weight[i] 
        if (j == res) {
            bin_rem[res] = c - weight[i];
            res++;
        }
    }
    return res;
}

int firstFitDec(int weight[], int n, int c) {
    // First sort all weights in decreasing order 
    std::sort(weight, weight + n, std::greater<int>());

    // Now call first fit for sorted items 
    return firstFit(weight, n, c);
}


// Driver program 
int main() {
    int weight[] = { 2, 5, 4, 7, 1, 3, 8 };
    int c = 10;
    int n = sizeof(weight) / sizeof(weight[0]);
    std::cout << "Number of bins required in First Fit : "
        << firstFitDec(weight, n, c);
    return 0;
}