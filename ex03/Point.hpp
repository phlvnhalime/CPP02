/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:37:21 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/17 10:43:33 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Point {

    private:
        int x;
        int y;
    public:
        Point(const int &x,const int &y): x(0), y(0){};
        Point(const float &x, const float &y);
        Point(const Point& copy);
        Point& operator=(const Point& copy);
        ~Point();
};

