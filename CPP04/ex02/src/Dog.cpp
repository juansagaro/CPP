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
    this->_brain = new Brain(); // 1. MALLOC AL NACER
    std::cout << "Dog constructed with a brain" << std::endl;
}

// COPIA PROFUNDA (Constructor de copia)
Dog::Dog(const Dog &src) : AAnimal(src) {
    // NO HACER: this->_brain = src._brain; (Esto sería puntero compartido)
    
    // SI HACER: Crear nuevo cerebro y copiar el contenido
    this->_brain = new Brain(*src._brain); 
    std::cout << "Dog copy constructed" << std::endl;
}

// COPIA PROFUNDA (Operador de asignación)
Dog &Dog::operator=(const Dog &src) {
    if (this != &src) {
        AAnimal::operator=(src); // Copiar parte de Animal
        
        // 1. Borrar mi cerebro viejo (si tengo) para evitar leaks
        if (this->_brain)
            delete this->_brain;
        
        // 2. Crear cerebro nuevo copiado del otro
        this->_brain = new Brain(*src._brain);
    }
    std::cout << "Dog assigned" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete this->_brain; // 2. FREE AL MORIR
    std::cout << "Dog destroyed and brain deleted" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::compareIdeas(const Dog &other) const {
    std::cout << "My Brain address: " << this->_brain << std::endl;
    std::cout << "Other Brain address: " << other._brain << std::endl;
}
