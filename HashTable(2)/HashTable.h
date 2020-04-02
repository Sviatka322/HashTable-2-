#pragma once

class HashTable
{
private:

	class Element
	{
	private:
		int m_key;
		int m_value;

	public:
		Element(int key = 0, int value = 0)
			: m_key(key), m_value(value) {}

		void setValue(int value)
		{
			m_value = value;
		}

		int getValue()
		{
			return m_value;
		}

		int getKey()
		{
			return m_key;
		}

		int setKey(int key)
		{
			m_key = key;
		}

	};

	int m_count_element;
	int m_size;
	Element* m_table;

	bool isFull()
	{
		if (m_count_element == m_size)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enlargeTable()
	{
		int t_size = m_size;

		Element* t_table = new Element[t_size];

		for (int i = 0; i < t_size; i++)
		{
			t_table[i] = m_table[i];
		}

		delete[] m_table;

		m_size += 10;

		m_table = new Element[m_size];

		for (int i = 0; i < t_size; i++)
		{
			m_table[i] = t_table[i];
		}

		delete[] t_table;
	}

	int hash1(int key)
	{
		return key % m_size;
	}

	int hash2(int key)
	{

		return 3 - (key % 3);
		//return (1 + ((key / m_size) % m_size - 2));
	}

	int mainHash(int key, int i)
	{
		return (hash1(key) + i * hash2(key)) % m_size;
	}

public:
	/*
	void showSize()
	{
		for (int i = 0; i < m_size; i++)
		{
			std::cout << i << " --> " << m_table[i].getValue() << '\n';
		}
	}
	*/

	HashTable(int size = 10)
		: m_count_element(0), m_size(size), m_table(new Element[m_size]) {}

	bool isKeyExist(int key)
	{
		int h_k1 = hash1(key);

		if (m_table[h_k1].getKey() == key)
		{
			return true;
		}
		else
		{
			for (int i = 0; i < m_size; i++)
			{
				if (m_table[i].getKey() == key)
				{
					return true;
				}
			}

			return false;
		}
	}

	void input(int key, int value)
	{
		if (!isKeyExist(key))
		{
			if (isFull())
			{
				enlargeTable();
			}

			if (m_table[hash1(key)].getKey() != 0)
			{
				int h_k1 = hash1(key);
				int h_k2 = hash2(key);

				for (int i = 0; i < m_size - 1; i++)
				{
					int main_h_k = mainHash(key, i);

					if (m_table[main_h_k].getKey() == 0)
					{
						m_table[main_h_k] = Element(key, value);
						m_count_element++;
						break;
					}
					else if (isFull())
					{
						enlargeTable();
					}
				}
			}
			else
			{
				m_table[hash1(key)] = Element(key, value);
				m_count_element++;
			}
		}
		else
		{
			throw 100; // Êëþ÷ âæå ³ñíóº!
		}
	}

	int getValue(int key)
	{
		if (isKeyExist(key))
		{
			if (m_table[hash1(key)].getKey() == key)
			{
				return m_table[hash1(key)].getValue();
			}
			else
			{
				int h_k1 = hash1(key);
				int h_k2 = hash2(key);

				for (int i = 0; i < m_size - 1; i++)
				{
					int main_h_k = mainHash(key, i);

					if (m_table[main_h_k].getKey() == key)
					{
						return m_table[main_h_k].getValue();
					}

				}
			}
		}
		else
		{
			throw - 100; // Êëþ÷ íå ³ñíóº!
		}
	}

	void modifyValue(int key, int modify_value)
	{
		if (isKeyExist(key))
		{
			if (m_table[hash1(key)].getKey() == key)
			{
				m_table[hash1(key)].setValue(modify_value);
			}
			else
			{
				int h_k1 = hash1(key);
				int h_k2 = hash2(key);

				for (int i = 0; i < m_size - 1; i++)
				{
					int main_h_k = mainHash(key, i);

					if (m_table[main_h_k].getKey() == key)
					{
						m_table[main_h_k].setValue(modify_value);
					}

				}
			}
		}
		else
		{
			throw - 100; // Êëþ÷ íå ³ñíóº!
		}
	}

	void deleteValue(int key)
	{
		if (isKeyExist(key))
		{
			if (m_table[hash1(key)].getKey() == key)
			{
				m_table[hash1(key)] = Element();
			}
			else
			{
				int h_k1 = hash1(key);
				int h_k2 = hash2(key);

				for (int i = 0; i < m_size - 1; i++)
				{
					int main_h_k = mainHash(key, i);

					if (m_table[main_h_k].getKey() == key)
					{
						m_table[main_h_k] = Element();
					}

				}
			}
		}
		else
		{
			throw - 100; // Êëþ÷ íå ³ñíóº!
		}
	}

	~HashTable()
	{
		delete[] m_table;
	}
};
