/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 13:51:07 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/29 13:51:07 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    // --- 1. Operadores de Comparación (se mantienen bool) ---
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // --- 2. Operadores Aritméticos (AHORA DEVUELVEN FLOAT) ---
    float operator+(const Fixed &other) const;
    float operator-(const Fixed &other) const;
    float operator*(const Fixed &other) const;
    float operator/(const Fixed &other) const;

    // --- 3. Operadores de Incremento/Decremento (se mantienen Fixed&) ---
    Fixed&  operator++();       // Pre-incremento
    Fixed   operator++(int);    // Post-incremento
    Fixed&  operator--();       // Pre-decremento
    Fixed   operator--(int);    // Post-decremento

    // --- 4. Funciones Estáticas Min/Max ---
    static Fixed& min(Fixed &a, Fixed &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static const Fixed& min(const Fixed &a, const Fixed &b);
    static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif