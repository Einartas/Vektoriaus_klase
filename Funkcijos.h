#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <random>
#include <cmath>
#include <iterator>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <sstream>

using std::cout;
using std::cin;
using std::string;

class zmogus
{
protected:
	std::string vardas_;
	std::string pavarde_;
public:
	inline std::string vardas() const { return vardas_; }
	inline std::string pavarde() const { return pavarde_; }

	virtual void set_vardas(string v) = 0;
	virtual void set_pavarde(string p) = 0;
};

class studentas : public zmogus
{
private:
	int egzaminas_, pazymiai_;
	std::vector<int> mark_;
	double galutinis_, mediana_;
public:
	studentas();
	//getter'iai
	inline int egzaminas() { return egzaminas_; }
	inline int pazymiai() { return pazymiai_; }
	inline std::vector<int> mark() { return mark_; }
	inline double mediana() { return mediana_; }
	inline double galutinis() const { return galutinis_; }
	//setter'iai
	std::istream& read(std::ifstream&, double&);
	void set_vardas(string v) { vardas_ = v; }
	void set_pavarde(string p) { pavarde_ = p; }
	void set_mark(int& m) { mark_.push_back(m); }
	void set_egzaminas(int e) { egzaminas_ = e; }
	void set_pazymiai(int& p) { pazymiai_ = p; }
	void set_galutinis(double& g) { galutinis_ = g; }
	void set_mediana(double& m) { mediana_ = m; }

	studentas(const studentas&); // copy konstruktorius

	studentas& operator=(const studentas&); // priskyrimo operatorius

	friend std::ostream& operator << (std::ostream& out, studentas& s);
};

void input(studentas& temp);

bool file(std::string failas, std::vector<std::string>& data);

void output(studentas& temp, int y);

bool compare_vardas(const studentas& a, const studentas& b);

bool compare_mark(const studentas& a, const studentas& b);