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

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* _brain; // <--- Nuevo atributo puntero

public:
    Cat();
    Cat(const Cat &src);
    Cat &operator=(const Cat &src);
    virtual ~Cat(); // Virtual es buena práctica aunque herede

    virtual void makeSound() const;
    
    // Método extra para probar que las ideas son independientes
    void compareIdeas(const Cat &other) const;
};

#endif
