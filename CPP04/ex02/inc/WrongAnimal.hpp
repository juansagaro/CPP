/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:20:07 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:20:07 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    // Constructores y Destructor (OCF)
    WrongAnimal();
    WrongAnimal(const WrongAnimal &src);
    WrongAnimal &operator=(const WrongAnimal &src);
    ~WrongAnimal(); // ¡ERROR: Debería ser virtual, pero aquí lo hacemos mal a propósito!

    // Métodos
    void makeSound() const; // ¡ERROR: Sin virtual no hay polimorfismo!
    std::string getType() const;
};

#endif
