/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:45:37 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/18 15:47:17 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"
bool bsp(Point const a, Point const b, Point const c, Point const point);
int main( void ) {
    std::cout << "----- Let's found Point in Triangle! -----" << std::endl;
    Point a(0.0f,0.0f);
    Point b(5.0f,0.0f);
    Point c(2.5f,2.5f);

    float points[][3] = {
        {2.5f, 2.0f,1},
        {0.0f, 0.0f, 0},
        {2.5f, 0.0f, 0},
        {-1.0f, 0.0f,0}
    };

    const char* desc[] = {
        "Inside triangle",
        "at vertex A",
        "on edge AB",
        "outside (left)"
    };
    
    int passed = 0;
    int numOfTest = 4;

    for(int i = 0; i < numOfTest; i++)
    {
        Point p(points[i][0], points[i][1]);
        bool result = bsp(a,b,c,p);
        bool exp = points[i][2];
        bool pass = result == exp;

        std::cout << "Test " << i + 1 << ": (" << points[i][0] << ", " << points[i][1] << ") " << desc[i] << "\n Result: " << (result ? "inside" : "outside") << " | Expected: " << (exp ? "inside" : "outside") << (pass ? " PASS" : "FAIL") << "\n";
        if (pass) passed++;
    }
    std::cout << "Passed: " << passed << "/" << numOfTest << std::endl;
    return 0;
}