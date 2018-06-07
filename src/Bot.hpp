//
// Created by Nicolas Guerin on 05/06/2018.
//

#pragma once

#include <string>
#include <vector>
#include <queue>
#include "MarketPlace.hpp"
#include "Buy.hpp"

class Bot {
	public:
		explicit Bot(int bkroll = 10000);
		~Bot();

		//Interaction functions
		void	login();
		void	resetToken();
		void pull();
		void buy();
		void sell();
		int defineSoldForBuying() const noexcept ;



	private:
		int 	_id;
		std::string _token;
		int	_bankroll;
		std::vector<MarketPlace> _marketList;
		std::vector<Buy>	_buyList;
};
