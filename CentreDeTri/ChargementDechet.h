#pragma once
#include <list>
#include "dechet.h"
#include "Compteur.h"

class ChargementDechet
{
public:
	ChargementDechet(std::list<Dechet*>* l) :liste_dechets(*l) { Compteur::ajouterConstructeur(); }
	Dechet* getDechet();

	~ChargementDechet();

private:
	std::list<Dechet*> liste_dechets;
};

ChargementDechet::~ChargementDechet() {
	for (list<Dechet*>::iterator it = liste_dechets.begin(); it != liste_dechets.end(); ++it) {
		delete *it;
	}
	liste_dechets.resize(0);
	Compteur::ajouterDestructeur();
}

Dechet* ChargementDechet::ChargementDechet::getDechet()
{
	Dechet* d = liste_dechets.front();
	liste_dechets.pop_front();
	return d;

}
