/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:57:31 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 11:57:31 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

int main() {
    std::srand(std::time(NULL));

    std::cout << "--- TEST 1: RANDOM OBJECT ---" << std::endl;
    Base* obj1 = generate();
    std::cout << "Pointer identify:   "; identify(obj1);
    std::cout << "Reference identify: "; identify(*obj1);
    delete obj1;

    std::cout << "\n--- TEST 2: RANDOM OBJECT ---" << std::endl;
    Base* obj2 = generate();
    std::cout << "Pointer identify:   "; identify(obj2);
    std::cout << "Reference identify: "; identify(*obj2);
    delete obj2;

    std::cout << "\n--- TEST 3: RANDOM OBJECT ---" << std::endl;
    Base* obj3 = generate();
    std::cout << "Pointer identify:   "; identify(obj3);
    std::cout << "Reference identify: "; identify(*obj3);
    delete obj3;

	std::cout << "\n--- TEST 4: UNKNOWN TYPE ---" << std::endl;
    Base pureBase;
    std::cout << "Pointer identify:   "; identify(&pureBase);
    std::cout << "Reference identify: "; identify(pureBase);

    return 0;
}
