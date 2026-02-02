/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:51:43 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/29 13:51:43 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

// --- Constructores y Destructores (Igual que Ex01) ---
Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) {
    this->_fixedPointValue = n << _fractionalBits;
}

Fixed::Fixed(const float n) {
    this->_fixedPointValue = roundf(n * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_fixedPointValue = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {}

// --- Getters / Setters / Conversión ---
int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

// --- 1. Operadores de Comparación ---
bool Fixed::operator>(const Fixed &other) const {
    return this->_fixedPointValue > other._fixedPointValue;
}
bool Fixed::operator<(const Fixed &other) const {
    return this->_fixedPointValue < other._fixedPointValue;
}
bool Fixed::operator>=(const Fixed &other) const {
    return this->_fixedPointValue >= other._fixedPointValue;
}
bool Fixed::operator<=(const Fixed &other) const {
    return this->_fixedPointValue <= other._fixedPointValue;
}
bool Fixed::operator==(const Fixed &other) const {
    return this->_fixedPointValue == other._fixedPointValue;
}
bool Fixed::operator!=(const Fixed &other) const {
    return this->_fixedPointValue != other._fixedPointValue;
}

// --- 2. Operadores Aritméticos (Devuelven FLOAT) ---
// Al devolver float, la estrategia más limpia es convertir ambos a float,
// operar y devolver el resultado.
float Fixed::operator+(const Fixed &other) const {
    return this->toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed &other) const {
    return this->toFloat() - other.toFloat();
}

float Fixed::operator*(const Fixed &other) const {
    return this->toFloat() * other.toFloat();
}

float Fixed::operator/(const Fixed &other) const {
    return this->toFloat() / other.toFloat();
}

// --- 3. Incremento / Decremento ---
Fixed& Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

// --- 4. Min / Max (SIN OPERADOR TERNARIO) ---

Fixed& Fixed::min(Fixed &a, Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b) {
        return a;
    }
    return b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b) {
        return a;
    }
    return b;
}

// --- Sobrecarga de Stream global ---
std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}