/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:36:59 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/20 16:30:03 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <cstddef>
# include <iostream>
# include <string>

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T>
void iter(T const * array, size_t length, void (*func)(T const &)) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}
