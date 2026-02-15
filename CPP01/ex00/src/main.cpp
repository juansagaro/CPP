#include "../inc/Zombie.hpp"

int main() {
    std::cout << "--- Llamando a randomChump ---" << std::endl;
    randomChump("StackZombie"); 
    
    std::cout << "\n--- Llamando a newZombie ---" << std::endl;
    Zombie* heapZ = newZombie("HeapZombie");
    heapZ->announce();
    
    std::cout << "El HeapZombie sigue vivo en el main..." << std::endl;

    delete heapZ; 

    return 0;
}