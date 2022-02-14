#include <iostream>
#include <fstream>
#include <string>

#include "lib/utils.hpp"
#include "lib/globals.hpp"
#include "lib/db.hpp"
#include "lib/includes/json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    // Inicialização da geração de números pseudos aleatórios
    srand((unsigned)time(NULL));

    Collection db("users");

    json docData = {
        {"name", "Gustavo"},
        {"course", "Engenharia de Computação"},
        {"university", "UFSC"}};

    // Adicionar documento
    string docId = db.setDocument(docData);
    cout << "Documento " << docId << " criado com sucesso!";

    // Editar documento existente
    docData["happy"] = true;
    db.setDocument(docData, "lassHShGhNw9dbQS");

    // Buscar documentos
    json search = db.findDocument("name", "Débora");
    cout << search;

    // Remover documento
    db.removeDocument("lassHShGhNw9dbQS");

    return 0;
}