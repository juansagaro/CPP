/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:34:25 by jsagaro-          #+#    #+#             */
/*   Updated: 2026/02/04 20:34:25 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// MateriaSource.cpp
#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src) {
    for (int i = 0; i < 4; i++) {
        if (src._templates[i])
            this->_templates[i] = src._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
    if (this != &src) {
        for (int i = 0; i < 4; i++) {
            if (this->_templates[i])
                delete this->_templates[i];
            this->_templates[i] = NULL;
        }
        for (int i = 0; i < 4; i++) {
            if (src._templates[i])
                this->_templates[i] = src._templates[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++) {
        if (_templates[i])
            delete _templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m) return;
    for (int i = 0; i < 4; i++) {
        if (_templates[i] == NULL) {
            _templates[i] = m;
            return;
        }
    }

    delete m; 
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type)
            return _templates[i]->clone();
    }
    return 0;
}
