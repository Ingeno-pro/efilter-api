#include <iostream>
#include <vector>
#include <cstdint>

#ifndef __N_FILTER_H__
#define __N_FILTER_H__

class IIRFilter
{
	public:
		int order;
		IIRFilter(std::vector<double> b, std::vector<double> a);
		~IIRFilter();
		
		double operator*(const double &number);
		std::vector<double> operator*(std::vector<double> tab);
		
	private:
		std::vector<double> b;
		std::vector<double> a;
		
		std::vector<double> _savedInput;
		std::vector<double> _savedOutput;
		
		double _transmitance(double input);
};


class FIRFilter
{
	public:
		int order;
		FIRFilter(std::vector<double> b);
		~FIRFilter();
		
		double operator*(const double &number);
		std::vector<double> operator*(std::vector<double> tab);
		
	private:
		std::vector<double> b;
		
		std::vector<double> _savedInput;
		
		double _transmitance(double input);
	
};

#endif