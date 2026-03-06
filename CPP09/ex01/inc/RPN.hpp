/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 17:13:45 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/03/06 19:02:12 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <stack>
# include <cstdlib>

class RPN {
private:
    std::stack<int> _stack;

    bool isOperator(char c) const;
    bool performOperation(char op);

public:
    RPN();
    RPN(const RPN& src);
    RPN& operator=(const RPN& src);
    ~RPN();

    void calculate(const std::string& expression);
};
