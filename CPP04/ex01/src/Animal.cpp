/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:17:24 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:17:24 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Animal.cpp */
#include "../inc/Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(const Animal &src) {
    *this = src;
    std::cout << "Animal copy constructed" << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
    if (this != &src)
        this->type = src.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "*Generic Animal Sound*" << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}
