#include <iostream>
#include <vector>
#include <utility> // Include the utility header for std::pair
#include <algorithm> // Include the algorithm header for std::sort

int main() {
    // Create a vector of pairs to store pairs of integers
    std::vector<std::pair<int, int>> pairVector;

    // Add pairs to the vector
    pairVector.push_back(std::make_pair(3, 1));
    pairVector.push_back(std::make_pair(5, 2));
    pairVector.push_back(std::make_pair(6, 5));
    pairVector.push_back(std::make_pair(23, 1));
    pairVector.push_back(std::make_pair(766, 1));


    // Define a custom comparison function to sort by the second element of the pair
    auto customComparator = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };

    // Sort the vector using the custom comparison function
    std::sort(pairVector.begin(), pairVector.end(), customComparator);

    // Access and print the sorted elements of the vector
    for (const auto& pair : pairVector) {
        std::cout << "First: " << pair.first << ", Second: " << pair.second << std::endl;
    }

    return 0;
}
