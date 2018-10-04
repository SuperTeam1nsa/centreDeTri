#pragma once
#include "Dechet.h"
class VerreCafe :
	public Dechet
{
public:
	VerreCafe() :Dechet(1, "Tasse de cafe casse", 0, "gris", METAL, 70, false, true) {};
	~VerreCafe() {};
};