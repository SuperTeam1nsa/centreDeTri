#pragma once
#include <list>
#include "dechet.h"
#include "Compteur.h"

class ChargementDechet
{
public:
	ChargementDechet(std::list<Dechet*>* l) :liste_dechets(*l) {Compteur::ajouterConstructeur();};
	Dechet* getDechet();

	~ChargementDechet() { Compteur::ajouterDestructeur(); };
private:
	std::list<Dechet*> liste_dechets;
};


Dechet* ChargementDechet::ChargementDechet::getDechet()
{
	Dechet* d = liste_dechets.front();
	liste_dechets.pop_front();
	return d;

}
