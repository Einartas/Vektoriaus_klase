#include "Funkcijos.h"
#include "Generavimas.h"
#include "Vektorius.h"

int main()
{

	int ka = 0;
	cout << "Studentu duomenys 0, skaiciu pildymas 1 : ";
	cin >> ka;

	if (ka == 1)
	{
		auto start = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();

		start = std::chrono::steady_clock::now();
		unsigned int sz = 10000;
		vektorius<int> v1;
		for (int i = 1; i <= sz; ++i)
			v1.push(i);
		end = std::chrono::steady_clock::now();
		cout << sz << " skaiciu vektoriaus pildymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

		start = std::chrono::steady_clock::now();
		sz = 100000;
		vektorius<int> v2;
		for (int i = 1; i <= sz; ++i)
			v2.push(i);
		end = std::chrono::steady_clock::now();
		cout << sz << " skaiciu vektoriaus pildymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

		start = std::chrono::steady_clock::now();
		sz = 1000000;
		vektorius<int> v3;
		for (int i = 1; i <= sz; ++i)
			v3.push(i);
		end = std::chrono::steady_clock::now();
		cout << sz << " skaiciu vektoriaus pildymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

		start = std::chrono::steady_clock::now();
		sz = 10000000;
		vektorius<int> v4;
		for (int i = 1; i <= sz; ++i)
			v4.push(i);
		end = std::chrono::steady_clock::now();
		cout << sz << " skaiciu vektoriaus pildymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;

		start = std::chrono::steady_clock::now();
		sz = 100000000;
		vektorius<int> v5;
		for (int i = 1; i <= sz; ++i)
			v5.push(i);
		end = std::chrono::steady_clock::now();
		cout << sz << " skaiciu vektoriaus pildymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;


	}

	if (ka == 0)
	{
		std::stringstream S;
		std::string name, sur;
		int n = 0, np = 0, fl = 0;
		studentas stud;
		vektorius<studentas> list;
		vektorius<studentas> geri;
		vektorius<studentas> blogi;
		auto start = std::chrono::steady_clock::now();
		auto end = std::chrono::steady_clock::now();
		clock_t tStart = 0;

		cout << "Kurti faila (0), skaityti is esamo failo (1): " << std::endl;
		cin >> fl;

		if (fl == 0)
		{
			cout << "Kiek bus studentu? : " << std::endl;
			cin >> n;
			cout << "Kiek studentas turi pazymiu? : " << std::endl;
			cin >> np;

			clock_t tStart = clock();

			mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
			int_distribution dist(1, 10);

			std::ofstream O("..\\..\\Generavimas.txt");

			start = std::chrono::steady_clock::now();

			for (int i = 0; i < n; i++)
			{
				generate_name(name, sur);
				S << name << " " << sur;

				for (int j = 0; j < np; j++)
				{
					S << " " << dist(mt);
				}

				S << std::endl;
				O << S.str();
				S.str("");
			}
			O.close();

			end = std::chrono::steady_clock::now();
			cout << "Generavimas su " << n << " studentu ir " << np << " pazymiu uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;
		}

		vektorius<std::string> data;
		bool result = file("..\\..\\Generavimas.txt", data);

		if (fl == 1)
		{
			clock_t tStart = clock();
			if (result)
			{
				for (std::string& line : data)
				{
					n++;
				}
			}
			int space = 0;
			for (auto el : data)
			{
				for (int i = 0; i < el.length(); i++)
				{
					if (i != el.length() - 1)
					{
						if ((el.at(i) == ' ') && (el.at(i + 1) != ' ')) space++;
					}
				}
				break;
			}
			np = space - 1;
		}

		int p = 0, pazymiai = 0;
		std::ofstream G("..\\..\\Gerieciai_vector.txt");
		std::ofstream B("..\\..\\Blogieciai_vector.txt");

		B << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis vid" << std::left << std::setw(20) << "Galutinis med" << std::endl << std::endl;
		G << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde" << std::left << std::setw(20) << "Galutinis vid" << std::left << std::setw(20) << "Galutinis med" << std::endl << std::endl;

		start = std::chrono::steady_clock::now();

		string vardas, pavarde;
		int mark = 0, egzaminas = 0, paz[100];
		double galutinis = 0, mediana = 0;

		for (auto& line : data)
		{
			S.str("");
			S << line;
			S >> vardas >> pavarde;
			stud.set_vardas(vardas);
			stud.set_pavarde(pavarde);
			for (int i = 0; i < (np - 3); i++)
			{
				S >> p;
				pazymiai += p;
				paz[i] = p;
			}

			std::sort(paz, paz + (np - 3));
			if (((np - 3) - 2) % 2)
			{
				mediana = (paz[((np - 3) - 2) / 2] + paz[(((np - 3) - 2) / 2 + 1)]) / 2;
				stud.set_mediana(mediana);
			}
			else
			{
				mediana = paz[((np - 3) - 2) / 2];
				stud.set_mediana(mediana);
			}

			S >> egzaminas;
			stud.set_egzaminas(egzaminas);
			galutinis = 0.4 * (pazymiai / (np - 3)) + 0.6 * egzaminas;
			stud.set_galutinis(galutinis);

			pazymiai = 0;
			stud.mark().clear();
			list.push(stud);
		}
		data.clear();

		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu nuskaitymas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		start = std::chrono::steady_clock::now();
		std::sort(list.begin(), list.end(), compare_mark);
		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu rusiavimas sort funkcija uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		start = std::chrono::steady_clock::now();
		for (auto el = list.end(); el != list.begin(); el--)
		{
			if (el->galutinis() >= 5)
			{
				geri.push(*el);
				list.pop();
			}
		}
		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu rusiavimas i dvi kategorijas uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		start = std::chrono::steady_clock::now();

		for (auto el : geri)
		{
			G << el;
		}
		for (auto el : list)
		{
			B << el;
		}

		end = std::chrono::steady_clock::now();
		cout << "Failo su " << n << " studentu isvedimas i naujus failus uztruko: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << std::endl;

		B.close();
		G.close();

		printf("Visos programos darbo laikas: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	}
	system("pause");
}