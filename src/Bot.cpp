//
// Created by Nicolas Guerin on 05/06/2018.
//

#include <iostream>
#include <zconf.h>
#include <cmath>
#include "Bot.hpp"
#include "parser/Parser.hpp"

Bot::Bot() : _marketList{}
{
	_parser.getInput();
	_marketList = _parser.getMarketList();
}

Bot::~Bot()
{

}

void Bot::loop()
{
	auto beginTime = clock();

	while (true) {
		if (clock() - beginTime >= 125000) {
			break;
		}
		_parser.getInput();
		_marketList = _parser.getMarketList();
		usleep(500000);
		if (_marketList.at(0).getData().size() >= PERIOD) {
			_parser.parseStats();
			_stats = _parser.getStats();
			marketDecision(CRYPTO);
			_parser.parseStats();
			_stats = _parser.getStats();
			marketDecision(RAW_MAT);
		}
	}
	forceSell(CRYPTO);
	forceSell(RAW_MAT);
}

void Bot::marketDecision(MarketID marketID)
{
	Bollinger bollinger{};

	bollinger.setNumbers(_marketList.at(marketID).getData());
	bollinger.setIndex(static_cast<int>(_marketList.at(marketID).getData().size() - 1));
	bollinger.setPeriod(PERIOD);
	bollinger.computeAlgorithms();

	float priceUnity = _marketList.at(marketID).getLastValue();

	float lower = bollinger.getBMoins();
	float upper = bollinger.getBPlus();
	bool bought = false;

	if (priceUnity <= _stats.getBankroll() && priceUnity + (priceUnity * 0.05) <= lower) {
		auto quantityToBuy = static_cast<int>(floor(_stats.getBankroll() /  priceUnity));
		std::cout << "BUY:" << quantityToBuy << ":" + getMarketString(marketID) << std::endl;
		_lastBoughtPrice = priceUnity;
		bought = true;

	}
	auto shares = _stats.getShares(marketID);
	if (!bought && shares > 0) {
		if (priceUnity >= upper - (upper * 0.20) && _lastBoughtPrice < priceUnity) {
			std::cout << "SELL:" << shares << ":" + getMarketString(marketID) << std::endl;
		}
	}
}

void Bot::forceSell(MarketID marketID) noexcept
{
	auto shares = _stats.getShares(marketID);
	if (shares > 0)
		std::cout << "SELL:" << shares << ":" + getMarketString(marketID) << std::endl;
}