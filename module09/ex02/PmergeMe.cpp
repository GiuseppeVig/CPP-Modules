#include "PmergeMe.hpp"

// Constructor
PmergeMe::PmergeMe() {}

// Destructor
PmergeMe::~PmergeMe() {}

// Merge-Insertion Sort for Vector
void PmergeMe::mergeInsertionSortVector(std::vector<int>& sequence) {
    if (sequence.size() < 2)
        return;
    
    size_t mid = sequence.size() / 2;
    std::vector<int> left(sequence.begin(), sequence.begin() + mid);
    std::vector<int> right(sequence.begin() + mid, sequence.end());

    mergeInsertionSortVector(left);
    mergeInsertionSortVector(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        sequence[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    }
    while (i < left.size()) sequence[k++] = left[i++];
    while (j < right.size()) sequence[k++] = right[j++];
}

// Merge-Insertion Sort for Deque
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& sequence) {
    if (sequence.size() < 2)
        return;

    size_t mid = sequence.size() / 2;
    std::deque<int> left(sequence.begin(), sequence.begin() + mid);
    std::deque<int> right(sequence.begin() + mid, sequence.end());

    mergeInsertionSortDeque(left);
    mergeInsertionSortDeque(right);

    size_t i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        sequence[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
    }
    while (i < left.size()) sequence[k++] = left[i++];
    while (j < right.size()) sequence[k++] = right[j++];
}

// Sort Sequences and Measure Time
void PmergeMe::sortSequences(char **argv) {
    // Parse inputs
    for (int i = 1; argv[i]; i++) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0) {
            throw std::runtime_error("Error: Invalid input.");
        }
        vectorSequence.push_back(num);
        dequeSequence.push_back(num);
    }

    // Print Before Sorting
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorSequence.size(); i++)
        std::cout << vectorSequence[i] << " ";
    std::cout << std::endl;

    // Measure time for Vector
    struct timeval start, end;
    gettimeofday(&start, NULL);
    mergeInsertionSortVector(vectorSequence);
    gettimeofday(&end, NULL);
    double timeVec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Measure time for Deque
    gettimeofday(&start, NULL);
    mergeInsertionSortDeque(dequeSequence);
    gettimeofday(&end, NULL);
    double timeDeq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    printResults(timeVec, timeDeq);
}

// Print Results
void PmergeMe::printResults(double timeVec, double timeDeq) {
    std::cout << "After: ";
    for (size_t i = 0; i < vectorSequence.size(); i++)
        std::cout << vectorSequence[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vectorSequence.size() 
              << " elements with std::vector: " << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << dequeSequence.size() 
              << " elements with std::deque: " << timeDeq << " us" << std::endl;
}
