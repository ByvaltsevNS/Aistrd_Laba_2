#pragma once
class Elem {
public:
	int value;
	Elem *next;
	Elem(int entered_value);
	~Elem();
};

class List {
private:
	Elem *Head;
	Elem *Tail;
	size_t size;
public:
	List();// онструктор без параметров
	List(int*, const int);// онструктор с параметрами
	~List();//ƒеструктор
	void push_back(int); // добавление в конец списка
	void push_front(int); // добавление в начало списка
	void pop_back(); // удаление последнего элемента
	void pop_front(); // удаление первого элемента
	void insert(int, size_t); // добавление элемента по индексу
	int at(size_t); // получение элемента по индексу
	void remove(size_t); // удаление элемента по индексу
	size_t get_size(); // получение размера списка
	void print_to_console(); // вывод элементов списка в консоль через разделитель, не использовать at
	void clear(); // удаление всех элементов списка
	void set(size_t, int); // замена элемента по индексу на передаваемый элемент
	bool isEmpty(); // проверка на пустоту списка
	void reverse(); // мен€ет пор€док элементов в списке
	Elem* get_Head();//ѕолучение указател€ на первый элемент списка
	Elem* get_Tail();//ѕолучение указател€ на последний элемент списка
};

bool is_equal(List*, List*);