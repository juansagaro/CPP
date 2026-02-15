/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:18:01 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/15 20:14:53 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "--- PRUEBA 1: DEBUG ---" << std::endl;
    harl.complain("DEBUG");
    
    std::cout << "\n--- PRUEBA 2: INFO ---" << std::endl;
    harl.complain("INFO");
    
    std::cout << "\n--- PRUEBA 3: WARNING ---" << std::endl;
    harl.complain("WARNING");
    
    std::cout << "\n--- PRUEBA 4: ERROR ---" << std::endl;
    harl.complain("ERROR");
    
    std::cout << "\n--- PRUEBA 5: INEXISTENTE ---" << std::endl;
    harl.complain("UNKNOWN");

    return 0;
}