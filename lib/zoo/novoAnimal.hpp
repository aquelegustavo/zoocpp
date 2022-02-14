#include <iostream>

int novoAnimal()
{

    int option;
    Animal *animal;

    cout << "\033[1;33m"
         << "\n\nSelecione um animal: \n\n"
         << "\033[0m";

    cout << " 1 - Flamingo" << endl;
    cout << " 2 - Pavão" << endl;
    cout << " 3 - Girafa" << endl;
    cout << " 4 - Elefante" << endl;
    cout << " 5 - Zebra" << endl;
    cout << " 6 - Voltar ao menu principal" << endl;

    cin >> option;

    switch (option)
    {
    case 1:
        animal = new Flamingo;
        break;

    case 2:
        animal = new Pavao;
        break;

    case 3:
        animal = new Girafa;
        break;

    case 4:
        animal = new Elefante;
        break;

    case 5:
        animal = new Zebra;
        break;

    case 6:
        return 0;

    default:
        cout << "\033[1;31m"
             << "Opção inválida."
             << "\033[0m\n"
             << endl;
        break;
    }

    json docData;

    for (size_t i = 0; i < animal->getCategories().size(); i++)
    {
        string key = animal->getCategories()[i].first;
        string type = animal->getCategories()[i].second;

        docData[key]["key"] = key;
        docData[key]["type"] = type;

        cout << key << " (" << type << "): ";

        string temp;
        cin >> temp;

        docData[key]["value"] = temp;
    }

    Collection db("animals");

    db.setDocument(docData);

    delete animal;

    return 0;
}