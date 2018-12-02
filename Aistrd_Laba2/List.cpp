#include "pch.h"
#include "List.h"
#include <iostream>
#include <stdexcept>

#define start_index 0

using namespace std;

Elem::Elem(int entered_value): value(entered_value), next(nullptr) {}
Elem::~Elem() {}

List::List(): Head (nullptr), Tail (nullptr), size(0) {}
//������ ��� ������������
List::List(int *arr, const int arr_size) {//����������� � �����������
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

//������ + �����
void List::push_back(int value) {// ���������� � ����� ������
	Elem *temp = new Elem(value);
	if (isEmpty()) {//���� ������ ����
		Head = temp;
		Tail = Head;
	}
	else {//���� ������ �� ����
		Tail->next = temp;
		Tail = temp;
	}
	size++;
}

//������ + �����
void List::push_front(int value) {//���������� � ������ ������
	Elem *temp = new Elem(value);
	if (isEmpty()) {//���� ������ ����
		Tail = temp;
	}
	temp->next = Head;
	Head = temp;
	size++;
}

//������ + �����
void List::pop_back() {//�������� ���������� ��������
	if (isEmpty()) {//���� ������ ����
		cout << "List is empty!";
	}
	else {
		if (Head == Tail) {//������ �� ������ ��������
			delete Head;
			Head = Tail = nullptr;
			size = 0;
		}
		else {//��������� ������
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

//������ + �����
bool List::isEmpty() {//�������� �� �������
	if (Head == nullptr) {
		return true;
	}
	return false;
}

//������ + �����
void List::pop_front() {// �������� ������� ��������
	if (isEmpty()) {//���� ������ ����
		cout << "List is empty!";
	}
	else {
		if (Head == Tail) {//������ �� ������ ��������
			delete Head;
			Head = Tail = nullptr;
			size = 0;
		}
		else {//��������� ������
			Elem *temp = Head;
			Head = Head->next;
			delete temp;
			size--;
		}
	}
}

//������ + �����
void List::insert(int value, size_t number) {// ���������� �������� �� �������
	if (number >= size) {//����� ������ ���������� ��������� ������
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {//������� � ����� ������� ����
		Elem *added = new Elem(value);
		if (number == start_index) {//���� ���������� � ������
			added->next = Head;
			Head = added;
		}
		else {
			Elem *temp = Head;//��������� ������
			for (size_t i = 0; i < number - 1; i++) {
				temp = temp->next;
			}
			added->next = temp->next;
			temp->next = added;
		}
		size++;
	}
}

//������ + �����
int List::at(size_t number) {// ��������� �������� �� �������
	if (number >= size) {//����� ������ ���������� ��������� ������
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {//��������� ������
		Elem *temp = Head;
		for (size_t i = 0; i < number; i++) {
			temp = temp->next;
		}
		return temp->value;
	}
}

//������ + �����
void List::remove(size_t number) { // �������� �������� �� �������
	if (number >= size) {//����� ������ ���������� ��������� ������
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {
		Elem *temp = Head;
		if (number == start_index) {//���� �������� ������� ��������
			if (Tail == Head) {//���� � ������ 1 �������
				Tail = Head = nullptr;
			}
			else {//���� � ������ ������ 1�� ��������
				Head = temp->next;
			}
			delete temp;
		} 
		else {
			for (size_t i = 0; i < number - 1; i++) {
				temp = temp->next;
			}
			if (temp->next == Tail) {//���� �������� ���������� ��������
				Tail = temp;
				delete temp->next;
				Tail->next = nullptr;
			}
			else {//� ��������� �������
				Elem *removable = temp->next;
				temp->next = temp->next->next;
				delete removable;
			}
		}
		size--;
	}
}

//������, ����� �� �����
size_t List::get_size() {// ��������� ������� ������
	return size;
}

//������, ����� �� �����
void List::print_to_console() { // ����� ��������� ������ � ������� ����� �����������, �� ������������ at
	if (isEmpty()) {//������ ����
		cout << "List is empty!";
	}
	else {
		Elem *temp = Head;
		cout << "List: ";
		while (temp != Tail) {
			cout << temp->value << " , ";
			temp = temp->next;
		}
		cout << temp->value << ";" << endl;//����� ���������� ��������
	}
}

//������ + �����
void List::clear() { // �������� ���� ��������� ������
	if (isEmpty()) {//���� ������ ����
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

//������ + �����
void List::set(size_t number, int new_value) { // ������ �������� �� ������� �� ������������ �������
	if (number >= size) {//����� ������ ���������� ��������� ������
		throw out_of_range("The number entered is greater than the count of items!");
	}
	else {//������� � ����� ������� ����
		Elem *temp = Head;//��������� ������
		for (size_t i = 0; i < number; i++) {
			temp = temp->next;
		}
		temp->value = new_value;
	}
}

//������ + �����
void List::reverse() { // ������ ������� ��������� � ������
	if (isEmpty()) {//���� ������ ����
		cout << "List is empty!";
	}
	else {
		if (Head != Tail) { // ���� � ������ ������ ������ ��������
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

//������, ����� �� �����
Elem* List::get_Head() {//��������� ��������� �� ������ ������� ������
	return Head;
}

//������, ����� �� �����
Elem* List::get_Tail() {//��������� ��������� �� ��������� ������� ������
	return Tail;
}

//������ + �����
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