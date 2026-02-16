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

int Fixed::getRawBits(void) const { return this->_fixedPointValue; }
void Fixed::setRawBits(int const raw) { this->_fixedPointValue = raw; }

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (float)(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> _fractionalBits;
}

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

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

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

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}