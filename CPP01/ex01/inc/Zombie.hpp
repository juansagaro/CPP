#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
    std::string _name;

public:
    // Constructor por defecto (NECESARIO para arreglos)
    Zombie();
    
    // Constructor con nombre (del ex00, opcional aquí pero bueno mantenerlo)
    Zombie(std::string name);
    
    // Destructor
    ~Zombie();

    void announce(void);
    
    // Nuevo método para asignar nombre después de crear
    void setName(std::string name);
};

// Prototipo de la función del ejercicio
Zombie* zombieHorde(int N, std::string name);

#endif