/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:46:55 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/27 18:46:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// --- Constructores Canónicos ---
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// --- NUEVOS CONSTRUCTORES ---

// Constructor INT: Desplazamos bits a la izquierda (x 256)
Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = n << _fractionalBits;
}

// Constructor FLOAT: Multiplicamos por 256 y redondeamos
Fixed::Fixed(const float n) {
    std::cout << "Float constructor called" << std::endl;
    // 1 << 8 es igual a 256
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

// --- GETTERS / SETTERS ---

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

// --- FUNCIONES DE CONVERSIÓN ---

// toFloat: Convertimos a float y dividimos entre 256
float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

// toInt: Desplazamos a la derecha para eliminar la parte decimal
int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// --- SOBRECARGA DEL OPERADOR << ---
// Esto permite hacer: std::cout << miObjetoFixed;
std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    // Insertamos en el flujo la representación flotante del número
    o << i.toFloat();
    return o;
}