#pragma once
#include "Contact.h"

class Cunoscut:public Contact{
public:
	Cunoscut(std::string nume_, std::string prenume_, std::string nr_de_tel) {
		nume = nume_;
		prenume = prenume;
		numar_de_telefon = nr_de_tel;
	}
	std::string numar_de_telefon;
	TipContact getContactType() {
		return TipCunoscut;
	}
};

