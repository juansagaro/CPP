/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceString.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsagaro- <jsagaro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 21:18:30 by jsagaro-          #+#    #+#             */
/*   Updated: 2025/11/25 21:19:47 by jsagaro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/sedIsForLosers.hpp"

// Función auxiliar para reemplazar todas las ocurrencias
// Pasamos el string por referencia para modificarlo directamente
void replaceString(std::string& content, const std::string& s1, const std::string& s2) {
    if (s1.empty()) {
        return; // Si lo que buscamos está vacío, no hacemos nada para evitar bucles
    }

    size_t pos = 0;
    
    // find devuelve la posición del primer carácter de la coincidencia
    // npos es un valor especial que significa "no encontrado"
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        
        // 1. Borramos s1 desde la posición encontrada
        content.erase(pos, s1.length());
        
        // 2. Insertamos s2 en la misma posición
        content.insert(pos, s2);
        
        // 3. Avanzamos la posición para seguir buscando DESPUÉS de lo que acabamos de insertar
        pos += s2.length();
    }
}