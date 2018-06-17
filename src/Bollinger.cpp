//
// Created by Nicolas Guerin on 05/02/2018.
//

#include <cmath>
#include <cstring>
#include <iostream>
#include "Bollinger.hpp"

Bollinger::Bollinger() : _index(0), _period(0), _sdCoeff(0), _ma(0), _sd(0), _bPlus(0), _bMoins(0)
{

}

Bollinger::~Bollinger()
{

}

void Bollinger::computeAlgorithms()
{
    algorithmMA();
    algorithmSD();
    algorithmBandP();
    algorithmBandM();
}


void Bollinger::algorithmMA()
{
    float arrMA[_period];
    int pos = 0;
    float newMA = 0;
    float sumMA = 0;

    std::memset(arrMA, 0, _period * sizeof(float));
    for (int itr = (_index - _period + 1); itr < _index + 1; itr++) {
        sumMA += -arrMA[pos] + _numbers.at(itr);
        arrMA[pos] = _numbers.at(itr);
        newMA = sumMA / _period;
        pos++;
        if (pos >= _period)
            pos = 0;
    }
    _ma = newMA;
}

void Bollinger::algorithmSD()
{
    float average = 0;
    long double sum1 = 0;
    long double sum2 = 0;
    float variance = 0;

   for (int itr = (_index - _period + 1); itr < _index + 1; itr++) {
        sum1 += _numbers.at(itr);
    }
    average = static_cast<float>(sum1 / _period);

    for (int itr = (_index - _period + 1); itr < _index + 1; itr++) {
        sum2 += (_numbers.at(itr) - average)  * (_numbers.at(itr) - average);
    }
    variance = static_cast<float>(sum2 / _period);
    _sd = sqrt(variance);
}

void Bollinger::algorithmBandP()
{
    _bPlus = _ma + _sdCoeff * _sd;
}

void Bollinger::algorithmBandM()
{
    _bMoins = _ma - _sdCoeff * _sd;
}
