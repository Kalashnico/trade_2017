//
// Created by Nicolas Guerin on 05/06/2018.
//

#pragma once

#include <string>
#include <vector>
#include <queue>
#include "MarketPlace.hpp"
#include "parser/Parser.hpp"
#include "Stats.hpp"
#include "Bollinger.hpp"

#define PERIOD 20

class Bot {
	public:
		Bot();
		~Bot();

		//Interaction functions
		void loop();
		void marketDecision(MarketID marketID);

		MarketPlace getMarket(MarketID marketID) {
			for (auto const &market : _marketList) {
				if (marketID == market.getId())
					return market;

			}
			return _marketList.at(0);
		}



	private:
		std::vector<MarketPlace> _marketList;
		Parser			_parser;
		Stats			_stats;
		Bollinger		_algorithm;
		float 			_lastBoughtPrice;

		void forceSell(MarketID marketID) noexcept;
};
