/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:43:07 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/17 14:46:20 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Binary space Partitioning.
// hat indicates whether a point is inside a triangle or not
/*
    I have to create a triangle and to be sure about each edge can not be same others
*/

static Fixed crossLine(Point const& a, Point const& b, Point const& point)
{
    Fixed ax = a.getX() - point.getX();
    Fixed ay = a.getY() - point.getY();
    Fixed bx = b.getX() - point.getX();
    Fixed by = b.getY() - point.getY();

    return ((ax * by) - (ay * bx));
}


static bool oppositeVertex(Point const startLine, Point const endLine, Point const& point, Point const& referance){
    Fixed cl1 = crossLine(endLine, referance, startLine);
    Fixed cl2 = crossLine(endLine, point, startLine);

    if(cl1 == Fixed(0) || cl2 == Fixed(0))
    {
        return false;
    }

    return ((cl1 > Fixed(0) && cl2 > Fixed(0)) || (cl1 < Fixed(0) && cl2 < Fixed(0)));
}

// I will create function as bool to check each point is inside a triangle

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

    bool sideOne = oppositeVertex(a,b,point,c);
    if(!sideOne)
        return false;

    bool sideTwo = oppositeVertex(b,c,point,a);
    if(!sideOne)
        return false;
    
    bool sideThree = oppositeVertex(c,a,point,b);
    if(!sideOne)
        return false;
}

