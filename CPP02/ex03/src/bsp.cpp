/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:50:16 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/29 16:50:16 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Point.hpp"

// Función auxiliar para calcular el producto cruz 2D: (Bx - Ax) * (Py - Ay) - (By - Ay) * (Px - Ax)
static Fixed cross_product(Point const a, Point const b, Point const p) {
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed cp1 = cross_product(a, b, point);
    Fixed cp2 = cross_product(b, c, point);
    Fixed cp3 = cross_product(c, a, point);
    
    if (cp1 > 0 && cp2 > 0 && cp3 > 0)
        return true;

    if (cp1 < 0 && cp2 < 0 && cp3 < 0)
        return true;

    return false;
}