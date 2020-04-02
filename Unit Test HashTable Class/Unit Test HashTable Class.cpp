#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTable(2)/HashTable.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHashTableClass
{
	TEST_CLASS(UnitTestHashTableClass)
	{
	public:
		
		TEST_METHOD(TestIsKeyExist) // ���� ��������� ��������� �����
		{
			HashTable table;

			const int key = 14;
			const int value = 65;

			table.input(key, value);

			Assert::IsTrue(table.isKeyExist(14));

		}

		TEST_METHOD(TestAddOneElementInHashTable) // ���� ��������� ������ �������� � ���-�������;
		{
			HashTable table;

			const int key = 14;
			const int value = 65;

			table.input(key, value);
		}

		TEST_METHOD(TestAddOneElementInFullHashTable) // ���� ��������� ������ �������� � ����� ��� �������
		{
			const int table_size = 5;

			HashTable table(5);

			const int key = 144;
			const int value = 65;

			for (int i = 1; i < table_size; i++)
			{
				table.input(i * 2, i * 3);
			}

			table.input(key, value);
			

			Assert::AreEqual(value, table.getValue(key));
		}

		TEST_METHOD(TestAddOneElementInHashTableColissionProcessingChek) // ���� ��������� ������ �������� � ��� �������, �������� ������� �����
		{
			HashTable table;

			const int first_key = 11;
			const int second_key = 21;
			const int first_value = 150;
			const int second_value = 234;

			table.input(first_key, first_value);
			table.input(second_key, second_value);

			Assert::AreEqual(first_value, table.getValue(first_key));
			Assert::AreEqual(second_value, table.getValue(second_key));
		}

		TEST_METHOD(TestAddOneElementInHashTableWithExistKey) // ���� ��������� ������ �������� � ��� ������� � ��� �������� ������ 
		{
			HashTable table;

			const int key = 14;
			const int first_value = 43;
			const int second_value = 150;

			table.input(key, first_value);
			try
			{
				table.input(key, second_value);
			}
			catch (int a)
			{
				std::cerr << "Key is Exist, ERROR # " << a << '\n';
			}
		}
		
		TEST_METHOD(TestGetValueByKey) // ���� ��������� �������� �� ������
		{
			HashTable table;

			const int key = 14;
			const int value = 65;

			table.input(key, value);

			Assert::AreEqual(value, table.getValue(key));
		}

		TEST_METHOD(TestGetValueByKeyFromEmptyHashTable) // ���� ��������� �������� �� ������ � �������� ��� �������
		{
			HashTable table;

			const int key = 14;

			try
			{
				table.getValue(key);
			}
			catch (int a)
			{
				std::cerr << "Key does not exist, ERROR # " << a << '\n';
			}
		}

		TEST_METHOD(TestGetValueByExistKey) // ���� ��������� �������� �� ��������� ������
		{
			HashTable table;

			const int first_key = 14;
			const int second_key = 43;
			const int value = 150;

			table.input(first_key, value);

			try
			{
				table.getValue(second_key);
			}
			catch (int a)
			{
				std::cerr << "Key does not exist, ERROR # " << a << '\n';
			}
		}

		TEST_METHOD(TestModifyValueByKey) // ���� ����������� �������� �� ������
		{
			HashTable table;

			const int key = 14;
			const int first_value = 150;
			const int second_value = 510;

			table.input(key, first_value);
			table.modifyValue(key, second_value);

			Assert::AreEqual(second_value, table.getValue(key));
		}

		TEST_METHOD(TestModifyValueByExistKey) // ���� ����������� �������� �� ��������� ������
		{
			HashTable table;

			const int key = 14;
			const int false_key = 24;
			const int value = 140;
			const int false_value = 250;

			table.input(key, value);

			try
			{
				table.modifyValue(false_key, false_value);
			}
			catch (int a)
			{
				std::cerr << "Key does not exist, ERROR # " << a << '\n';
			}
		}

		TEST_METHOD(TestDeleteElementByKey) // ���� ��������� �������� �� ������
		{
			HashTable table;

			const int key = 14;
			const int value = 150;

			table.input(key, value);

			Assert::AreEqual(value, table.getValue(key));
			
			table.deleteValue(key);

			try
			{
				table.getValue(key);
			}
			catch (int a)
			{
				std::cerr << "Key does not exist, ERROR # " << a << '\n';
			}
		}

		TEST_METHOD(TestDeleteElementByKeyFromEmptyTable)
		{
			HashTable table;
			
			const int key = 14;

			try
			{
				table.deleteValue(key);
			}
			catch (int a)
			{
				std::cerr << "Key does not exist, ERROR # " << a << '\n';
			}
		}

		TEST_METHOD(TestDeleteElementByExistKey) // ���� ��������� �������� �� ��������� ������
		{
			HashTable table;

			const int key = 14;
			const int false_key = 42;
			const int value = 150;

			table.input(key, value);

			try
			{
				table.deleteValue(false_key);
			}
			catch (int a)
			{
				std::cerr << "Key does not exist, ERROR # " << a << '\n';
			}
		}
	}; 

	
}
