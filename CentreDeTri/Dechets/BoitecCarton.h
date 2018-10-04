#pragma once
#include "../Dechet.h"
class BoitecCarton :
	public Dechet
{
public:
	BoitecCarton() :Dechet(3, "Grosse boite de demenagement", 0, "marron", CARTON, 100, false, true) {};
	~BoitecCarton() {};
};
