#pragma once
#include <list>
#include "dechet.h"
class ChargementDechet
{
public:
	ChargementDechet(std::list<Dechet*>* l) :liste_dechets(*l) {};
	Dechet* getDechet();

	~ChargementDechet();
private:
	std::list<Dechet*> liste_dechets;
};


Dechet* ChargementDechet::ChargementDechet::getDechet()
{
	Dechet* d = liste_dechets.front();
	liste_dechets.pop_front();
	return d;

}
