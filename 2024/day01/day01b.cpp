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

    int result = 0;
    for (auto it1 = v1.begin(); it1 != v1.end(); it1++)
        for (auto it2 = v2.begin(); it2 != v2.end(); it2++)
            if (*it1 == *it2)
                result = result + *it1;
    
    std::cout << result << std::endl;

    return 0;
}