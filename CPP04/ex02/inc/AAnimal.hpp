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

/* AAnimal.hpp */
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &src);
    AAnimal &operator=(const AAnimal &src);
    
    // Destructor virtual (CRUCIAL como siempre)
    virtual ~AAnimal();

    // --- EL CAMBIO ESTÁ AQUÍ ---
    // El "= 0" convierte a esta función en "Virtual Pura".
    // Esto hace que la clase sea ABSTRACTA automáticamente.
    virtual void makeSound() const = 0;
    
    std::string getType() const;
};

#endif
