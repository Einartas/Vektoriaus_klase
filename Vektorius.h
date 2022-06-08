#pragma once

template <class V>
class vektorius
{
private:

	V* duomenys;
	int dydis;
	int limitas;

public:

	typedef V* iterator;
	iterator begin();
	iterator end();

	unsigned int size() const;

	vektorius()
	{
		duomenys = new V[1];
		dydis = 0;
		limitas = 1;
	}

	void push(V data)
	{
		if (limitas == dydis)
		{
			V* temp = new V[limitas * 2];

			for (int i = 0; i < limitas; i++)
			{
				temp[i] = duomenys[i];
			}

			delete[] duomenys;
			limitas *= 2;
			duomenys = temp;
		}

		duomenys[dydis] = data;
		dydis++;
	}

	void pop()
	{
		dydis--;
	}

	void clear()
	{
		dydis = 0;
		limitas = 0;
		delete[] duomenys;
	}
};

template<class V>
typename vektorius<V>::iterator vektorius<V>::begin()
{
	return duomenys;
}

template<class V>
typename vektorius<V>::iterator vektorius<V>::end()
{
	return duomenys + dydis;
}

template<class V>
unsigned int vektorius<V>::size() const {
	return this->dydis;
}
