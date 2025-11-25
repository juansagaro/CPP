#include "../inc/Zombie.hpp"

int main() {
    // 1. Probando la STACK
    std::cout << "--- Llamando a randomChump ---" << std::endl;
    randomChump("StackZombie"); 
    // Verás el mensaje del destructor inmediatamente después de announce
    
    std::cout << "\n--- Llamando a newZombie ---" << std::endl;
    // 2. Probando el HEAP
    Zombie* heapZ = newZombie("HeapZombie");
    heapZ->announce();
    
    // El HeapZombie sigue vivo aquí.
    std::cout << "El HeapZombie sigue vivo en el main..." << std::endl;

    // IMPORTANTE: Debemos borrarlo manualmente o tendremos un "Memory Leak"
    delete heapZ; 

    return 0;
}