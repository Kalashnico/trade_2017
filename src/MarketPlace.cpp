//
// Created by Nicolas Guerin on 05/06/2018.
//

#include "MarketPlace.hpp"

#include <utility>

MarketPlace::MarketPlace(MarketID id, std::string name) : _id{id}, _name{std::move(name )}, _data{}
{
}

MarketPlace::~MarketPlace()
{

}
