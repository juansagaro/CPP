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

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8; // Siempre será 8

public:
    // 1. Constructor por defecto
    Fixed();

    // 2. Constructor de Copia
    Fixed(const Fixed& other);

    // 3. Operador de Asignación de Copia
    Fixed& operator=(const Fixed& other);

    // 4. Destructor
    ~Fixed();

    // Getters y Setters requeridos
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};

#endif