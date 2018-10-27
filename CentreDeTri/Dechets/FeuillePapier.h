#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class FeuillePapier :
	public Dechet
{
public:
	FeuillePapier() :Dechet(3, "Tas de feuilles de papier", 0, "inconnu", PAPIER, 90, false, false) { Compteur::ajouterConstructeur(); }
	~FeuillePapier() { Compteur::ajouterDestructeur(); }
};
