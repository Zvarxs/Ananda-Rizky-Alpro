#include <iostream>
#include <vector>
#include <algorithm>

void mergeAndSort(std::vector<int>& A, int m, std::vector<int>& B, int n) {
    int i = m - 1;
    int j = n - 1; 
    int k = m + n - 1;
    
    while (i >= 0 && j >= 0) {
        if (A[i] > B[j]) {
            A[k] = A[i];
            i--;
        } else {
            A[k] = B[j];
            j--;
        }
        k--;
    }
    
    while (j >= 0) {
        A[k] = B[j];
        j--;
        k--;
    }
}

int main() {
    std::vector<int> A = {1, 3, 5, 7, 9, 0, 0, 0, 0, 0}; 
    std::vector<int> B = {2, 4, 6, 8, 10};
    int m = 5; 
    int n = B.size(); 
    
    mergeAndSort(A, m, B, n);
    
    for (int i = 0; i < m + n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}