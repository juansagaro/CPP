/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 11:16:20 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/03 11:16:20 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Cat.hpp */
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &src);
    ~Cat();
    void makeSound() const; // Sobrescribe la del padre
};

#endif