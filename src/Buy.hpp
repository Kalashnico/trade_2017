//
// Created by Nicolas Guerin on 06/06/2018.
//

#pragma once

#include <jmorecfg.h>
#include "MarketPlace.hpp"

class Buy {
	public:
		Buy(int marketPlace, int priceUnityBuy, int quantityBuy, int index);
		~Buy();

		int getMarketPlace() const noexcept { return _marketPlaceId; }
		int getUnityPrice() const noexcept { return  _priceUnityBuy; }
		int getTotalPrice() const noexcept { return _priceTotalBuy; }
		int getQuantity() const noexcept { return _quantityBuy; }

	private:
		int	_marketPlaceId;
		int	_priceUnityBuy;
		int	_priceTotalBuy;
		int 	_quantityBuy;
		int	_index;
};
