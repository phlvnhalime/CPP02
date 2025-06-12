/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:09:29 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/12 09:35:30 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): PointValue(0) {
    std::cout << "Default constructor called" << std::endl;
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

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return this->PointValue;
}

void Fixed::setRawBits(int const newValue) {
    this->PointValue = newValue;
}


