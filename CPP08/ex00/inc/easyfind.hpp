/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 19:43:50 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/20 19:48:31 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <algorithm>
# include <exception>
# include <iterator>
# include <iostream>
# include <vector>
# include <list>

class NotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Error: Element not found in container.";
    }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    if (it == container.end()) {
        throw NotFoundException();
    }

    return it;
}
