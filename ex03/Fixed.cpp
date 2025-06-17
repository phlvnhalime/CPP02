/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:09:29 by hpehliva          #+#    #+#             */
/*   Updated: 2025/06/17 12:11:35 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(): PointValue(0) {
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
// Output stream objects can write sequences of characters and represent other kinds of data
std::ostream& operator<<(std::ostream& out,const Fixed& fixed){
    out << fixed.toFloat();
    return out;
}

// Operators:
bool Fixed::operator>(const Fixed& other) const{
    return PointValue > other.PointValue;
}

bool Fixed::operator<(const Fixed& other) const{
    return PointValue < other.PointValue;
}
bool Fixed::operator>=(const Fixed& other) const{
    return PointValue >= other.PointValue;
}

bool Fixed::operator<=(const Fixed& other) const{
    return PointValue <= other.PointValue;
}

bool Fixed::operator==(const Fixed& other) const{
    return PointValue == other.PointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return PointValue != other.PointValue;
}


// operators::

Fixed Fixed::operator+(const Fixed& other) const{
    Fixed result;
    result.PointValue = this->PointValue + other.PointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const{
    Fixed result;
    result.PointValue = this->PointValue - other.PointValue;
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const{
    Fixed result;
    result.PointValue = (static_cast<long long>(this->PointValue) * other.PointValue) >> fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const{
    Fixed result;
    result.PointValue = (static_cast<long long>(this->PointValue) << fractionalBits) / other.PointValue;
    return result;
}


// Increment and decrement
Fixed& Fixed::operator++(void){
    ++PointValue; // Increment by the smallest representable value.
    return *this;
}
Fixed Fixed::operator++(int){
    Fixed temp(*this); // Save current value.
    this->PointValue++;
    return temp; 
}
Fixed& Fixed::operator--(void){
    --PointValue; // Decrement
    return *this;
}
Fixed Fixed::operator--(int){
    Fixed temp(*this); //Save current value
    this->PointValue--;

    return temp;
}


// Static min/max function for non-const references
Fixed& Fixed::max(Fixed& a, Fixed& b){
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
    return (a > b) ? a : b;
}

Fixed& Fixed::min(Fixed& a, Fixed& b){
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b){
    return (a < b) ? a : b;
}