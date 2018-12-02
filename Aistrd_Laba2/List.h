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
	List();//����������� ��� ����������
	List(int*, const int);//����������� � �����������
	~List();//����������
	void push_back(int); // ���������� � ����� ������
	void push_front(int); // ���������� � ������ ������
	void pop_back(); // �������� ���������� ��������
	void pop_front(); // �������� ������� ��������
	void insert(int, size_t); // ���������� �������� �� �������
	int at(size_t); // ��������� �������� �� �������
	void remove(size_t); // �������� �������� �� �������
	size_t get_size(); // ��������� ������� ������
	void print_to_console(); // ����� ��������� ������ � ������� ����� �����������, �� ������������ at
	void clear(); // �������� ���� ��������� ������
	void set(size_t, int); // ������ �������� �� ������� �� ������������ �������
	bool isEmpty(); // �������� �� ������� ������
	void reverse(); // ������ ������� ��������� � ������
	Elem* get_Head();//��������� ��������� �� ������ ������� ������
	Elem* get_Tail();//��������� ��������� �� ��������� ������� ������
};

bool is_equal(List*, List*);