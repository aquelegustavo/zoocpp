
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

#include "../globals.hpp"
#include "../utils.hpp"
#include "../db.hpp"
#include "../includes/json.hpp"

#include "animals.hpp"
#include "novoAnimal.hpp"
#include "operacoes.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
    // Inicialização da geração de números pseudos aleatórios
    srand((unsigned)time(NULL));

    int option;
    while (1)
    {
        cout << "\033[1;33m\n*******************************\n"
             << "Escolha uma das opções abaixo: \n"
             << "*******************************\033[0m\n\n";

        cout << " 1 - Registrar novo animal." << endl;
        cout << " 2 - Pesquisar animal por nome." << endl;
        cout << " 3 - Obter animal por ID." << endl;
        cout << " 4 - Excluir animal por ID." << endl;
        cout << " 5 - Sair." << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            // Registrar novo animal
            novoAnimal();
            break;

        case 2:
            pesquisarAnimalPorNome();
            break;

        case 3:
            // Obter animal.
            obterAnimal();
            break;

        case 4:
            deletarAnimal();
            break;

        case 5:
            return 0;

        default:
            cout << "\033[1;31m"
                 << "Opção inválida. Tente novamente."
                 << "\033[0m\n"
                 << endl;
            break;
        }
    }

    return 0;
}