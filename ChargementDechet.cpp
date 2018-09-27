#include "ChargementDechet.h"




ChargementDechet::ChargementDechet(std::list<Dechet> l) :liste_dechets(l)
{
}


Dechet ChargementDechet::getDechet()
{
	Dechet d = liste_dechets.front();
	liste_dechets.pop_front()
		return d;

}

ChargementDechet::~ChargementDechet()
{
}
