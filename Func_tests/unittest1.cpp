#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\\Users\\byval\\source\\repos\\Aistrd_Laba2\\Aistrd_Laba2\\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Func_tests
{		

	//�������� ����� ��� pop_front
	TEST_CLASS(List_Tests)
	{
	public:
		List * lst;

		//�������� ������ ����� ����������� ������� �����
		TEST_METHOD_INITIALIZE(setUp)
		{
			lst = new List();
		}
		//�������� ������ ����� ���������� ������� �����
		TEST_METHOD_CLEANUP(cleanUp) 
		{
			delete lst;
		}

		//��������� ���������� �������
		TEST_METHOD(is_equal_eq_lists_test)
		{
			const int size = 6;
			int arr[size] = { 0, 1, 2, 3, 4, 5};
			List *list_1 = new List(arr, size);
			List *list_2 = new List(arr, size);
			Assert::IsTrue(is_equal(list_1, list_2));
			delete list_1;
			delete list_2;
		}
		//��������� �������, ������� ��������� ��������
		TEST_METHOD(is_equal_not_eq_lists_test)
		{
			const int size_1 = 5;
			int arr_1[size_1] = { 0, 1, 3, 3, 4};
			List *list_1 = new List(arr_1, size_1);
			const int size_2 = 5;
			int arr_2[size_2] = { 0, 1, 2, 3, 4 };
			List *list_2 = new List(arr_2, size_2);
			Assert::IsFalse(is_equal(list_1, list_2));
			delete list_1;
			delete list_2;
		}
		//��������� �������, ������� ��������� �������
		TEST_METHOD(is_equal_diff_sizes_lists_test)
		{
			const int size_1 = 6;
			int arr_1[size_1] = { 0, 1, 2, 3, 4, 5 };
			List *list_1 = new List(arr_1, size_1);
			const int size_2 = 5;
			int arr_2[size_2] = { 0, 1, 2, 3, 4};
			List *list_2 = new List(arr_2, size_2);
			Assert::IsFalse(is_equal(list_1, list_2));
			delete list_1;
			delete list_2;
		}

		//�������� �� ������� ������� ������
		TEST_METHOD(isEmpty_empty_list_test)
		{
			Assert::IsTrue(lst->isEmpty());
		}
		//�������� �� ������� �� ������� ������
		TEST_METHOD(isEmpty_not_empty_list_test)
		{
			int i = 1;
			lst->push_front(i);
			Assert::IsFalse(lst->isEmpty());
		}

		//�������� ���������� �������� � ����� ������
		TEST_METHOD(push_back_test) {
			const int size_1 = 3;
			int arr_1[size_1] = { 0, 1, 2 };
			List *list_1 = new List(arr_1, size_1);
			const int size_2 = 2;
			int arr_2[size_2] = { 0, 1};
			List *list_2 = new List(arr_2, size_2);
			int added_value = 2;
			Elem *tail = list_2->get_Tail();
			list_2->push_back(added_value);
			Assert::IsTrue(is_equal(list_1, list_2) && tail != list_2->get_Tail());
			delete list_1;
			delete list_2;
		}
		//�������� ���������� �������� � ����� ������ � ������ ������� ������ 
		TEST_METHOD(push_back_in_empty_list_test) {
			const int size = 1;
			int arr[size] = {0};
			List *list_for_comp = new List(arr, size);
			Elem *head = lst->get_Head();
			Elem *tail = lst->get_Tail();
			int added_value = 0;
			lst->push_back(added_value);
			Assert::IsTrue(is_equal(lst, list_for_comp) && head != lst->get_Head() && tail != lst->get_Tail());
			delete list_for_comp;
		}

		//�������� ���������� �������� � ������ ������ 
		TEST_METHOD(push_front_test) { 
			const int size_1 = 3;
			int arr_1[size_1] = { 0, 1, 2 };
			List *list_1 = new List(arr_1, size_1);
			const int size_2 = 2;
			int arr_2[size_2] = { 1, 2 };
			List *list_2 = new List(arr_2, size_2);
			Elem *head = list_2->get_Head();
			int added_value = 0;
			list_2->push_front(added_value);
			Assert::IsTrue(is_equal(list_1, list_2) && head != list_2->get_Head());
			delete list_1;
			delete list_2;
		}
		//�������� ���������� �������� � ������ ������� ������ 
		TEST_METHOD(push_front_in_empty_list_test) {
			const int size = 1;
			int arr[size] = { 0 };
			List *list_for_comp = new List(arr, size);
			Elem *head = lst->get_Head();
			Elem *tail = lst->get_Tail();
			int added_value = 0;
			lst->push_front(added_value);
			Assert::IsTrue(is_equal(lst, list_for_comp) && head != lst->get_Head() && tail != lst->get_Tail());
			delete list_for_comp;
		}
		
		//�������� �������� �������� � ����� ������
		TEST_METHOD(pop_back_test)
		{
			const int size = 3;
			int arr[size] = { 0, 1, 2 };
			List *list_for_comp = new List(arr, size);
			for (int i = 0; i < size - 1; i++) {
				lst->push_back(arr[i]);
			}
			Elem *tail = list_for_comp->get_Tail();
			list_for_comp->pop_back();
			Assert::IsTrue(is_equal(list_for_comp, lst) && tail != list_for_comp->get_Tail());
			delete list_for_comp;
		}
		//�������� �������� �������� � ����� ������ �� ������ ��������
		TEST_METHOD(pop_back_list_with_1_element_test)
		{
			const int size = 1;
			int arr[size] = {0};
			List *list_for_comp = new List(arr, size);
			Elem *tail = list_for_comp->get_Tail();
			Elem *head = list_for_comp->get_Head();
			list_for_comp->pop_back();
			Assert::IsTrue(is_equal(list_for_comp, lst) && tail != list_for_comp->get_Tail() && head != list_for_comp->get_Head());
			delete list_for_comp;
		}

		//�������� �������� �������� � ������ ������
		TEST_METHOD(pop_front_test) {
			const int size = 3;
			int arr[size] = { 0, 1, 2 };
			List *list_for_comp = new List(arr, size);
			for (int i = size - 1; i > 0; i--) {
				lst->push_front(arr[i]);
			}
			Elem *head = list_for_comp->get_Head();
			list_for_comp->pop_front();
			Assert::IsTrue(is_equal(list_for_comp, lst) && head != list_for_comp->get_Head());
			delete list_for_comp;
		}
		//�������� �������� �������� � ������ ������ �� ������ ��������
		TEST_METHOD(pop_front_list_with_1_element_test)
		{
			const int size = 1;
			int arr[size] = { 0 };
			List *list_for_comp = new List(arr, size);
			Elem *tail = list_for_comp->get_Tail();
			Elem *head = list_for_comp->get_Head();
			list_for_comp->pop_front();
			Assert::IsTrue(is_equal(list_for_comp, lst) && tail != list_for_comp->get_Tail() && head != list_for_comp->get_Head());
			delete list_for_comp;
		}

		//�������� ������� �������� ���� ��������� �������
		TEST_METHOD(clean_test){
			const int size = 3;
			int arr[size] = { 0, 1, 2 };
			List *list_for_comp = new List(arr, size);
			list_for_comp->clear();
			Assert::IsTrue(is_equal(lst, list_for_comp) && lst->get_Head() == list_for_comp->get_Head() && lst->get_Tail() == list_for_comp->get_Tail());
		}
	
		//�������� ������� ����� ������� ��������� � ������
		TEST_METHOD(reverse_test) {
			const int size_1 = 5;
			int arr_1[size_1] = { 0, 1, 2, 3, 4 };
			List *list_1 = new List(arr_1, size_1);
			const int size_2 = 5;
			int arr_2[size_2] = { 4, 3, 2, 1, 0 };
			List *list_2 = new List(arr_2, size_2);
			list_2->reverse();
			Assert::IsTrue(is_equal(list_1, list_2));
			delete list_1;
			delete list_2;
		}

		//�������� ������� ���������� �������� �� ������� � ����� ������
		TEST_METHOD(insert_test) {
			lst->push_back(1);
			lst->push_back(1);
			lst->push_back(1);
			lst->insert(2, 1);
			int size = 4;
			int arr[4] = { 1, 2, 1, 1 };
			List *list_for_comp = new List(arr, size);
			Assert::IsTrue(is_equal(lst, list_for_comp));
			delete list_for_comp;
		}
		//�������� ������� ���������� �������� �� ������� � ������ ������
		TEST_METHOD(insert_in_first_place_test) {
			lst->push_back(1);
			lst->push_back(1);
			lst->push_back(1);
			Elem *head = lst->get_Head();
			lst->insert(2, 0);
			int size = 4;
			int arr[4] = { 2, 1, 1, 1 };
			List *list_for_comp = new List(arr, size);
			Assert::IsTrue(is_equal(lst, list_for_comp) && head != lst->get_Head());
			delete list_for_comp;
		}
		//�������� ������� ���������� �������� �� ������� � ������ ������������� �������
		TEST_METHOD(insert_incorrect_index_test) {
			try {
				lst->insert(1, -1);
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("The number entered is greater than the count of items!", exc.what());
			}
		}
		//�������� ������� ��������� �������� �� ������� � ������ ����� ����������� �������
		TEST_METHOD(at_correct_index_test) {
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			Assert::AreEqual(lst->at(1), 2);
		}
		//�������� ������� ��������� �������� �� ������� � ������ ����� ������������� �������
		TEST_METHOD(at_incorrect_index_test) {
			try {
				lst->at(-1);
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("The number entered is greater than the count of items!", exc.what());
			}
		}
	
		//�������� ������� ������ �������� �� �������
		TEST_METHOD(set_test) {
			lst->push_back(1);
			lst->push_back(1);
			lst->push_back(1);
			int new_value = 2;
			lst->set(1, new_value);
			Assert::AreEqual(new_value, lst->at(1));
		}
		//�������� ������� ������ �������� �� ������� � ������ ����� ������������� �������
		TEST_METHOD(set_incorrect_index_test) {
			try {
				lst->set(-1, 1);
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("The number entered is greater than the count of items!", exc.what());
			}
		}

		//�������� ������� �������� �������� �� ������� � ����� ������
		TEST_METHOD(remove_test) {
			size_t index = 2;
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(4);
			int index_value = lst->at(index);
			size_t size = lst->get_size();
			lst->remove(index);
			Assert::IsTrue(size != lst->get_size() && lst->at(index) != index_value);
		}
		//�������� ������� �������� �������� �� ������� � ������ ������ �� ������ ��������
		TEST_METHOD(remove_list_with_one_elem) {
			lst->push_back(1);
			lst->remove(0);
			Assert::IsTrue(lst->get_size() == 0 && lst->get_Head() == lst->get_Tail() && lst->get_Tail()  == nullptr);
		}
		//�������� ������� �������� �������� �� ������� � ������ �������� ������� ��������
		TEST_METHOD(remove_first_elem) {
			int first_value = 1;
			lst->push_back(first_value);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(4);
			Elem  *head = lst->get_Head();
			size_t size = lst->get_size();
			lst->remove(0);
			Assert::IsTrue(size != lst->get_size() && head != lst->get_Head() && lst->at(0) != first_value);
		}
		//�������� ������� �������� �������� �� ������� � ������ �������� ���������� ��������
		TEST_METHOD(remove_last_elem) {
			int last_value = 1;
			lst->push_back(1);
			lst->push_back(2);
			lst->push_back(3);
			lst->push_back(last_value);
			Elem  *tail = lst->get_Tail();
			size_t size = lst->get_size();
			lst->remove(lst->get_size() - 1);
			Assert::IsTrue(size != lst->get_size() && tail != lst->get_Tail() && lst->at(lst->get_size() - 1) != last_value);
		}
		//�������� ������� �������� �������� �� ������� � ������ ������������� �������
		TEST_METHOD(remove_incorrect_index_test) {
			try {
				lst->remove(-1);
			}
			catch (std::out_of_range exc) {
				Assert::AreEqual("The number entered is greater than the count of items!", exc.what());
			}
		}
	};
}