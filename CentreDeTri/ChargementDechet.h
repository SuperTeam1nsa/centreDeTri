#pragma once
#include <list>
#include "dechet.h"
#include "Compteur.h"

class ChargementDechet
{
public:
	ChargementDechet(std::list<Dechet*>* l) :liste_dechets(*l) { Compteur::ajouterConstructeur(); }
	Dechet* getDechet();
	ChargementDechet(ChargementDechet& c);
	~ChargementDechet();

private:
	std::list<Dechet*> liste_dechets;
};
ChargementDechet::ChargementDechet(ChargementDechet& c) {
	for (list<Dechet*>::iterator it = c.liste_dechets.begin(); it != c.liste_dechets.end(); ++it) {
		liste_dechets.push_back(new Dechet(**it));
	}
}
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
