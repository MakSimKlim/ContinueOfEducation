// 230920_запись_чтение массива в _из_файла
//

#include <iostream>
#include <Windows.h>
#include <fstream>
#include <iomanip>

using namespace std;




int main()
{
    char answer;
    const int messageCount = 8;
    int i, j;

    enum
    {
        CHOICE = 3,// РАЗМЕРНОСТЬ МАССИВА, равно числу пнуктов в string msg
        INPUT_FILENAME,// соответствуют индексам строчек в string msg
        INPUT_DIMENSIONS,
        INPUT_ELEMENTS,
        FILE_ERROR


    };


    string msg[messageCount]
    {
        "1. Read data from the text file\n",
        "2. Write data into the text file\n",
        "3. Exit\n",
        "\nYour choice:",
        "\nEnter the file's name: ",
        "Enter matrix size: ",
        "Enter matrix elements: ",
        "Couldnt open the file\n"
    };

    do
    {
        for (i = 0; i < 4; i++)
        {
            cout << msg[i];
        }
        cin >> answer;

    } while (answer < '1' || answer > '3');

    if (answer == '3')
    {
        return 0;
    }

    string fileName;//строка с именем файла
    int M, N;//размеры матрицы
    int num;

    cout << msg[INPUT_FILENAME];
    cin >> fileName;

    if (answer == 1)
    {
        ifstream inF(fileName.c_str(), ios::in | ios::_Nocreate);//_Nocreate - файл не должен создаваться
        if (!inF)
        {
            cout << endl << msg[FILE_ERROR];
            return 0;

        }
        inF >> N;
        inF >> M;
        for ( i = 0; i < N; i++)
        {
            for (j = 0; j < M; j++)
            {
                inF >> num;
                cout << setw(6) << num;


            }
            cout << endl;
        }
        inF.close();
    }
    else//answer ==2
    {
        ofstream outF(fileName.c_str(), ios::out);
        if (!outF)
        {
            cout << endl << msg[FILE_ERROR];
            return 0;
        }

        cout << msg[INPUT_DIMENSIONS];
        cout << "\nN:"; cin >> N;
        cout << "\nM:"; cin >> M;
        outF << N << ' ' << M << '\n';
        cout << msg[INPUT_ELEMENTS];
        for ( i = 0; i < N; i++)
        {
            for ( j = 0; j < M; j++)
            {
                cout << "A[" << i << ", " << j << "] = ";
                cin >> num;
                outF << num << ' ';

            }
            outF << '\n';

        }
        outF.close();
    }


    return 0;
}

