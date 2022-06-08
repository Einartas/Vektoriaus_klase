#pragma once
#include <map>
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
#include <chrono>

using std::string;
using std::mt19937;

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int>  int_distribution;

void generate_name(std::string& name, std::string& sur);
