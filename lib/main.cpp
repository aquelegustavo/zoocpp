#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

#include "utils.hpp"
#include "globals.hpp"
#include "db.hpp"
#include "includes/json.hpp"

using namespace std;
using json = nlohmann::json;

template <typename T>
class FieldValue
{
private:
    vector<json> _data;

public:
    FieldValue(string key, T value);

    vector<json> get()
    {
        return _data;
    }
};

template <typename T>
FieldValue<T>::FieldValue(string key, T value)
{
    {
        pair<string, T> field(key, value);

        json fieldFormat = {{field.first, field.second}};

        _data.push_back(fieldFormat);
    }
}

int main()
{
    // Inicialização da geração de números pseudos aleatórios
    srand((unsigned)time(NULL));

    Collection users("users");

    cout << FieldValue<string>("especie", "flamingo").get();

    // cout << documentData.get()[0];
    // users.setDocument();

    return 0;
}