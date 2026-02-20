/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:46:00 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/20 20:31:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"

int main() {
    std::cout  << "--- Test 1: Buscando en un std::vector ---" << std::endl;
    
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    try {
        std::cout << "Buscando el 30... ";
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "¡Encontrado! El valor es: " << *it << std::endl;

        std::cout << "Buscando el 99... ";
        it = easyfind(vec, 99);
        std::cout << "¡Encontrado! El valor es: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Buscando en un std::list ---" << std::endl;

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    try {
        std::cout << "Buscando el 2... ";
        std::list<int>::iterator it2 = easyfind(lst, 2);
        std::cout << "¡Encontrado! El valor es: " << *it2 << std::endl;

        std::cout << "Buscando el -5... ";
        it2 = easyfind(lst, -5);
        std::cout << "¡Encontrado! El valor es: " << *it2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
