/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:20:40 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/21 20:20:40 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../inc/Span.hpp"

int main()
{
    std::cout << "--- TEST 1: El test oficial del Subject ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
    } 
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Excepciones (Lleno y Pocos Elementos) ---" << std::endl;
    try {
        Span sp2 = Span(2);
        sp2.addNumber(42);
        std::cout << sp2.shortestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Capturado: " << e.what() << std::endl;
    }

    try {
        Span sp3 = Span(1);
        sp3.addNumber(1);
        sp3.addNumber(2);
    } catch (std::exception &e) {
        std::cout << "Capturado: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Stress Test (20.000 números) e Iteradores ---" << std::endl;
    try {
        Span bigSpan = Span(22000);
        
        std::vector<int> randomNumbers;
        std::srand(std::time(NULL));
        for (int i = 0; i < 20000; i++) {
            randomNumbers.push_back(std::rand());
        }

        bigSpan.addNumber(randomNumbers.begin(), randomNumbers.end());

        std::cout << "20,000 números añadidos de golpe con éxito." << std::endl;
        std::cout << "Calculando shortestSpan en 20,000 números... " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Calculando longestSpan en 20,000 números... " << bigSpan.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error en test 3: " << e.what() << std::endl;
    }

    return 0;
}
