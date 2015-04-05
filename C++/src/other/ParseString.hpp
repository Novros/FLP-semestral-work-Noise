#pragma once

#include <string>
#include <vector>

inline std::vector<std::string> parseString(std::string input, std::string delimiter) {
	size_t pos = 0;
	std::string token;
	std::vector<std::string> lines;

	while((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos);
		lines.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	lines.push_back(input);
	return lines;
}