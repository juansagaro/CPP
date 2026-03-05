/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:20:20 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/21 20:20:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& src) : _maxSize(src._maxSize), _numbers(src._numbers) {}

Span& Span::operator=(const Span& src) {
    if (this != &src) {
        _maxSize = src._maxSize;
        _numbers = src._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() <= 1) {
        throw NotEnoughElementsException();
    }
    std::vector<int> sorted_numbers = _numbers;
    
    std::sort(sorted_numbers.begin(), sorted_numbers.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        unsigned int span = static_cast<unsigned int>(sorted_numbers[i]) - static_cast<unsigned int>(sorted_numbers[i - 1]);
        if (span < minSpan) {
            minSpan = span;
        }
    }

    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() <= 1) {
        throw NotEnoughElementsException();
    }

    std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());

    std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());

    return static_cast<unsigned int>(*max_it) - static_cast<unsigned int>(*min_it);
}
