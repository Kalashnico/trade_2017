//
// Created by Nicolas Guerin on 06/06/2018.
//

#pragma once

#include <string>
#include <map>
#include <vector>
#include "../MarketPlace.hpp"
#include "../Stats.hpp"

class Parser {
	public:
		Parser();
		~Parser();

		void getInput();
		std::vector<MarketPlace> getMarketList() const noexcept { return _marketList; }
		void parseStats();
		Stats getStats() const noexcept { return _stats; }


	private:
		std::string _data;
		std::vector<MarketPlace> _marketList;
		Stats	_stats;

		void fillMarketList(const std::string &data);

};
