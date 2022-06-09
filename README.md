# Vektoriaus_klase

1000 įrašų:
Vector nuskaitymas: 0.001s, rūšiavimas į dvi grupes: 0s, rūšiavimas sort: 0s
Mano nuskaitymas: 0.001s, rūšiavimas į dvi grupes: 0s, rūšiavimas sort: 0s

10000 įrašų:
Vector nuskaitymas: 0.014s, rūšiavimas į dvi grupes: 0.001s, rūšiavimas sort: 0.002s
Mano nuskaitymas: 0.018s, rūšiavimas į dvi grupes: 0.002s, rūšiavimas sort: 0.003s

100000 įrašų:
Vector nuskaitymas: 0.133s, rūšiavimas į dvi grupes: 0.032s, rūšiavimas sort: 0.022s
Mano nuskaitymas: 0.182s, rūšiavimas į dvi grupes: 0.021s, rūšiavimas sort: 0.034s

1000000 įrašų:
Vector nuskaitymas: 1.291s, rūšiavimas į dvi grupes: 0.225s, rūšiavimas sort: 0.266s
Mano nuskaitymas: 1.667s, rūšiavimas į dvi grupes: 0.254s, rūšiavimas sort: 0.353s

10000000 įrašų:
Vector nuskaitymas: 21.375s, rūšiavimas į dvi grupes: 7.016s, rūšiavimas sort: 2.769s
Mano nuskaitymas: 23.009s, rūšiavimas į dvi grupes: 3.319s, rūšiavimas sort: 2.974s

Skaičių pildymas:

10000 skaičių:
Vector:  0s
Mano:  0s

100000 skaičių:
Vector:  0s
Mano:  0s

1000000 skaičių:
Vector:  0.004s
Mano:  0.004s

10000000 skaičių:
Vector:  0.042s
Mano:  0.055s

100000000 skaičių:
Vector:  0.491s
Mano:  0.548s

Push_back() realizacija:

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

Pop_back() realizacija:

	void pop()
	{
		dydis--;
	}

Size() realizacija:

template<class V>
unsigned int vektorius<V>::size() const {
	return this->dydis;
}

Clear() realizacija:

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

Begin() realizacija:

template<class V>
typename vektorius<V>::iterator vektorius<V>::begin() 
{
	return duomenys;
}

End() realizacija:

template<class V>
typename vektorius<V>::iterator vektorius<V>::end() 
{
	return duomenys + dydis;
}
	
Operatoriaus [] realizacija:
	
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

Mano vektoriaus perskirtstymas su 100000000 skaičių įvyksta 27 kartus.
