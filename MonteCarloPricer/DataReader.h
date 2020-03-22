#pragma once

#ifndef GUARD_DataReader_h
#define GUARD_DataReader_h

#include <string>
#include <vector>
#include "Option.h"

std::vector<std::string> split(const std::string& line);
std::vector<Option> readInput(const std::string& path);
#endif // !GUARD_DataReader_h
