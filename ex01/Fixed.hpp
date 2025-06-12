/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:45:40 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/12 10:47:29 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int PointValue; // For whole number
        static const int fractionalBits = 8; // for decimal portion
    public:
        // Default constructor
        Fixed();
        // Constructor that takes integer.
        Fixed(const int value);
        // Constructor that takes float-point number
        Fixed(const float value);
        // Copy constructor
        Fixed(const Fixed& copy);
        // Copy assignment operator
        Fixed& operator=(const Fixed& copy);
        // Destructor
        ~Fixed();

        // Members of function
        float toFloat( void ) const;
        int toInt( void ) const;
        
        int getRawBits(void) const;
        void setRawBits(int const newValue);
};

// represents an output stream!
// ostream a destination where you can send a data to be displayed or stored.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif