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
    std::cout << "--- CREATING DOG ---" << std::endl;
    Dog* j = new Dog();
    
    std::cout << "\n--- CREATING CAT ---" << std::endl;
    Cat* i = new Cat();

    std::cout << "\n--- ACTIONS ---" << std::endl;
    j->makeSound();
    i->makeSound();

    std::cout << "\n--- POLYMORPHISM ---" << std::endl;
    AAnimal* meta = new Dog();
    meta->makeSound();
    delete meta;

    std::cout << "\n--- CLEANUP ---" << std::endl;
    delete j;
    delete i;

    return 0;
}
