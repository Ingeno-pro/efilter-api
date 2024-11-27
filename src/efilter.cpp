#include "efilter.hpp"

eFilter::eFilter(double (*transmitance)(double input)){
	this->_transmitance = transmitance;	
}
eFilter::~eFilter(){
	this->_transmitance = NULL;	
}

double eFilter::operator*(const double &number){
	return this->_transmitance(number);
}
std::vector<double> eFilter::operator*(std::vector<double> tab){

	for(int i=0; i < tab.size(); i++){
		tab[i] = *this*tab[i];
	}
	return tab;
}