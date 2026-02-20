/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 17:10:37 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/20 17:52:01 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "--- TEST DEL SUBJECT ---" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }

    std::cout << "\n--- Muestreo Array<int> (Primeros 5 elementos) ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    std::cout << "..." << std::endl;
    std::cout << "Size total: " << numbers.size() << "\n" << std::endl;

    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "[OK] Deep Copy verificada. 'numbers' sobrevive al scope.\n" << std::endl;

    std::cout << "--- Probando protección de límites ---" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Acceso numbers[-2]       -> " << e.what() << '\n';
    }
    
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Acceso numbers[MAX_VAL]  -> " << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    std::cout << "\n--- TEST EXTRA: OTRAS PLANTILLAS ---" << std::endl;
    std::cout << "\n--- Muestreo Array<std::string> ---" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hola";
    strArray[1] = "Mundo";
    strArray[2] = "42";
    
    for (unsigned int i = 0; i < strArray.size(); i++) {
        std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;
    }

    return 0;
}
