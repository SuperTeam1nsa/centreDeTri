#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class RestantNourriture :
	public Dechet
{
public:
	RestantNourriture() :Dechet(2, "Restes d'un repas", 0, "marron", NOURRITURE, 100, false, false) { Compteur::ajouterConstructeur(); }
	virtual ~RestantNourriture() { Compteur::ajouterDestructeur(); }
};
