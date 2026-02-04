/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:32:45 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/04 20:32:45 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Ice.hpp
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
public:
    Ice();
    Ice(const Ice &src);
    Ice &operator=(const Ice &src);
    ~Ice();

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
