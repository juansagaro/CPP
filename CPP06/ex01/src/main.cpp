/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 11:22:55 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/19 11:22:55 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"
#include <iostream>

int main() {
    Data originalData;
    originalData.id = 42;
    originalData.name = "Marvin";
    originalData.level = 9000.1f;

    std::cout << "--- ORIGINAL OBJECT ---" << std::endl;
    std::cout << "Address: " << &originalData << std::endl;
    std::cout << "ID:      " << originalData.id << std::endl;
    std::cout << "Name:    " << originalData.name << std::endl;
    std::cout << "Level:   " << originalData.level << "\n" << std::endl;

    uintptr_t serializedData = Serializer::serialize(&originalData);
    
    std::cout << "--- SERIALIZATION ---" << std::endl;
    std::cout << "Raw uintptr_t value: 0x" << std::hex << serializedData << std::dec << "\n" << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);

    std::cout << "--- DESERIALIZATION ---" << std::endl;
    std::cout << "Address: " << deserializedData << std::endl;
    std::cout << "ID:      " << deserializedData->id << std::endl;
    std::cout << "Name:    " << deserializedData->name << std::endl;
    std::cout << "Level:   " << deserializedData->level << "\n" << std::endl;

    std::cout << "--- VERIFICATION ---" << std::endl;
    if (&originalData == deserializedData) {
        std::cout << "SUCCESS: Pointers match perfectly!" << std::endl;
    } else {
        std::cout << "ERROR: Pointers do not match!" << std::endl;
    }

    return 0;
}
