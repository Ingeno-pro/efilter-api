#include "nfilter.hpp"

IIRFilter::IIRFilter(std::vector<double> b, std::vector<double> a)
{
	this->order = b.size();
	this->b = b;
	this->a = a;
	
	this->_savedInput.resize(this->order, 0);
	this->_savedOutput.resize(this->order, 0);
	
}
IIRFilter::~IIRFilter(){
}

double IIRFilter::_transmitance(double input){
	
	double output=0;
	for(int i=0;i < this->b.size();i++){
		output += (!i) ? input*this->b[i] : this->_savedInput[i-1]*this->b[i];
	}

	for(int i=0;i < this->a.size();i++){
		output -= this->_savedOutput[i-1]*this->a[i];
	}
	
	this->_savedInput.insert(this->_savedInput.begin(), input);
	this->_savedInput.erase(this->_savedInput.begin()+(int)this->b.size());
	
	this->_savedOutput.insert(this->_savedOutput.begin(), output);
	this->_savedOutput.erase(this->_savedOutput.begin()+(int)this->a.size());
	
	return output;
}
double IIRFilter::operator*(const double &number){
	return this->_transmitance(number);
}
std::vector<double> IIRFilter::operator*(std::vector<double> tab){

	for(int i=0; i < tab.size(); i++){
		tab[i] = *this*tab[i];
	}
	return tab;
}

FIRFilter::FIRFilter(std::vector<double> b)
{
	this->order = b.size();
	this->b = b;
	
	this->_savedInput.resize(this->order, 0);
	
}
FIRFilter::~FIRFilter(){

}

double FIRFilter::_transmitance(double input){
	
	double output=0;
	for(int i=0;i < this->order;i++){
		output += (!i) ? input*this->b[i] : this->_savedInput[i-1]*this->b[i];
	}
	
	this->_savedInput.insert(this->_savedInput.begin(), input);
	this->_savedInput.erase(this->_savedInput.begin()+(int)this->b.size());
	
	return output;
}
double FIRFilter::operator*(const double &number){
	return this->_transmitance(number);
}
std::vector<double> FIRFilter::operator*(std::vector<double> tab){

	for(int i=0; i < tab.size(); i++){
		tab[i] = *this*tab[i];
	}
	return tab;
}