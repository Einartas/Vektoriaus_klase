# Vektoriaus_klase

1000 įrašų:
Vector nuskaitymas: 0.001s, rūšiavimas į dvi grupes: 0s, rūšiavimas sort: 0s
Mano nuskaitymas: 0.001s, rūšiavimas į dvi grupes: 0s, rūšiavimas sort: 0s

10000 įrašų:
Vector nuskaitymas: 0.014s, rūšiavimas į dvi grupes: 0.001s, rūšiavimas sort: 0.002s
Mano nuskaitymas: 0.017s, rūšiavimas į dvi grupes: 0.001s, rūšiavimas sort: 0.002s

100000 įrašų:
Vector nuskaitymas: 0.133s, rūšiavimas į dvi grupes: 0.032s, rūšiavimas sort: 0.022s
Mano nuskaitymas: 0.183s, rūšiavimas į dvi grupes: 0.014s, rūšiavimas sort: 0.027s

1000000 įrašų:
Vector nuskaitymas: 1.291s, rūšiavimas į dvi grupes: 0.225s, rūšiavimas sort: 0.266s
Mano nuskaitymas: 1.588s, rūšiavimas į dvi grupes: 0.145s, rūšiavimas sort: 0.222s

10000000 įrašų:
Vector nuskaitymas: 21.375s, rūšiavimas į dvi grupes: 7.016s, rūšiavimas sort: 2.769s
Mano nuskaitymas: 20.359s, rūšiavimas į dvi grupes: 4.744s, rūšiavimas sort: 1.988s

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

	void clear()
	{
		dydis = 0;
		limitas = 0;
		delete[] duomenys;
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

Mano vektoriaus perskirtstymas su 100000000 skaičių įvyksta 27 kartus.
