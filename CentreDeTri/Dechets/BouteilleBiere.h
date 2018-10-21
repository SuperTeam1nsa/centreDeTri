#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class BouteilleBiere :
	public Dechet
{
public:
	BouteilleBiere() :Dechet(1, "Bouteille de biere vide", 0, "vert", BOUTEILLE, 95, false, true) { Compteur::ajouterConstructeur(); }
	virtual ~BouteilleBiere() { Compteur::ajouterDestructeur(); }
};
