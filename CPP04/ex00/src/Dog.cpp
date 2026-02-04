/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:18:00 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:18:00 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Dog.cpp */
#include "../inc/Dog.hpp"

Dog::Dog() {
    this->type = "Dog"; // Configuramos el tipo
    std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    *this = src;
    std::cout << "Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
    if (this != &src)
        Animal::operator=(src);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destroyed" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
