#pragma once
#include "../Dechet.h"
class Chaise :
	public Dechet
{
public:
	Chaise() :Dechet(6, "Chaise", 0, "rouge", BOIS, 100, false, true) {};
	~Chaise() {};
};
