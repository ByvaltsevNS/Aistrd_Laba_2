#include "pch.h"
#include "List.h"
#include <iostream>
#include <stdexcept>

#define start_index 0

using namespace std;

Elem::Elem(int entered_value): value(entered_value), next(nullptr) {}
Elem::~Elem() {}

List::List(): Head (nullptr), Tail (nullptr), size(0) {}
//Только для тестирования
List::List(int *arr, const int arr_size) {//Конструктор с параметрами
	Head = new Elem(arr[0]);
	Tail = Head;
	size = 1;
	Elem *for_create = Head;
	for (int i = 1; i < arr_size; i++) {
		for_create->next = new Elem(arr[i]);
		Tail = for_create->next;
		for_create = for_create->next;
		size++;
	}
}
List::~List() {
	clear();
}

//Готова + тесты
void List::push_back(int value) {// добавление в конец списка
	Elem *temp = new Elem(value);
	if (isEmpty()) {//если список пуст
		Head = temp;
		Tail = Head;
	}
	else {//если список не пуст
		Tail->next = temp;
		Tail = temp;
	}
	size++;
}

//Готова + тесты
void List::push_front(int value) {//добавление в начало списка
	Elem *temp = new Elem(value);
	if (isEmpty()) {//если список пуст
		Tail = temp;
	}
	temp->next = Head;
	Head = temp;
	size++;
}

//Готова + тесты
void List::pop_back() {//удаление последнего элемента
	if (isEmpty()) {//если список пуст
		cout << "List is empty!";
	}
	else {
		if (Head == Tail) {//список из одного элемента
			delete Head;
			Head = Tail = nullptr;
			size = 0;
		}
		else {//остальные случаи
			Elem *temp = Head;
			while (temp->next != Tail) {
				temp = temp->next;
			}
			Tail = temp;
			Tail->next = nullptr;
			delete  temp->next;
			size--;
		}
	}
}

//Готова + тесты
bool List::isEmpty() {//Проверка на пустоту
	if (Head == nullptr) {
		return true;
	}
	return false;
}

//Готова + тесты
void List::pop_front() {// удаление первого элемента
	if (isEmpty()) {//если список пуст
		cout << "List is empty!";
	}
	else {
		if (Head == Tail) {//список из одного элемента
			delete Head;
			Head = Tail = nullptr;
			size = 0;
		}
		else {//остальные случаи
			Elem *temp = Head;
			Head = Head->next;
			delete temp;
			size--;
		}
	}
}

//Готова + тесты
void List::insert(int value, size_t number) {// добавление элемента по индексу
	if (number >= size) {//Номер больше количества элементов списка
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {//Элемент с таким номером есть
		Elem *added = new Elem(value);
		if (number == start_index) {//Если добавление в начало
			added->next = Head;
			Head = added;
		}
		else {
			Elem *temp = Head;//Остальные случаи
			for (size_t i = 0; i < number - 1; i++) {
				temp = temp->next;
			}
			added->next = temp->next;
			temp->next = added;
		}
		size++;
	}
}

//Готова + тесты
int List::at(size_t number) {// получение элемента по индексу
	if (number >= size) {//Номер больше количества элементов списка
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {//Остальные случаи
		Elem *temp = Head;
		for (size_t i = 0; i < number; i++) {
			temp = temp->next;
		}
		return temp->value;
	}
}

//Готова + тесты
void List::remove(size_t number) { // удаление элемента по индексу
	if (number >= size) {//Номер больше количества элементов списка
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {
		Elem *temp = Head;
		if (number == start_index) {//Если удаление первого элемента
			if (Tail == Head) {//Если в списке 1 элемент
				Tail = Head = nullptr;
			}
			else {//Если в списке больше 1го элемента
				Head = temp->next;
			}
			delete temp;
		} 
		else {
			for (size_t i = 0; i < number - 1; i++) {
				temp = temp->next;
			}
			if (temp->next == Tail) {//Если удаление последнего элемента
				Tail = temp;
				delete temp->next;
				Tail->next = nullptr;
			}
			else {//В остальных случаях
				Elem *removable = temp->next;
				temp->next = temp->next->next;
				delete removable;
			}
		}
		size--;
	}
}

//Готова, тесты не нужны
size_t List::get_size() {// получение размера списка
	return size;
}

//Готова, тесты не нужны
void List::print_to_console() { // вывод элементов списка в консоль через разделитель, не использовать at
	if (isEmpty()) {//Список пуст
		cout << "List is empty!";
	}
	else {
		Elem *temp = Head;
		cout << "List: ";
		while (temp != Tail) {
			cout << temp->value << " , ";
			temp = temp->next;
		}
		cout << temp->value << ";" << endl;//Вывод последнего элемента
	}
}

//Готова + тесты
void List::clear() { // удаление всех элементов списка
	if (isEmpty()) {//если список пуст
		cout << "List is already empty!";
	}
	else {
		Elem *temp;
		while (Head != nullptr) {
			temp = Head->next;
			delete Head;
			Head = temp;
		}
		size = 0;
		Tail = nullptr;
	}
}

//Готова + тесты
void List::set(size_t number, int new_value) { // замена элемента по индексу на передаваемый элемент
	if (number >= size) {//Номер больше количества элементов списка
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {//Элемент с таким номером есть
		Elem *temp = Head;//Остальные случаи
		for (size_t i = 0; i < number; i++) {
			temp = temp->next;
		}
		temp->value = new_value;
	}
}

//Готова + тесты
void List::reverse() { // меняет порядок элементов в списке
	if (isEmpty()) {//если список пуст
		cout << "List is empty!";
	}
	else {
		if (Head != Tail) { // Если в списке больше одного элемента
			int start_size = size;
			for (int i = start_size - 2; i >= 0; i--) {
				push_back(at((size_t) i));
			}
			for (int i = 0; i < start_size - 1; i++) {
				pop_front();
			}
		}
	}
}

//Готова, тесты не нужны
Elem* List::get_Head() {//Получение указателя на первый элемент списка
	return Head;
}

//Готова, тесты не нужны
Elem* List::get_Tail() {//Получение указателя на последний элемент списка
	return Tail;
}

//Готова + тесты
bool is_equal(List* list_1, List* list_2) {
	if (list_1->get_size() != list_2->get_size()) {
		return false;
	}
	for (size_t i = 0; i < list_1->get_size(); i++) {
		if (list_1->at(i) != list_2->at(i))
			return false;
	}
	return true;
}