/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:17:27 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:17:27 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cat.cpp */
#include "../inc/Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
    *this = src;
    std::cout << "Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
    if (this != &src)
        Animal::operator=(src);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
