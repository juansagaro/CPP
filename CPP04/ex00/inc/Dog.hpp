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

/* Dog.hpp */
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &src);
    ~Dog();

    void makeSound() const; // Sobrescribe la del padre
};

#endif
