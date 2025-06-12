/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:45:40 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/12 09:37:06 by hpehliva         ###   ########.fr       */
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
        // Copy constructor
        Fixed(const Fixed& copy);
        // Copy assignment operator
        Fixed& operator=(const Fixed& copy);
        // Destructor
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits(int const newValue);
};


#endif