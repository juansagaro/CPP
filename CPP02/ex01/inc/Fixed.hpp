/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:30:56 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/27 18:30:56 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> // Necesario para roundf

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    // Constructor de Int
    Fixed(const int n);
    // Constructor de Float
    Fixed(const float n);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    // Funciones de conversión
    float   toFloat(void) const;
    int     toInt(void) const;
};

// Sobrecarga del operador de inserción (fuera de la clase)
std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif