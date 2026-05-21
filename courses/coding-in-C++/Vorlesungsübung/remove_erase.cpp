#include <iostream>
#include <vector>
#include <algorithm>




int main() {
    std::vector<int> vector_1 = {1,2,3,2,4,2,5};
    // Remove all occurrences of the value 2 from vector_1
    vector_1.erase(std::remove(vector_1.begin(), vector_1.end(), 2), vector_1.end());

    // Print the modified vector
    std::cout << "Modified vector: ";
    for (int num : vector_1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
