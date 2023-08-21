// 230821_перегрузка ( )
// перегрузка круглых скобок
// 
// () перегружаются любыми действиями
// "+" большая гибкость
// "-" неявность
// можно пользоваться, если понятно, что делает код при перегрузке ()
//
// Общая сигнатура:
// ReturnType operator()()
// ReturnType operator()(ParamTypeA paramA)
// ReturnType operator()(ParamTypeA paramA, ParamTypeB paramB)
// { <code> };

// Matrix[1][5]

#include <iostream>
#include <time.h>
#include "Array2d.h"
#include "Matrix.h"
using namespace std;

//int sum(int a, int b)
//{
//    return a + b;
//
//}

int main()
{
    srand(time(0)); // ()-оператор вызова функции
                    // Данный оператор можно перегрузить ТОЛЬКО методом!!!
                    // Нельзя перегрузить дружественной функцией

    int rows{ 3 };
    int columns{ 3 };

    //Array2D a2d{ rows,columns };
    //for (int y = 0; y < rows; y++)
    //{
    //    for (int x = 0; x < columns; x++)
    //    {
    //        a2d.data[y][x] = 1 + rand() % 9;
    //    }
    //}
    //a2d.print();

    Matrix m{ rows,columns };
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < columns; x++)
        {
            m(y,x) = 1 + rand() % 9;
        }
    }
    m.print();

    m.deleteColumn(1);
    m.print();

    int* a = new int[3];
    for (int i = 0; i < 3; i++)
    {
        a[i] = i + 1;
            
    }
    m.addColumn(1, a);
    m.print();
    cout << endl;

    //int x = 10, y = 17;
    //sum(x, y);

    return 0;
 }
