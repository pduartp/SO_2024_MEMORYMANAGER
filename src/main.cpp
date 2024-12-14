#include <iostream>
#include <vector>

#include "SimpleMemoryManager.hpp"

using namespace std;

int main()
{
    // Criando um gerenciador de memória com 20 bytes
    SimpleMemoryManager memoryManager(20);

    std::cout << "Memoria inicial: " << endl;
    memoryManager.show_memory();

    cout << endl;
    cout << "\nTentando alocar 5 bytes..." << endl;
    memoryManager.alloc_memory(5);

    cout << endl;
    cout << "\nTentando alocar 8 bytes..." << endl;
    memoryManager.alloc_memory(8);

    cout << endl;
    cout << "\nLiberando 5 bytes comeaando do indice 0..." << endl;
    memoryManager.free_memory(0, 5);

    cout << endl;
    cout << "\nTentando alocar 5 bytes novamente..." << endl;
    memoryManager.alloc_memory(5);

    return 0;
}