// 230925_наследование методов
//

#include <iostream>
using namespace std;

class Sit
{
public:
    int amountOfLegs;
    virtual void sit()
    {
        cout << "\n";
    }
};

class Stool :public Sit
{
public:
    Stool()
    {
        amountOfLegs = 3;
    };
    void sit()
    {
        cout << "====\n";
        cout << "=  =\n";
        cout << "=  =\n";
        cout << "=  =\n";
    }


};
class Chair :public Sit
{
public:
    Chair()
    {
        amountOfLegs = 4;
    };
    void sit()
    {
        cout << "=   \n";
        cout << "=   \n";
        cout << "====\n";
        cout << "=  =\n";
        cout << "=  =\n";
    }


};


class Armchair :public Sit
{
public:
    Armchair()
    {
        amountOfLegs = 2;
    };
    void sit()
    {
        cout << "#   \n";
        cout << "#   \n";
        cout << "####\n";
        cout << "####\n";
        cout << "####\n";
    }
};


int main()
{
    //Sit* genSit;
    //genSit = dynamic_cast<Sit*>(new Chair());
    //genSit->sit();

    int sitsCount = 4;
    Sit** sits = new Sit*[sitsCount];
    sits[0] = dynamic_cast<Stool*>(new Stool());
    sits[1] = dynamic_cast<Chair*>(new Chair());
    sits[2] = dynamic_cast<Armchair*>(new Armchair());
    sits[3] = dynamic_cast<Sit*>(new Armchair());

    for (int i = 0; i < sitsCount; i++)
    {
        cout << "Sit" << i + 1 << " has " << sits[i]->amountOfLegs << " legs." << "\n";
        sits[i]->sit();
        delete sits[i];// вся память которая выделена, должна быть освобождена

    }
    delete[] sits;
    return 0;
};

// идея - вложить в родительский класс значения дочернего через dynamic_cast
