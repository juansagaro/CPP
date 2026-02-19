/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:22:12 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 11:22:12 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer {
private:
    Serializer();
    Serializer(Serializer const & src);
    ~Serializer();
    Serializer & operator=(Serializer const & src);

public:
    static uintptr_t serialize(Data* ptr);

    static Data* deserialize(uintptr_t raw);
};

#endif
