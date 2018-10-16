#pragma once
#include "../Dechet.h"
class BoiteCarton :
	public Dechet
{
public:
	BoiteCarton() :Dechet(3, "Grosse boite de demenagement", 0, "marron", CARTON, 100, false, true) {};
	~BoiteCarton() {};
};
