/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:34:16 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/04 20:34:16 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MateriaSource.hpp
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* _templates[4]; // Guarda copias para clonar

public:
    MateriaSource();
    MateriaSource(const MateriaSource &src);
    MateriaSource &operator=(const MateriaSource &src);
    ~MateriaSource();

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);
};

#endif
