//
// Created by Nicolas Guerin on 05/06/2018.
//

#pragma once

#include <string>
#include <vector>
#include <iostream>

enum MarketID {
	CRYPTO,
	RAW_MAT,
	FOREX,
	STOCK_EX
};

static std::string getMarketString(MarketID marketID) {
	switch (marketID) {
		case CRYPTO:
			return "crypto";
		case RAW_MAT:
			return "raw_material";
		case FOREX:
			return "forex";
		case STOCK_EX:
			return "stock_exchange";
		default:
			break;
	}
}

class MarketPlace {
	public:
		MarketPlace(MarketID id,std::string name);
		~MarketPlace();

		MarketID getId() const noexcept { return _id; }
		std::string getName() const noexcept { return _name; }
		std::vector<float> getData() const noexcept { return _data; }
		float	getLastValue() const noexcept {
			if (!_data.empty())
				return _data.back();
			return 0.0;
		}

		void	setData(float value) noexcept {
			if (_data.empty())
				_data.emplace_back(value);
			else if (!_data.empty() && _data.back() != value) {
				_data.emplace_back(value);
			}
		}

	private:
		MarketID	 _id;
		std::string	 _name;
		std::vector<float> _data;

};
