/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:31:23 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/27 18:31:23 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// 1. Constructor por Defecto
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

// 2. Constructor de Copia
// Se llama cuando creas un objeto nuevo a partir de uno existente: Fixed a = b;
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    // Copiamos el valor usando el operador de asignación o directamente
    // Para calcar el output del subject que dice "Copy assignment operator called",
    // podemos llamar a *this = other. O simplemente copiar el valor.
    // Lo haré directo para ser eficiente, pero el subject a veces varía.
    this->_fixedPointValue = other.getRawBits();
}

// 3. Operador de Asignación
// Se llama cuando modificas un objeto YA existente: a = b;
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    
    // Protección contra auto-asignación (a = a)
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    // Devuelve referencia a sí mismo para permitir a = b = c
    return *this;
}

// 4. Destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// --- Getters y Setters ---

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    // El subject no pide cout aquí explícitamente en el log de ejemplo,
    // pero es la función para establecer el valor manualmente.
    this->_fixedPointValue = raw;
}