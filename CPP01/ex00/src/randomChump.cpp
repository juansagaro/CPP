#include "../inc/Zombie.hpp"

void randomChump(std::string name) {
    // Esta instancia se crea en la STACK.
    Zombie z(name);
    
    z.announce();

    // Cuando la función termina (aquí), 'z' sale del ámbito 
    // y su destructor se llama automáticamente.
}