/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:45:40 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/14 13:29:44 by hpehliva         ###   ########.fr       */
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

        // Members of function Convert functions.
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits(void) const;
        void setRawBits(int const newValue);

        // comparison operators: Must be 6
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;

        // Operators: Must be 4
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;

        // Static functions min/max function
        static Fixed& min(Fixed&a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed&a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);

        // Pre-Increment Post-Increment pre-decrement and post-decrement
        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);
        
};

// represents an output stream!
// ostream a destination where you can send a data to be displayed or stored.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif