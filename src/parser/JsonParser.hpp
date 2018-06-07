//
// Created by Nicolas Guerin on 06/06/2018.
//

#pragma once

#include <string>
#include <map>
#include <vector>

class JsonParser {
	public:
		explicit JsonParser(const std::string &_data);
		~JsonParser();

		void fillTokens();

	private:
		std::string _data;
		std::vector<std::map<std::string, std::string>> _tokens;
};
