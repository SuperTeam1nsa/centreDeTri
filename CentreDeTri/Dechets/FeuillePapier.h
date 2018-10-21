#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class FeuillePapier :
	public Dechet
{
public:
	FeuillePapier() :Dechet(1, "Tas de feuilles de papier", 0, "blanc", PAPIER, 90, false, false) { Compteur::ajouterConstructeur(); }
	~FeuillePapier() { Compteur::ajouterDestructeur(); }
};
