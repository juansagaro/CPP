/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:50:55 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/29 16:50:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../inc/Point.hpp"

int main(void) {
    // Triángulo básico (0,0) -> (10,0) -> (0,10)
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    // 1. Punto DENTRO (1, 1)
    Point p1(1, 1);
    if (bsp(a, b, c, p1))
        std::cout << "P1 (1,1) is INSIDE" << std::endl;
    else
        std::cout << "P1 (1,1) is OUTSIDE" << std::endl;

    // 2. Punto FUERA (10, 10)
    Point p2(10, 10);
    if (bsp(a, b, c, p2))
        std::cout << "P2 (10,10) is INSIDE" << std::endl;
    else
        std::cout << "P2 (10,10) is OUTSIDE" << std::endl;

    // 3. Punto en el BORDE (5, 0)
    Point p3(5, 0);
    if (bsp(a, b, c, p3))
        std::cout << "P3 (5,0) is INSIDE" << std::endl;
    else
        std::cout << "P3 (5,0) is OUTSIDE (Edge)" << std::endl;

    // 4. Punto en VÉRTICE (0, 0)
    if (bsp(a, b, c, a))
        std::cout << "Vertex A is INSIDE" << std::endl;
    else
        std::cout << "Vertex A is OUTSIDE" << std::endl;

    return 0;
}