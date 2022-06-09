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

	V& operator[] (unsigned int index);
	const V& operator[] (unsigned int index) const;

	unsigned int size() const;

	vektorius(unsigned int dydis) {};
	vektorius(unsigned int dydis, const V& init) {};
	vektorius(const std::initializer_list<V>& list) {};
	vektorius()
	{
		duomenys = new V[1];
		dydis = 0;
		limitas = 1;
	}

	~vektorius();

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

	void clear();
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

template<class V>
void vektorius<V>::clear()
{
	dydis = 0;
	limitas = 0;
}

template<class V>
vektorius<V>::~vektorius<V>()
{
	clear();
}

template<class V>
const V& vektorius<V>::operator[](unsigned int index) const
{
	if (index < 0 || index >= dydis)
		throw "out of bounds element access";
	return duomenys[index];
}

template<class V>
V& vektorius<V>::operator[](unsigned int index) 
{
	if (index < 0 || index >= dydis)
		throw "out of bounds element access";
	return duomenys[index];
}