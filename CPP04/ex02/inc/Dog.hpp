/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:10 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:16:10 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* _brain; // <--- Nuevo atributo puntero

public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &src);
    virtual ~Dog(); // Virtual es buena práctica aunque herede

    virtual void makeSound() const;
    
    // Método extra para probar que las ideas son independientes
    void compareIdeas(const Dog &other) const;
};

#endif
