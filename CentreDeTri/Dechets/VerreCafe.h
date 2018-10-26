#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class VerreCafe :
	public Dechet
{
public:
	VerreCafe() :Dechet(1, "Tasse de cafe casse", 0, "brun", METAL, 70, false, true) { Compteur::ajouterConstructeur(); }
	~VerreCafe() { Compteur::ajouterDestructeur(); }
};
