//
// Created by Nicolas Guerin on 05/02/2018.
//

#ifndef BOLLINGER_HPP
#define BOLLINGER_HPP


#include <utility>
#include <vector>

class Bollinger
{
	public:
		//Constructor & Destructor
		Bollinger();
		~Bollinger();

		//memberFunction
		void    computeAlgorithms();

		void setIndex(int index) { _index = index; }
		void setPeriod(int period) { _period = period; }
		void setNumbers(const std::vector<float> &nbs) { _numbers = nbs; }

		float getBPlus() const noexcept  { return _bPlus; }
		float getBMoins() const noexcept { return _bMoins; }
	private:
		void    algorithmMA();
		void    algorithmSD();
		void    algorithmBandP();
		void    algorithmBandM();

		int     _index;
	    	int     _period;
	    	float   _sdCoeff;

	    	std::vector<float> _numbers;

	    	float   _ma;
		float   _sd;
	    	float   _bPlus;
	    	float   _bMoins;
	};


#endif //BOLLINGER_HPP
