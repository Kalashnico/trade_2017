//
// Created by Nicolas Guerin on 06/06/2018.
//

#include "Buy.hpp"

Buy::Buy(int marketPlace, int priceUnityBuy, int quantityBuy, int index) : _marketPlaceId{marketPlace},
								   _priceUnityBuy{priceUnityBuy},
								   _quantityBuy{quantityBuy},
								   _index{index}
{
	_priceTotalBuy = priceUnityBuy * quantityBuy;
}

Buy::~Buy()
{
}
