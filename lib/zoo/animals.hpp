#include <iostream>
#include <string>
#include <vector>
#include <utility>

class Animal
{
public:
    Animal()
    {
        setCategorie("nome", "string");
        setCategorie("idade", "int");
        setCategorie("especie", "string");
    }

    vector<pair<string, string> > getCategories()
    {
        return categories;
    }

protected:
    void setCategorie(string key, string type)
    {
        categories.push_back(make_pair(key, type));
    }

    vector<pair<string, string> > categories;
};

class Ave : public Animal
{
public:
    Ave()
    {
        setCategorie("tamanhoDoBico", "int");
        setCategorie("corDasPenas", "string");
    }
};

class Mamifero : public Animal
{
private:
    int quantidadeDePatas;
    string cor;

public:
    Mamifero()
    {
        setCategorie("quantidadeDePatas", "int");
        setCategorie("cor", "string");
    }
};

class Flamingo : public Ave
{
private:
    int tamanhoDasPatas;

public:
    Flamingo()
    {
        setCategorie("tamanhoDasPatas", "int");
    }
};

class Pavao : public Ave
{
private:
    int sexo;

public:
    Pavao()
    {
        setCategorie("sexo", "string");
    }
};

class Girafa : public Mamifero
{
private:
    int tamanhoDoPescoco;

public:
    Girafa()
    {
        setCategorie("tamanhoDoPescoco", "int");
    }
};

class Elefante : public Mamifero
{
private:
    int peso;

public:
    Elefante()
    {
        setCategorie("peso", "double");
    }
};

class Zebra : public Mamifero
{
private:
    int quantidadeDeListras;

public:
    Zebra()
    {
        setCategorie("quantidadeDeListras", "int");
    }
};
