/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:45:49 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/29 16:45:49 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

Point::Point() : _x(0), _y(0) {
    // Inicializa a 0 usando el constructor de Fixed
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
    // Inicializa usando el constructor Fixed(float)
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
}

Point &Point::operator=(const Point &other) {
    // Como _x y _y son const, NO PODEMOS modificarlos aquí:
    // this->_x = other._x; // ERROR DE COMPILACIÓN
    
    // Simplemente no hacemos nada o devolvemos *this.
    // Es una limitación de diseño impuesta por el subject al hacer atributos const.
    (void)other;
    return *this;
}

Point::~Point() {
}

Fixed Point::getX() const {
    return this->_x;
}

Fixed Point::getY() const {
    return this->_y;
}