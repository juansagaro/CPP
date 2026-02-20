/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:39:04 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/20 12:53:43 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"

void increment(int &n) {
    n++;
}

void printString(std::string const & str) {
    std::cout << str << " ";
}

template <typename T>
void printElement(T const & element) {
    std::cout << element << " ";
}

int main() {
    std::cout << "--- TEST 1: Modificando un array de enteros (non-const) ---" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original:  ";
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << std::endl;

    std::cout << "Mutated:   ";
    ::iter(intArray, intArrayLen, increment);
    ::iter(intArray, intArrayLen, printElement<int>);
    std::cout << "\n" << std::endl;

    std::cout << "--- TEST 2: Imprimiendo un array de strings (const reference) ---" << std::endl;
    std::string strArray[] = {"Hello", "Evaluator,", "welcome", "to", "C++"};
    size_t strArrayLen = sizeof(strArray) / sizeof(strArray[0]);

    ::iter(strArray, strArrayLen, printString);
    std::cout << "\n" << std::endl;

    std::cout << "--- TEST 3: Array inmutable (const array) ---" << std::endl;
    const double doubleArray[] = {4.2, 21.0, 84.0};
    size_t doubleArrayLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    ::iter(doubleArray, doubleArrayLen, printElement<double>); 
    std::cout << std::endl;

    return 0;
}
