#include <string>

#include "includes/json.hpp"
#include "globals.hpp"

using namespace std;
using json = nlohmann::json;

class Collection
{
private:
    string _collectionId;

public:
    Collection(string collectionId)
    {
        _collectionId = collectionId;
    }

    json getDocument(string documentId);

    json findDocument(string key, string value);

    string setDocument(json documentData, string documentId);

    void removeDocument(string documentId);
};

json Collection::getDocument(string documentId)
{

    ifstream fileDataInput(DATABASE_FILENAME);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    json document = jsonInput[_collectionId][documentId];

    if (document == nullptr)
    {
        throw string("Documento não encontrado");
    }

    fileDataInput.close();

    return document;
};

json Collection::findDocument(string key, string value)
{

    ifstream fileDataInput(DATABASE_FILENAME);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    json collection = jsonInput[_collectionId];

    json search = json::array();

    for (auto doc = collection.begin(); doc != collection.end(); ++doc)
    {
        string docId = doc.key();
        json docData = doc.value();

        json field = doc.value()[key];

        if (field == nullptr)
        {
            throw string("Campo não encontrado");
        }

        string fieldValue = doc.value()[key]["value"];

        size_t found = fieldValue.find(value);
        if (found != string::npos)
        {
            search.push_back(docData);
        }
    }

    return search;
};

string Collection::setDocument(json documentData, string documentId = getRandomId(DOCUMENT_ID_SIZE))
{

    ifstream fileDataInput(DATABASE_FILENAME);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    jsonInput[_collectionId][documentId] = documentData;

    ofstream fileDataOutput(DATABASE_FILENAME, ios::trunc);

    fileDataOutput << setw(4) << jsonInput;

    fileDataInput.close();
    fileDataOutput.close();

    return documentId;
};

void Collection::removeDocument(string documentId)
{
    ifstream fileDataInput(DATABASE_FILENAME);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    jsonInput[_collectionId].erase(documentId);

    json document = jsonInput[_collectionId][documentId];

    if (document == nullptr)
    {
        throw string("Documento não encontrado");
    }

    ofstream fileDataOutput(DATABASE_FILENAME, ios::trunc);

    fileDataOutput << setw(4) << jsonInput;

    fileDataInput.close();
    fileDataOutput.close();
};