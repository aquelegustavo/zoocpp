#include <iostream>

int obterAnimal()
{
    Collection db("animals");

    cout << "\033[1;34m"
         << "\nInforme o ID do animal: "
         << "\033[0m";

    string id;
    cin >> id;

    try
    {
        json doc = db.getDocument(id);

        for (auto el = doc.begin(); el != doc.end(); ++el)
        {
            cout << el.key() << ": " << el.value()["value"] << endl;
        }
    }
    catch (string error)
    {
        cout << "\033[1;31m" << error << "\033[0m\n"
             << endl;
    }

    return 0;
}

int deletarAnimal()
{
    Collection db("animals");

    cout << "\033[1;34m"
         << "\nInforme o ID do animal: "
         << "\033[0m";

    string id;
    cin >> id;

    try
    {
        db.removeDocument(id);
    }
    catch (string error)
    {
        cout << "\033[1;31m" << error << "\033[0m\n"
             << endl;
    }

    return 0;
}

int pesquisarAnimalPorNome()
{
    Collection db("animals");

    cout << "\033[1;34m"
         << "\nInforme o nome do animal: "
         << "\033[0m";

    string value;
    cin >> value;

    try
    {

        json search = db.findDocument("nome", value);

        if (search.size() == 0)
        {
            throw string("Nenhum animal não encontrado.");
        }

        for (auto doc = search.begin(); doc != search.end(); ++doc)
        {
            for (auto el = doc->begin(); el != doc->end(); ++el)
            {
                cout << el.key() << ": " << el.value()["value"] << endl;
            }

            cout << "\n";
        }
    }
    catch (string error)
    {
        cout << "\033[1;31m" << error << "\033[0m\n"
             << endl;
    }
}