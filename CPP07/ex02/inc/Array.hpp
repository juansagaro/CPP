/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:08:25 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/20 17:11:37 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <exception>
# include <cstdlib>
# include <ctime>

template <typename T>
class Array {
private:
    T* _array;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& src);
    Array& operator=(const Array& src);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

    class OutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Error: Index out of bounds!";
        }
    };
};

# include "Array.tpp"
