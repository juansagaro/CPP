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

#include "../inc/Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog constructed with a brain" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src) {
    this->_brain = new Brain(*src._brain); 
    std::cout << "Dog copy constructed" << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
    if (this != &src) {
        Animal::operator=(src);

        if (this->_brain)
            delete this->_brain;

        this->_brain = new Brain(*src._brain);
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->_brain;
    std::cout << "Dog destroyed and brain deleted" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::compareIdeas(const Dog &other) const {
    std::cout << "My Brain address: " << this->_brain << std::endl;
    std::cout << "Other Brain address: " << other._brain << std::endl;
}
