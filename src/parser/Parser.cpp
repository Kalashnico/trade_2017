//
// Created by Nicolas Guerin on 06/06/2018.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "Parser.hpp"

Parser::Parser() : _data()
{
	MarketPlace crypto(CRYPTO, "crypto");
	_marketList.emplace_back(crypto);

	MarketPlace rawMat(RAW_MAT, "raw_material");
	_marketList.emplace_back(rawMat);

	MarketPlace forex(FOREX, "forex");
	_marketList.emplace_back(forex);

	MarketPlace stockExchange(STOCK_EX, "stock_exchange");
	_marketList.emplace_back(stockExchange);

}

Parser::~Parser()
{

}

void Parser::getInput()
{
	std::ifstream	file("../push_index/.index.db");
	std::string	dataBuffer;

	while (std::getline(file, dataBuffer)) {
		try {
			fillMarketList(dataBuffer);
		}
		catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		_data += dataBuffer;
	}
	file.close();
}

void Parser::parseStats()
{
	std::ifstream file(".server.log");
	std::string	dataBuffer;
	int crypto{};
	int stockEx{};
	int rawMat{};
	int forex{};
	float bk{};

	while (std::getline(file, dataBuffer)) {
		if (dataBuffer.find("crypto") != std::string::npos) {
			crypto = std::stoi(dataBuffer.c_str() + 7);
		}
		else if (dataBuffer.find("stock_exchange") != std::string::npos) {
			stockEx = std::stoi(dataBuffer.c_str() + 15);
		}
		else if (dataBuffer.find("raw_material") != std::string::npos) {
			rawMat = std::stoi(dataBuffer.c_str() + 13);
		}
		else if (dataBuffer.find("forex") != std::string::npos) {
			forex = std::stoi(dataBuffer.c_str() + 6);
		}
		else if (dataBuffer.find("current_money") != std::string::npos) {
			bk = std::stof(dataBuffer.c_str() + 14);

		}
	}
	_stats.setValues(bk, crypto, rawMat, stockEx, forex);

}

void Parser::fillMarketList(const std::string &data)
{
	std::string value;

	if (data.find("crypto") != std::string::npos) {
		value = data.c_str() + 7;
		_marketList.at(CRYPTO).setData(std::stof(value.c_str()));
	}
	else if (data.find("stock_exchange") != std::string::npos) {
		value = data.c_str() + 15;
		_marketList.at(STOCK_EX).setData(std::stof(value.c_str()));
	}
	else if (data.find("raw_material") != std::string::npos) {
		value = data.c_str() + 13;
		_marketList.at(RAW_MAT).setData(std::stof(value.c_str()));
	}
	else if (data.find("forex") != std::string::npos) {
		value = data.c_str() + 6;
		_marketList.at(FOREX).setData(std::stof(value.c_str()));
	}
	else
		throw std::invalid_argument("Unsupported market place");
}
