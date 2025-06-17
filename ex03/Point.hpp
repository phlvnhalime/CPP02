/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:37:21 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/17 12:22:07 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point {

    private:
        const Fixed _x;
        const Fixed _y;
    public:
        Point(): _x(0), _y(0){};
        Point(const float x, const float y);
        Point(const Point& copy);
        Point& operator=(const Point& copy);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

