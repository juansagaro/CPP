/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:03:38 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/12 20:03:32 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// ═══════════════════════════════════════════════════════════════════════════
// Orthodox Canonical Form
// ═══════════════════════════════════════════════════════════════════════════

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}

PmergeMe::PmergeMe(const PmergeMe& src)
    : _vec(src._vec), _deq(src._deq), 
      _timeVec(src._timeVec), _timeDeq(src._timeDeq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    if (this != &src) {
        _vec     = src._vec;
        _deq     = src._deq;
        _timeVec = src._timeVec;
        _timeDeq = src._timeDeq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// ═══════════════════════════════════════════════════════════════════════════
// Utils
// ═══════════════════════════════════════════════════════════════════════════

double PmergeMe::now() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1e6 + tv.tv_usec;
}

int PmergeMe::parseNumber(const std::string& arg) {
    if (arg.empty())
        throw std::runtime_error("Error: empty argument.");

    size_t start = (arg[0] == '+') ? 1 : 0;
    if (start >= arg.length())
        throw std::runtime_error("Error: invalid input '" + arg + "'.");

    for (size_t i = start; i < arg.length(); ++i) {
        if (!std::isdigit(arg[i]))
            throw std::runtime_error("Error: invalid input '" + arg + "'.");
    }

    long val = std::atol(arg.c_str());
    if (val < 0 || val > 2147483647)
        throw std::runtime_error("Error: value out of range '" + arg + "'.");

    return static_cast<int>(val);
}

void PmergeMe::printSequence(const std::string& label, 
                              const std::vector<int>& arr, 
                              const std::string& color) {
    std::cout << color << BOLD << label << RESET << " ";
    
    if (arr.size() <= MAX_DISPLAY) {
        for (size_t i = 0; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
    } else {
        for (size_t i = 0; i < MAX_DISPLAY / 2; ++i)
            std::cout << arr[i] << " ";
        std::cout << DIM << "[..." << (arr.size() - MAX_DISPLAY) << " more...] " << RESET;
        for (size_t i = arr.size() - MAX_DISPLAY / 2; i < arr.size(); ++i)
            std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// ═══════════════════════════════════════════════════════════════════════════
// Jacobsthal
// ═══════════════════════════════════════════════════════════════════════════

size_t PmergeMe::jacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<size_t> PmergeMe::jacobsthalSequence(size_t size) {
    std::vector<size_t> seq;
    for (size_t i = 3; jacobsthal(i) < size; ++i)
        seq.push_back(jacobsthal(i));
    return seq;
}

std::vector<size_t> PmergeMe::buildInsertionOrder(size_t pendSize) {
    std::vector<size_t> order;
    std::vector<bool>   used(pendSize, false);
    std::vector<size_t> jacob = jacobsthalSequence(pendSize);

    if (pendSize > 0)
        used[0] = true;

    for (size_t i = 0; i < jacob.size(); ++i) {
        size_t idx = jacob[i] - 1;
        if (idx < pendSize && !used[idx]) {
            order.push_back(idx);
            used[idx] = true;
        }
        for (size_t k = jacob[i] - 1; k > 0; --k) {
            if (k - 1 < pendSize && !used[k - 1]) {
                order.push_back(k - 1);
                used[k - 1] = true;
            }
        }
    }

    for (size_t i = 1; i < pendSize; ++i) {
        if (!used[i])
            order.push_back(i);
    }
    return order;
}

// ═══════════════════════════════════════════════════════════════════════════
// Ford-Johnson (Merge-Insert Sort) - Vector
// ═══════════════════════════════════════════════════════════════════════════

namespace {
    struct PairCompare {
        bool operator()(const std::pair<int,int>& a, 
                        const std::pair<int,int>& b) const {
            return a.first < b.first;
        }
    };
}

void PmergeMe::fordJohnson(std::vector<int>& arr) {
    if (arr.size() <= 1)
        return;

    // ─── Step 1: Handle odd element ─────────────────────────────────────────
    int  straggler    = 0;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler)
        straggler = arr.back();

    // ─── Step 2: Create pairs (larger, smaller) ─────────────────────────────
    std::vector<std::pair<int,int> > pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // ─── Step 3: Sort pairs by larger element ───────────────────────────────
    if (pairs.size() > 1)
        std::sort(pairs.begin(), pairs.end(), PairCompare());

    // ─── Step 4: Build mainChain and pend ───────────────────────────────────
    std::vector<int> mainChain, pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // ─── Step 5: Insert pend[0] at front ────────────────────────────────────
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    // ─── Step 6: Insert remaining pend using Jacobsthal order ───────────────
    std::vector<size_t> order = buildInsertionOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        std::vector<int>::iterator pos = 
            std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    // ─── Step 7: Insert straggler ───────────────────────────────────────────
    if (hasStraggler) {
        std::vector<int>::iterator pos = 
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

// ═══════════════════════════════════════════════════════════════════════════
// Ford-Johnson (Merge-Insert Sort) - Deque
// ═══════════════════════════════════════════════════════════════════════════

void PmergeMe::fordJohnson(std::deque<int>& arr) {
    if (arr.size() <= 1)
        return;

    int  straggler    = 0;
    bool hasStraggler = (arr.size() % 2 != 0);
    if (hasStraggler)
        straggler = arr.back();

    std::deque<std::pair<int,int> > pairs;
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    if (pairs.size() > 1)
        std::sort(pairs.begin(), pairs.end(), PairCompare());

    std::deque<int> mainChain, pend;
    for (size_t i = 0; i < pairs.size(); ++i) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    std::vector<size_t> order = buildInsertionOrder(pend.size());
    for (size_t i = 0; i < order.size(); ++i) {
        int val = pend[order[i]];
        std::deque<int>::iterator pos = 
            std::lower_bound(mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = 
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

// ═══════════════════════════════════════════════════════════════════════════
// Main Execution
// ═══════════════════════════════════════════════════════════════════════════

void PmergeMe::execute(int argc, char** argv) {
    try {
        // ─── Parse input ────────────────────────────────────────────────────
        std::vector<int> input;
        for (int i = 1; i < argc; ++i)
            input.push_back(parseNumber(argv[i]));

        if (input.empty())
            throw std::runtime_error("Error: no input provided.");

        // ─── Display before state ───────────────────────────────────────────
        printSequence("Before:", input, YELLOW);

        // ─── Sort with vector ───────────────────────────────────────────────
        _vec = input;
        double startVec = now();
        fordJohnson(_vec);
        _timeVec = now() - startVec;

        // ─── Sort with deque ────────────────────────────────────────────────
        _deq = std::deque<int>(input.begin(), input.end());
        double startDeq = now();
        fordJohnson(_deq);
        _timeDeq = now() - startDeq;

        // ─── Display after state ────────────────────────────────────────────
        printSequence("After: ", _vec, GREEN);

        // ─── Display timing ─────────────────────────────────────────────────
        std::cout << CYAN << "Time to process a range of " << BOLD << _vec.size() 
                  << RESET << CYAN << " elements with " << MAGENTA << "std::vector" 
                  << CYAN << " : " << BOLD << _timeVec << " us" << RESET << std::endl;

        std::cout << CYAN << "Time to process a range of " << BOLD << _deq.size() 
                  << RESET << CYAN << " elements with " << MAGENTA << "std::deque " 
                  << CYAN << " : " << BOLD << _timeDeq << " us" << RESET << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "\033[31m" << e.what() << RESET << std::endl;
    }
}
