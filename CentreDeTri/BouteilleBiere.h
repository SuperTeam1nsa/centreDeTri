#pragma once
#include "Dechet.h"
class BouteilleBiere :
	public Dechet
{
public:
	BouteilleBiere() :Dechet(1, "Bouteille de biere vide", 0, "vert", BOUTEILLE, 95, false, true) {};
	~BouteilleBiere() {};
};
