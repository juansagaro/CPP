/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:13:45 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/13 19:25:39 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>
# include <sstream>

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool performOperation(const std::string& op);
    bool isNumber(const std::string& token) const;

public:
    RPN();
    RPN(const RPN& src);
    RPN& operator=(const RPN& src);
    ~RPN();

    void calculate(const std::string& expression);
};
