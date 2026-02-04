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
    // --- PRUEBA CORRECTA (CON VIRTUAL) ---
    std::cout << "--- TRUE POLYMORPHISM ---" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    // Aquí imprime los tipos correctos
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    // MAGIA AQUÍ:
    // Aunque 'i' es un puntero a 'Animal', como makeSound es virtual,
    // el programa busca en tiempo de ejecución y encuentra que es un Gato.
    i->makeSound(); // Output: Meow!
    j->makeSound(); // Output: Woof!
    meta->makeSound();

    // Limpieza (Importante el destructor virtual en Animal)
    delete meta;
    delete j;
    delete i;


    // --- PRUEBA INCORRECTA (SIN VIRTUAL) ---
    std::cout << "\n--- WRONG ANIMAL (NO VIRTUAL) ---" << std::endl;
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;

    // FALLO AQUÍ:
    // El puntero es 'WrongAnimal*'. Como NO es virtual, el compilador decide
    // en tiempo de compilación llamar a la función de WrongAnimal.
    // Ignora completamente que en realidad es un WrongCat.
    wrongCat->makeSound(); // Output: WrongAnimal Sound (¡ERROR!)
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat; // Peligro: Probablemente solo llame al destructor de WrongAnimal

    return 0;
}
