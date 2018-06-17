//
// Created by Nicolas Guerin on 15/06/2018.
//

#pragma once

#include "MarketPlace.hpp"

class Stats {
	public:
		Stats();
		~Stats();

		float getBankroll() const noexcept { return _bankroll; }

		int getShares(MarketID marketID) {
			switch (marketID) {
				case CRYPTO:
					return _crypto;
				case RAW_MAT:
					return _rawMat;
				case STOCK_EX:
					return _stockEx;
				default:
					return _forex;
			}
		}

		void setValues(float bk, int crypto, int rawMat, int stockEx, int forex) noexcept;

	private:
		float	_bankroll;
		int 	_crypto;
		int 	_rawMat;
		int 	_stockEx;
		int 	_forex;
};
