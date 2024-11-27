#include <iostream>
#include <vector>

#ifndef __E_FILTER_H__
#define __E_FILTER_H__

class eFilter
{
	public:
		eFilter(double (*transmitance)(double input));
		~eFilter();
	
		double operator*(const double &number);
		std::vector<double> operator*(std::vector<double> tab);
	
	private:
		double (*_transmitance)(double input);
	
};


#endif