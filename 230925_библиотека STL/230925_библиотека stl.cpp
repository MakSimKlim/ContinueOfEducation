// 230925_библиотека stl
//
// 4 основных компонента STL:
// Контейнер - блок для хранения данных, упрпавления ими и размещения
// Алгоритм - функция для работы с данными, хранящимися в контейнере
// Итератор - спец.указатель для перемещения по данным конкретного контейнера
// Функторы - механизм инкапсуляции функций в конкретном объекте для использования
// другими компонентами
// 
// Также есть:
// Аллокатор - распределитель памяти
// Предикат - функция нестандартного типа, используемая в контейнере
// Бывает унарный и бинарный, возвращает логическое значение
//
// =================================================================================
// 
// Умные (интеллектуальные ) указатели
// Выделение ресурса - это инициализация.
// 
// Ситуация, когда файлы не закрытись и не удаляется динамический массив
// после того как вызвалось exit().
// 
// int* a = new int[20];
// FILE* f2 = fopen("example2.txt", "w");
// FILE* f = fopen("example.txt", "w");
// if(f)
// {
// cout<<"Error";
// exit(0);
// }
// f.close(); // метод может быть не вызван
// f2.close();// метод может быть не вызван
// delete[] a;// метод может быть не вызван
// 
// Решением этой проблемы:
// 1). создать класс
// 2). в конструкторе класса выделять ресурсы(открывать файл)
// 3). в деструкторе класса освобождать ресурсы(закрывать файл)
// 4). для работы с ресурсами создавать экземпляр класса
//
// Умные указатели (4шт)
// Владеет указателем и отвечает за его удаление.
// Доступ к указателю осуществляется операторами * и ->
// 1) auto_ptr - ни в коем случае не используем его
// 2) unique_ptr - переопределяет указатели (не дает скопировать указатель)
//  make_unique - функция возвращает уникальный указатель на этот объект, используется более грамотно вместо new (конструкторы и копирования и перемещения удалены)
// 3) shared_ptr - с счётчиком, увеличивая (в конструкторе) и уменьшая (в деструкторе) на 1, хранит счётчик количества указателей на один и тот же объект, когда он достигает 0
//  make_shared, use_count - функции
// 4) weak_ptr
// 

#include <iostream>
#include <fstream>
using namespace std;

class OpenFile
{
	FILE* f;
public:
	OpenFile(char* filename, char* filemode)
	{
		fopen_s(&f, filename, filemode);
		if (!f)
		{
			cout << "Couldn't open " << filename << endl;
			exit(1);
		}

	}
	~OpenFile()
	{
		fclose(f);
	}

	FILE* getFilePtr() { return f; }

};

class LargeObject
{
	static int counter;
	int num;
public:
	LargeObject()
		:num{ ++counter }
	{}
	void DoSomething() const
	{
		cout << "Doing something\n";
	}

	void GetNum()
	{
		return num;
	}
	
};

int LargeObject::counter;

void ProcessLargeObject(const LargeObject& lo)
{
	lo.DoSomething();
}

void UniqPtrs()
{
	//OpenFile myFile(const_cast<char*>("test.txt"), const_cast<char*>("w"));

	// LargeObject* lo = &x или new LargeObject()
	std::unique_ptr<LargeObject> oLarge(new LargeObject());
	oLarge->DoSomething();
	ProcessLargeObject(*oLarge);

	oLarge.reset();// досрочно освобождает память
	//вот так лучше не делать, чисто для примера
	LargeObject* lo = oLarge.get();// .get() - прямой доступ к указателю

	//обертка для слова new, которая существует для лучшей читаемости
	// предпочтительнее использовать её
	unique_ptr<LargeObject> otherLarge = make_unique<LargeObject>();
	otherLarge.reset();


	//единственный способ получить данные из одного уникального указателя в другой
	unique_ptr<LargeObject> copy_oLarge;
	cout << otherLarge << endl;
	// перемещает адрес (содержимое) из oLarge в otherLarge
	copy_oLarge = move(otherLarge);
	cout << copy_oLarge << " " << otherLarge << endl;


}

void SharedPtr()
{
	shared_ptr<LargeObject> largeP(new LargeObject());
	shared_ptr<LargeObject> largeP2 = make_shared<LargeObject>();

	shared_ptr<LargeObject> largeP3;
	largeP3 = largeP2;

	shared_ptr<LargeObject> largeP4 = largeP3;

	cout << largeP->GetNum() << endl;
	cout << largeP2->GetNum() << endl;
	cout << largeP3->GetNum() << endl;
	cout << largeP2.use_count() << endl;

	LargeObject sharedLo;
	shared_ptr<LargeObject> largeP5 = make_shared<LargeObject>(sharedLo);
	shared_ptr<LargeObject> largeP6 = make_shared<LargeObject>(sharedLo);
	shared_ptr<LargeObject> largeP7 = make_shared<LargeObject>(sharedLo);
	cout << largeP5.use_count() << endl;
	cout << largeP6.use_count() << endl;
	cout << largeP7.use_count() << endl;
	cout << largeP5->GetNum() << endl;
	cout << largeP6->GetNum() << endl;
	cout << largeP7->GetNum() << endl;
	cout << sharedLo.GetNum() << endl;

}

int main()
{
	shared_ptr<LargeObject> sp1 = make_shared<LargeObject>();
	shared_ptr<LargeObject> sp2 = sp1;
	shared_ptr<LargeObject> sp3 = sp1;
	cout << sp3.use_count() << endl;

	weak_ptr<LargeObject>wp = sp1;



	return 0;
}

