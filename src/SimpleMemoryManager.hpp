#pragma once

#include <iostream>
#include <vector>

using namespace std;

// Variáveis estáticas para armazenar o primeiro e último índice do byte livre respectivamente
static unsigned index_first_free_byte = 0; 
static unsigned index_last_free_byte = 0;

class SimpleMemoryManager
{
private:
    vector<unsigned> memory;

public:
    // Inicializa a memória com o tamanho fornecido pelo usuário e preenche com 0 (livre)
    SimpleMemoryManager(unsigned size)
    {
        memory.resize(size);

        cout << "\t\t<><><><> >>>> Memory Manager <<<< <><><><>" << endl;
        cout << endl;
        cout << "- THE MEMORY MANAGER WAS CREATED WITH A SIZE OF " << size << " BYTES" << endl;
        cout << endl;
    }

    int alloc_memory(unsigned number_of_bytes)
    {
        // Contador de bytes livres
        unsigned count_of_free_bytes = 0;
        // Vetor que armazena os índices dos bytes livres
        vector<unsigned> arr_index_free_bytes;

        for (size_t i = 0; i < memory.size(); i++)
        {
            // Verifica se o byte atual é livre
            if (memory[i] == 0)
            {
                ++count_of_free_bytes;
                arr_index_free_bytes.push_back(i);
            }
            // Verifica se o byte atual é ocupado
            else
            {
                count_of_free_bytes = 0;
                arr_index_free_bytes.clear();
            }

            // Verifica se o contador e o tamanho do vetor corresponde ao número de bytes desejados
            if (count_of_free_bytes == number_of_bytes && arr_index_free_bytes.size() == number_of_bytes)
            {
                index_first_free_byte = arr_index_free_bytes[0];
                index_last_free_byte = arr_index_free_bytes[number_of_bytes - 1];
                arr_index_free_bytes.clear();
            
                break;
            }
        }

        if (count_of_free_bytes == number_of_bytes)
        {
            // cout << "\nIndex first free byte: " << index_first_free_byte << endl;

            // Preenche os bytes livres
            for (size_t i = index_first_free_byte; i < index_last_free_byte + 1; i++)
            {
                memory[i] = 1;
            }

            cout << "MEMORY ALLOCATION SUCCESSFUL. STARTING AT INDEX: [" << index_first_free_byte << "]" << " TO [" << index_last_free_byte << "]" << endl;
            show_memory();
            
            // Atualiza o índice do primeiro byte livre
            index_first_free_byte = index_last_free_byte + 1;
            return index_first_free_byte;
        }

        cerr << "MEMORY ALLOCATION FAILED. NO SPACE AVAILABLE" << endl;
        return -1;
    }

    void free_memory(int start, int number_of_bytes) {
        for(int i = start; i < start + number_of_bytes; i++) {
            memory[i] = 0;
        }

        cout << "MEMORY FREED FROM INDEX: [" << start << "] TO [" << start + number_of_bytes - 1 << "]" << endl;
        show_memory();
    }

    void show_memory()
    {
        cout << "[";
        for (size_t i = 0; i < memory.size(); i++)
        {
            if (i != 0)
                cout << " ";

            cout << " " << memory[i] << " ";
        }
        cout << "]";

        cout << endl;
        // Aqui conta os índices da memória, logo abaixo do array
        for (size_t i = 0; i < memory.size(); i++)
        {
            cout << "  " << i;

            if (i <= 9)
                cout << " ";
        }
    }
};