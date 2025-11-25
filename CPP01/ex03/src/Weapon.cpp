/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:51:36 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/24 18:51:36 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type)
{
}
Weapon::~Weapon()
{
}
const std::string& Weapon::getType() const
{
	return _type;
}

void Weapon::setType(const std::string& type)
{
	_type = type;
}

