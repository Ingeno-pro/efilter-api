#include "efilter.hpp"

eFilter::eFilter(double (*transmitance)(double input)){
	this->transmitance = transmitance;	
}
eFilter::~eFilter(){
	this->transmitance = NULL;	
}

double eFilter::operator*(const double &number){
	return this->transmitance(number);
}
std::vector<double> eFilter::operator*(std::vector<double> tab){

	for(int i=0; i < tab.size(); i++){
		tab[i] = *this*tab[i];
	}
	return tab;
}