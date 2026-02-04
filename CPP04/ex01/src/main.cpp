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
    
    const int arraySize = 4; // Puedes poner 10 o 100
    const Animal* animals[arraySize];
    
    // Llenar mitad perros, mitad gatos
    for (int i = 0; i < arraySize / 2; i++)
        animals[i] = new Dog();
    
    for (int i = arraySize / 2; i < arraySize; i++)
        animals[i] = new Cat();

    std::cout << "\n--- BORRANDO ARRAY (Check Leaks) ---" << std::endl;
    // Aquí es vital que el destructor de Animal sea virtual.
    // Si no lo es, solo se borrará la parte "Animal", el "Dog" no se ejecutará,
    // el delete _brain nunca ocurrirá y tendrás un leak del tamaño de Brain.
    for (int i = 0; i < arraySize; i++)
        delete animals[i];


    std::cout << "\n--- TEST 2: DEEP COPY PROOF ---" << std::endl;
    Dog basic;
    // basic.getBrain()->ideas[0] = "I want food"; // Si implementas getters

    {
        Dog tmp = basic; // Llama al Copy Constructor
        // Si fuera Shallow Copy, tmp y basic tendrían el mismo puntero a Brain
    } 
    // Aquí tmp muere y llama a su destructor (delete _brain).
    // Si fuera Shallow Copy, el cerebro de 'basic' acabaría de ser borrado también.
    
    std::cout << "End of scope for tmp. If deep copy worked, 'basic' is still alive and safe." << std::endl;

    return 0;
}