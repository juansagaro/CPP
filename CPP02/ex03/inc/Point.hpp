/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:45:24 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/29 16:45:24 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
    Fixed const _x;
    Fixed const _y;

public:
    // 1. Constructor por defecto (0, 0)
    Point();
    
    // 2. Constructor con floats
    Point(const float x, const float y);
    
    // 3. Constructor de Copia
    Point(const Point &other);
    
    // 4. Operador de Asignación (Problema: atributos const)
    // El subject pide forma canónica, pero técnicamente no podemos asignar a const.
    // Lo declaramos pero no hará nada útil (o usaremos un truco sucio si es obligatorio).
    Point &operator=(const Point &other);
    
    // 5. Destructor
    ~Point();

    // Getters necesarios para el BSP
    Fixed getX() const;
    Fixed getY() const;
};

// Prototipo de la función global
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif