#pragma once
#include <string>

enum TipContact {
	TipPrieten, 
	TipCunoscut, 
	TipColeg
};

class Contact{
public:
	std::string nume;
	std::string prenume;
	virtual TipContact getContactType() = 0;
};

