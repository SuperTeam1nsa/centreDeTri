#pragma once
#include <list>
#include "dechet.h"
#include "Compteur.h"

class ChargementDechet
{
public:
	ChargementDechet(std::list<Dechet*>* l) :liste_dechets(*l) {
		Compteur::ajouterConstructeur();
	}
	Dechet* getDechet();
	ChargementDechet(ChargementDechet& c);
	~ChargementDechet();

private:
	std::list<Dechet*> liste_dechets;
};
