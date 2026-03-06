/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 20:03:38 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/06 20:53:06 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVector(0), _timeDeque(0) {}
PmergeMe::PmergeMe(const PmergeMe& src) : _vector(src._vector), _deque(src._deque), _timeVector(src._timeVector), _timeDeque(src._timeDeque) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    if (this != &src) {
        _vector = src._vector;
        _deque = src._deque;
        _timeVector = src._timeVector;
        _timeDeque = src._timeDeque;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

double PmergeMe::getTime() const {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0) + time.tv_usec;
}

size_t PmergeMe::getJacobsthal(size_t n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return getJacobsthal(n - 1) + 2 * getJacobsthal(n - 2);
}

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<size_t> sequence;
    size_t jacobIndex = 3;
    while (getJacobsthal(jacobIndex) < size) {
        sequence.push_back(getJacobsthal(jacobIndex));
        jacobIndex++;
    }
    return sequence;
}

void PmergeMe::execute(int argc, char **argv) {
    try {
        // 1. Mostrar estado inicial "Before"
        std::cout << "Before: ";
        for (int i = 1; i < argc; ++i) {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;

        // 2. Procesar y ordenar con std::vector
        double startVec = getTime();
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            size_t start = 0;
            if (!arg.empty() && arg[0] == '+')
                start = 1;
            if (start >= arg.length() || arg.substr(start).find_first_not_of("0123456789") != std::string::npos)
                throw std::runtime_error("Error: invalid input '" + arg + "'.");
            long val = std::atol(argv[i]);
            if (val < 0 || val > 2147483647)
                throw std::runtime_error("Error: value out of range '" + arg + "'.");
            _vector.push_back(static_cast<int>(val));
        }
        sortVector();
        _timeVector = getTime() - startVec;

        // 3. Procesar y ordenar con std::deque
        double startDeq = getTime();
        for (int i = 1; i < argc; ++i) {
            _deque.push_back(std::atoi(argv[i]));
        }
        sortDeque();
        _timeDeque = getTime() - startDeq;

        // 4. Mostrar estado final "After"
        std::cout << "After:  ";
        for (size_t i = 0; i < _vector.size(); ++i) {
            std::cout << _vector[i] << " ";
        }
        std::cout << std::endl;

        // 5. Imprimir los tiempos exactos
        std::cout << "Time to process a range of " << _vector.size() 
                  << " elements with std::vector : " << _timeVector << " us" << std::endl;
        std::cout << "Time to process a range of " << _deque.size() 
                  << " elements with std::deque  : " << _timeDeque << " us" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

// =================================================================================
// Implementación VECTOR
// =================================================================================

static void sortPairsVector(std::vector<std::pair<int, int> >& pairs) {
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j - 1].first > key.first) {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
}

void PmergeMe::sortVector() {
    if (_vector.size() > 1) {
        mergeInsertVector(_vector);
    }
}

void PmergeMe::mergeInsertVector(std::vector<int>& arr) {
    size_t size = arr.size();
    if (size <= 1) return;

    // 1. Separar straggler si es impar
    bool hasStraggler = (size % 2 != 0);
    int straggler = -1;
    if (hasStraggler)
        straggler = arr.back();

    // 2. Crear pares: el mayor como first, el menor como second
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < size; i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // 3. Ordenar los pares por su valor mayor con insertion sort
    if (pairs.size() > 1)
        sortPairsVector(pairs);

    // 4. Construir mainChain y pend
    std::vector<int> mainChain;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    // 5. Insertar pend[0] al inicio (siempre <= mainChain[0])
    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    // 6. Generar orden de inserción con Jacobsthal
    std::vector<size_t> insertOrder;
    std::vector<size_t> jacobSeq = generateJacobsthalSequence(pend.size());

    std::vector<bool> used(pend.size(), false);
    used[0] = true;

    for (size_t i = 0; i < jacobSeq.size(); i++) {
        size_t jVal = jacobSeq[i];
        if (jVal - 1 < pend.size() && !used[jVal - 1]) {
            insertOrder.push_back(jVal - 1);
            used[jVal - 1] = true;
        }
        // Rellenar hacia atrás
        for (size_t k = jVal - 1; k > 0; k--) {
            if (k - 1 < pend.size() && !used[k - 1]) {
                insertOrder.push_back(k - 1);
                used[k - 1] = true;
            }
        }
    }
    // Los que queden
    for (size_t i = 1; i < pend.size(); i++) {
        if (!used[i])
            insertOrder.push_back(i);
    }

    // 7. Insertar cada pend en mainChain con búsqueda binaria
    for (size_t i = 0; i < insertOrder.size(); i++) {
        int val = pend[insertOrder[i]];
        std::vector<int>::iterator pos = std::lower_bound(
            mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    // 8. Insertar straggler
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(
            mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}

// =================================================================================
// Implementación DEQUE
// =================================================================================

static void sortPairsDeque(std::deque<std::pair<int, int> >& pairs) {
    for (size_t i = 1; i < pairs.size(); i++) {
        std::pair<int, int> key = pairs[i];
        size_t j = i;
        while (j > 0 && pairs[j - 1].first > key.first) {
            pairs[j] = pairs[j - 1];
            j--;
        }
        pairs[j] = key;
    }
}

void PmergeMe::sortDeque() {
    if (_deque.size() > 1) {
        mergeInsertDeque(_deque);
    }
}

void PmergeMe::mergeInsertDeque(std::deque<int>& arr) {
    size_t size = arr.size();
    if (size <= 1) return;

    bool hasStraggler = (size % 2 != 0);
    int straggler = -1;
    if (hasStraggler)
        straggler = arr.back();

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < size; i += 2) {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    // 3. Ordenar los pares por su valor mayor con insertion sort
    if (pairs.size() > 1) {
        std::deque<int> largers;
        for (size_t i = 0; i < pairs.size(); i++)
            largers.push_back(pairs[i].first);
        mergeInsertDeque(largers);
        sortPairsDeque(pairs);
    }

    std::deque<int> mainChain;
    std::deque<int> pend;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pend.push_back(pairs[i].second);
    }

    if (!pend.empty())
        mainChain.insert(mainChain.begin(), pend[0]);

    std::vector<size_t> insertOrder;
    std::vector<size_t> jacobSeq = generateJacobsthalSequence(pend.size());

    std::vector<bool> used(pend.size(), false);
    used[0] = true;

    for (size_t i = 0; i < jacobSeq.size(); i++) {
        size_t jVal = jacobSeq[i];
        if (jVal - 1 < pend.size() && !used[jVal - 1]) {
            insertOrder.push_back(jVal - 1);
            used[jVal - 1] = true;
        }
        for (size_t k = jVal - 1; k > 0; k--) {
            if (k - 1 < pend.size() && !used[k - 1]) {
                insertOrder.push_back(k - 1);
                used[k - 1] = true;
            }
        }
    }
    for (size_t i = 1; i < pend.size(); i++) {
        if (!used[i])
            insertOrder.push_back(i);
    }

    for (size_t i = 0; i < insertOrder.size(); i++) {
        int val = pend[insertOrder[i]];
        std::deque<int>::iterator pos = std::lower_bound(
            mainChain.begin(), mainChain.end(), val);
        mainChain.insert(pos, val);
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(
            mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    arr = mainChain;
}
