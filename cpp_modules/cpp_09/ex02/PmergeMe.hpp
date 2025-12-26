#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>


bool	parseAndAddNumber(std::string name, std::vector<int>& vec, std::deque<int>& deq);
void 	displayDeque(const std::deque<int>& d);
void 	displayVector(const std::vector<int>& v);
void 	sortVector(std::vector<int>& vec);
void 	sortDeque(std::deque<int>& deq);

