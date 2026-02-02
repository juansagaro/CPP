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
// Representa el área signada del paralelogramo o la orientación.
static Fixed cross_product(Point const a, Point const b, Point const p) {
    return (b.getX() - a.getX()) * (p.getY() - a.getY()) - (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Calculamos la posición relativa del punto respecto a cada lado
    Fixed cp1 = cross_product(a, b, point);
    Fixed cp2 = cross_product(b, c, point);
    Fixed cp3 = cross_product(c, a, point);

    // El punto está dentro si todos los productos cruz tienen el mismo signo.
    // El enunciado dice que si está en el borde (0), devuelve False.
    
    // Caso 1: Todos positivos
    if (cp1 > 0 && cp2 > 0 && cp3 > 0)
        return true;
        
    // Caso 2: Todos negativos
    if (cp1 < 0 && cp2 < 0 && cp3 < 0)
        return true;

    // Si alguno es 0 (borde) o hay mezcla de signos (fuera), retorna false.
    return false;
}