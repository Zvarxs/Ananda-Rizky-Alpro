#include <iostream>
#include <string>

int findString(const std::string arr[], int size, const std::string& target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == "") {
            int leftMid = mid - 1;
            int rightMid = mid + 1;
            
            while (true) {
                if (leftMid < left && rightMid > right) {
                    return -1; 
                } else if (rightMid <= right && arr[rightMid] != "") {
                    mid = rightMid;
                    break;
                } else if (leftMid >= left && arr[leftMid] != "") {
                    mid = leftMid;
                    break;
                }
                rightMid++;
                leftMid--;
            }
        }

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

int main() {
    const int size = 10;
    std::string arr[size] = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    std::string target = "bola";
    
    int index = findString(arr, size, target);
    
    if (index != -1) {
        std::cout << "Kata '" << target << "' ditemukan di indeks " << index << std::endl;
    } else {
        std::cout << "Kata '" << target << "' tidak ditemukan" << std::endl;
    }

    return 0;
}