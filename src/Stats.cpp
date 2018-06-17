//
// Created by Nicolas Guerin on 15/06/2018.
//

#include "Stats.hpp"

Stats::Stats()
{

}

Stats::~Stats()
{

}

void Stats::setValues(float bk, int crypto, int rawMat, int stockEx, int forex) noexcept
{
	_bankroll = bk;
	_crypto = crypto;
	_rawMat = rawMat;
	_stockEx = stockEx;
	_forex = forex;
}
