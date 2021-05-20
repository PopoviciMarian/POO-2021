#pragma once
#include "Contact.h"

class Coleg:public Contact{
public:
	Coleg(std::string nume_, std::string prenume_, std::string nr_tel, std::string firma_,  std::string adresa_) {
		nume = nume_;
		prenume = prenume_;
		numar_de_telefon = nr_tel;
		firma = firma_;
		adresa = adresa_;

	}
	std::string numar_de_telefon;
	std::string firma;
	std::string adresa;
	TipContact getContactType() {
		return TipColeg;
	}
};

