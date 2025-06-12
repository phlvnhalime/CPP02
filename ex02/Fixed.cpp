/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:09:29 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/12 10:56:12 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
}

// For integer constructor function.
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    PointValue = value << fractionalBits;
}

// Float constructor.
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    PointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& copy) : PointValue(copy.PointValue){
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator is like:
// You already existed, but now a new piece of information has arrived, let's load it up on you! 
Fixed& Fixed::operator=(const Fixed& copy) {
    std::cout << "Copy assignment operator called" << std::endl;
    
    if(this != &copy) // It is check so that there is no self-assigment.
    {
        this->PointValue = copy.PointValue;
    }
    return *this;
}

//Destructor
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const{
    return static_cast<float>(PointValue) / (1 << fractionalBits);
    /*
        static_cast<new_type>(expression)
        Convert before the integer as float!
    */
}

int Fixed::toInt( void ) const{
    return PointValue >> fractionalBits;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->PointValue;
}

void Fixed::setRawBits(int const newValue) {
    this->PointValue = newValue;
}

std::ostream& operator<<(std::ostream& out,const Fixed& fixed){
    out << fixed.toFloat();
    return out;
}
