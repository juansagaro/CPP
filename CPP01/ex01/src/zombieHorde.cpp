#include "../inc/Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    // 1. Asignación única de memoria para N objetos.
    // Esto llama al constructor por defecto N veces.
    Zombie* horde = new Zombie[N];

    // 2. Inicialización de cada zombie
    for (int i = 0; i < N; i++) {
        // Usamos el setter porque ya están creados
        horde[i].setName(name);
    }

    // 3. Retornamos el puntero al inicio del array
    return horde;
}