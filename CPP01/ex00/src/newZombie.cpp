#include "../inc/Zombie.hpp"

Zombie* newZombie(std::string name) {
    // 'new' asigna memoria en el HEAP.
    // El objeto persiste hasta que alguien llame a 'delete'.
    return new Zombie(name);
}