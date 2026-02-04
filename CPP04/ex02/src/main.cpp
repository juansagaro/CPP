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

#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int main() {
    // 1. Esto funcionaba antes, pero AHORA DEBE DAR ERROR DE COMPILACIÓN
    // AAnimal test; 
    // AAnimal* pointer = new AAnimal();
    // Descomenta las líneas de arriba para probar que NO compila.
    // El error será algo como: "cannot instantiate abstract class"

    // 2. Esto SÍ debe funcionar
    std::cout << "--- CREATING DOG ---" << std::endl;
    Dog* j = new Dog();
    
    std::cout << "\n--- CREATING CAT ---" << std::endl;
    Cat* i = new Cat();

    std::cout << "\n--- ACTIONS ---" << std::endl;
    j->makeSound(); // Woof
    i->makeSound(); // Meow

    // 3. Polimorfismo sigue funcionando
    std::cout << "\n--- POLYMORPHISM ---" << std::endl;
    AAnimal* meta = new Dog(); // Puntero AAnimal apuntando a Dog es válido
    meta->makeSound();
    delete meta;

    std::cout << "\n--- CLEANUP ---" << std::endl;
    delete j;
    delete i;

    return 0;
}
