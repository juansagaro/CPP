/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:15:28 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:15:28 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Animal.hpp */
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &src);
    Animal &operator=(const Animal &src);
    
    // IMPORTANTE: Destructor virtual para evitar leaks al borrar hijos
    virtual ~Animal();

    // IMPORTANTE: 'virtual' permite que los hijos sobrescriban este comportamiento
    virtual void makeSound() const;
    
    std::string getType() const;
};

#endif
