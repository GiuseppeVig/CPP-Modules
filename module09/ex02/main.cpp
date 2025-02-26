#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: ./PmergeMe <list of positive integers>" << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter;
        sorter.sortSequences(argv);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
