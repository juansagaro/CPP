/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 10:07:37 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 10:07:37 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverter.hpp"

// =========================================================================
// 1. FUNCIONES DE DETECCIÓN (Detect the type)
// =========================================================================

static e_type detectType(const std::string& literal) {
    if (literal.empty()) return IMPOSSIBLE;

    std::string pseudo[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    for (int i = 0; i < 6; i++) {
        if (literal == pseudo[i]) return PSEUDO;
    }

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        return CHAR;
    }

    char* endptr;

    double val = std::strtod(literal.c_str(), &endptr);

    if (endptr == literal.c_str()) return IMPOSSIBLE;

    if (*endptr == '\0') {
        if (literal.find('.') == std::string::npos) {
            if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
                return INT;
            else
                return DOUBLE;
        }
        return DOUBLE;
    }

    if (*endptr == 'f' && *(endptr + 1) == '\0') return FLOAT;

    return IMPOSSIBLE;
}

// =========================================================================
// 2. FUNCIONES DE IMPRESIÓN MODULARES
// =========================================================================

static void printOutputs(char c, int i, float f, double d, bool charOk, bool intOk) {
    if (!charOk)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    if (!intOk)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

// =========================================================================
// 3. FUNCIONES DE CONVERSIÓN (Convert to actual type, then explicitly cast)
// =========================================================================

static void convertFromChar(const std::string& literal) {
    char c = literal[0];
    printOutputs(
        c, 
        static_cast<int>(c),
        static_cast<float>(c),
        static_cast<double>(c),
        true, true
    );
}

static void convertFromInt(const std::string& literal) {
    long long check = std::atol(literal.c_str());
    if (check < std::numeric_limits<int>::min() || check > std::numeric_limits<int>::max()) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
        return;
    }
    
    int i = static_cast<int>(check);
    printOutputs(
        static_cast<char>(i),
        i, 
        static_cast<float>(i),
        static_cast<double>(i),
        (i >= std::numeric_limits<char>::min() && i <= std::numeric_limits<char>::max()), 
        true
    );
}

static void convertFromFloat(const std::string& literal) {
    float f = std::strtof(literal.c_str(), NULL);

    printOutputs(
        static_cast<char>(f), 
        static_cast<int>(f), 
        f, 
        static_cast<double>(f), 
        (f >= std::numeric_limits<char>::min() && f < 128 && !std::isnan(f) && !std::isinf(f)), 
        (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max() && !std::isnan(f) && !std::isinf(f))
    );
}

static void convertFromDouble(const std::string& literal) {
    double d = std::strtod(literal.c_str(), NULL);
    printOutputs(
        static_cast<char>(d), 
        static_cast<int>(d), 
        static_cast<float>(d), 
        d, 
        (d >= std::numeric_limits<char>::min() && d < 128 && !std::isnan(d) && !std::isinf(d)), 
        (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max() && !std::isnan(d) && !std::isinf(d))
    );
}

static void convertPseudo(const std::string& literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf\ndouble: nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff\ndouble: +inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff\ndouble: -inf" << std::endl;
    }
}

// =========================================================================
// MÉTODO PRINCIPAL
// =========================================================================

void ScalarConverter::convert(std::string const & literal) {
    e_type type = detectType(literal);

    switch (type) {
        case CHAR:      convertFromChar(literal); break;
        case INT:       convertFromInt(literal); break;
        case FLOAT:     convertFromFloat(literal); break;
        case DOUBLE:    convertFromDouble(literal); break;
        case PSEUDO:    convertPseudo(literal); break;
        default:
            std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
            break;
    }
}
