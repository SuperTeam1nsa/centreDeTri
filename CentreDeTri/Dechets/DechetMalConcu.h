#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class DechetMalConcu :
	public Dechet
{
public:
	DechetMalConcu() :Dechet(7, "Dechet en styromousse peu utile", 0, "gris", STYROFOAM, 15, true, true) { Compteur::ajouterConstructeur(); }
	~DechetMalConcu() { Compteur::ajouterDestructeur(); }
};
