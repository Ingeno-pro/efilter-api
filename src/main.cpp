#include <iostream>
#include "efilter.hpp"

double lowpass(double input){
	return 3.18*input;
}

int main(){
	
	eFilter filter(&lowpass);
	std::vector<double> d = {2, 3, 4, 4, 5};
	d = filter*d;
	std::cout << d[0] << std::endl;
	return 0;
}