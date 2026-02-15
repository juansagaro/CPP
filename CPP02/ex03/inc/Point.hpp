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
    Point();

    Point(const float x, const float y);

    Point(const Point &other);
    
    Point &operator=(const Point &other);

    ~Point();

    Fixed getX() const;
    Fixed getY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif