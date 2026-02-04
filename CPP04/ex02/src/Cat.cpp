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
    this->_brain = new Brain(); // 1. MALLOC AL NACER
    std::cout << "Cat constructed with a brain" << std::endl;
}

// COPIA PROFUNDA (Constructor de copia)
Cat::Cat(const Cat &src) : AAnimal(src) {
    // NO HACER: this->_brain = src._brain; (Esto sería puntero compartido)
    
    // SI HACER: Crear nuevo cerebro y copiar el contenido
    this->_brain = new Brain(*src._brain); 
    std::cout << "Cat copy constructed" << std::endl;
}

// COPIA PROFUNDA (Operador de asignación)
Cat &Cat::operator=(const Cat &src) {
    if (this != &src) {
        AAnimal::operator=(src); // Copiar parte de Animal
        
        // 1. Borrar mi cerebro viejo (si tengo) para evitar leaks
        if (this->_brain)
            delete this->_brain;
        
        // 2. Crear cerebro nuevo copiado del otro
        this->_brain = new Brain(*src._brain);
    }
    std::cout << "Cat assigned" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete this->_brain; // 2. FREE AL MORIR
    std::cout << "Cat destroyed and brain deleted" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::compareIdeas(const Cat &other) const {
    std::cout << "My Brain address: " << this->_brain << std::endl;
    std::cout << "Other Brain address: " << other._brain << std::endl;
}