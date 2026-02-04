/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:32:58 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/04 20:32:58 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Cure.hpp
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure &src);
    Cure &operator=(const Cure &src);
    ~Cure();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
