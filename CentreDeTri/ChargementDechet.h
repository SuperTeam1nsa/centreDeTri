#pragma once
#include <list>
#include "dechet.h"
class ChargementDechet
{
public:
	ChargementDechet(std::list<Dechet>);
	Dechet getDechet();

	~ChargementDechet();
private:
	std::list<Dechet> liste_dechets;
};

