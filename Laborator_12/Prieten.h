#pragma once
#include "Contact.h"
class Prieten:public Contact{
public:
	Prieten(std::string nume_, std::string prenume_, std::string data_nastere_, std::string nr_tel, std::string adresa_) {
		nume = nume_;
		prenume = prenume_;
		data_nastere = data_nastere_;
		nr_de_telefon = nr_tel;
		adresa = adresa_;

	}
	std::string data_nastere;
	std::string nr_de_telefon;
	std::string adresa;
	TipContact getContactType() {
		return TipPrieten;
	}
};

