#pragma once
#include "../Dechet.h"
class RestantNourriture :
	public Dechet
{
public:
	RestantNourriture() :Dechet(2, "Restes d'un repas", 0, "marron", NOURRITURE, 100, false, false) {} ;
	~RestantNourriture() {} ;
};
