/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:05:38 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 17:05:38 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T &a, const T &b) {
    return (b <= a) ? b : a; 
}

template <typename T>
const T& max(const T &a, const T &b) {
    return (b >= a) ? b : a;
}
