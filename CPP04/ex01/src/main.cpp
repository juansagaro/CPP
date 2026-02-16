/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:19:21 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:19:21 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int main() {
    std::cout << "--- TEST 1: ARRAY DE ANIMALES ---" << std::endl;
    
    const int arraySize = 4;
    const Animal* animals[arraySize];

    for (int i = 0; i < arraySize / 2; i++)
        animals[i] = new Dog();
    
    for (int i = arraySize / 2; i < arraySize; i++)
        animals[i] = new Cat();

    std::cout << "\n--- BORRANDO ARRAY (Check Leaks) ---" << std::endl;
    for (int i = 0; i < arraySize; i++)
        delete animals[i];


    std::cout << "\n--- TEST 2: DEEP COPY PROOF ---" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    
    std::cout << "End of scope for tmp. If deep copy worked, 'basic' is still alive and safe." << std::endl;

    return 0;
}