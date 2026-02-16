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

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* _brain;

public:
    Dog();
    Dog(const Dog &src);
    Dog &operator=(const Dog &src);
    virtual ~Dog();

    virtual void makeSound() const;

    void compareIdeas(const Dog &other) const;
};

#endif
