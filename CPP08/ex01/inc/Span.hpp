/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 20:16:03 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/21 20:16:03 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <vector>
# include <exception>
# include <iterator>
# include <algorithm>
# include <limits>

class Span {
private:
    unsigned int        _maxSize;
    std::vector<int>    _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& src);
    Span& operator=(const Span& src);
    ~Span();

    void addNumber(int number);

    template <typename Iterator>
    void addNumber(Iterator begin, Iterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw SpanFullException();
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Error: Span is already full!"; }
    };

    class NotEnoughElementsException : public std::exception {
    public:
        virtual const char* what() const throw() { return "Error: Not enough elements to calculate span!"; }
    };
};
