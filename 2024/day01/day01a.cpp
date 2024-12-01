#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

const std::string input_file = "input";

int main() {
    std::ifstream file(input_file);
    if (!file) {
        std::cerr << "Error opening file " << input_file << std::endl;
        return 1;
    }

    std::vector<int> v1;
    std::vector<int> v2;
    
    int x1, x2;
    // Read two integers per line (ignoring whitespace)
    while (file >> x1 >> x2) {
        v1.push_back(x1);
        v2.push_back(x2);
    }

    file.close();

    // Sort each input-column in ascending order
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    int result = 0;
    for (auto it1 = v1.begin(), it2 = v2.begin(); it1 != v1.end(); it1++, it2++)
        result = result + std::abs(*it2 - *it1);
    
    std::cout << result << std::endl;

    return 0;
}