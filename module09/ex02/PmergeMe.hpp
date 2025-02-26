#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <sys/time.h>
#include <stdexcept>

class PmergeMe {
private:
    std::vector<int> vectorSequence;
    std::deque<int> dequeSequence;

    void mergeInsertionSortVector(std::vector<int>& sequence);
    void mergeInsertionSortDeque(std::deque<int>& sequence);

public:
    PmergeMe();
    ~PmergeMe();

    void sortSequences(char **argv);
    void printResults(double timeVec, double timeDeq);
};

#endif
