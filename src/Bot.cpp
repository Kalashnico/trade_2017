//
// Created by Nicolas Guerin on 05/06/2018.
//

#include <iostream>
#include "Bot.hpp"

Bot::Bot(int bankroll) :  _id{} , _token{}, _bankroll{bankroll}, _marketList{}, _buyList{}
{

}

Bot::~Bot()
{

}

void Bot::login()
{
	//TODO GET LE JSON
	std::string response = "\n"
		"{\n"
		"\"token\": \"93144b288eb1fdccbe46d6fc0f241a51766ecd3d\"\n"
		"}";

	//TODO PARSE LE JSON
	auto pos = response.find("token");
	if (pos == std::string::npos)
		throw std::invalid_argument("Token failed");

	pos += 9; //To go to token first letter.

	std::string loginToken{};

	for (; response.at(pos) != '\"' ; ++pos) {
		loginToken += response.at(pos);
	}

	std::cout << "Token = " << loginToken << std::endl;
}

void Bot::resetToken()
{
	//TODO GET LE JSON
	std::string response = "\n"
		"{\n"
		"\"token\": \"93144b288eb1fdccbe46d6fc0f241a51766ecd3d\"\n"
		"}";


	auto pos = response.find("token");
	if (pos == std::string::npos)
		throw std::invalid_argument("Token failed");

	pos += 9; //To go to token first letter.

	std::string newToken{};

	for (; response.at(pos) != '\"' ; ++pos) {
		newToken += response.at(pos);
	}

	_token = newToken;
}

void Bot::buy()
{
	//Faire l'achat;

	Buy buy(1, 0, 0, 0);
	_buyList.emplace_back(buy);
	_bankroll -= buy.getTotalPrice();
}

int Bot::defineSoldForBuying() const noexcept
{
	auto buyingSold = ((10 * _bankroll) / 100) / _marketList.size();

	return static_cast<int>(buyingSold);
}