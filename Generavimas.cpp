#include "Generavimas.h"

void generate_name(std::string& name, std::string& sur)
{

	string names[10] = { "Vardas1", "Vardas2", "Vardas3", "Vardas4", "Vardas5", "Vardas6", "Vardas7", "Vardas8", "Vardas9", "Vardas10" };
	string surs[10] = { "Pavarde1", "Pavarde2", "Pavarde3", "Pavarde4", "Pavarde5", "Pavarde6", "Pavarde7", "Pavarde8", "Pavarde9", "Pavarde10" };

	mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
	int_distribution dist(0, 9);

	name = names[dist(mt)];
	sur = surs[dist(mt)];
}