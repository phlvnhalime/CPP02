/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:42:50 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/17 12:27:08 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(const float x, const float y)
    : _x(Fixed(x)),
     _y(Fixed(y))
{}
Point::Point(const Point& copy)
    : _x(copy._x),
    _y(copy._y)
{}
// Since _x and _y are const, We don't need to assign to them.
Point& Point::operator=(const Point& copy)
{
    (void)copy;
    return *this;
}
Point::~Point(){
    // Default function.
}

Fixed Point::getX() const{
    return _x;
}
Fixed Point::getY() const{
    return _y;
}