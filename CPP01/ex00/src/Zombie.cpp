#include "../inc/Zombie.hpp"

// Constructor: Usamos lista de inicialización para eficiencia
Zombie::Zombie(std::string name) : _name(name) {
}

// Destructor: Se llama automáticamente al destruir el objeto
Zombie::~Zombie() {
    std::cout << this->_name << ": ha sido destruido (Debug message)" << std::endl;
}

void Zombie::announce(void) {
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}