#include <string>

using namespace std;

string getRandomId(int len)
{
    /*
    Obeter Id aleatório

    Params:
        (int) len: Tamanho do id requerido

    Returns:
        (string): Id gerado aleatóriamente
    */
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    string id;
    id.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        id += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return id;
}