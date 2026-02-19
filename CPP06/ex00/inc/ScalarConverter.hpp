/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:06:34 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 10:06:34 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <iomanip>
# include <cctype>

enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    IMPOSSIBLE
};

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
    ScalarConverter & operator=(ScalarConverter const & src);

public:
    static void convert(std::string const & literal);
};

#endif
