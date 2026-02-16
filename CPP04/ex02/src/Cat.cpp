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

#include "../inc/Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat constructed with a brain" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src) {
    this->_brain = new Brain(*src._brain); 
    std::cout << "Cat copy constructed" << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
    if (this != &src) {
        AAnimal::operator=(src);

        if (this->_brain)
            delete this->_brain;

        this->_brain = new Brain(*src._brain);
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat destroyed and brain deleted" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::compareIdeas(const Cat &other) const {
    std::cout << "My Brain address: " << this->_brain << std::endl;
    std::cout << "Other Brain address: " << other._brain << std::endl;
}