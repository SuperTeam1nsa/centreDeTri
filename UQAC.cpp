#include "UQAC.h"
#include <list>



UQAC::UQAC()
{
}



UQAC::~UQAC()
{
}

ChargementDechet* UQAC::getChargementDechet()
{
	std::list<Dechet> liste_dechets;
	liste_dechets.push_back(new Dechet(1, "DechetDe1kg"));
	liste_dechets.push_back(new Dechet(45, "DechetDe45kg"));
	//materiel matos = CARTON;
	//DECHET:: car l'enum est d�fini(en public dans la classe d�chet, sinon direct CARTON)
	//https://bytes.com/topic/c/answers/685178-how-pass-enum-function
	liste_dechets.push_back(new Dechet(13, 50, 1, 55 "DechetDe13kgAsssezPurDeType1", "vert", Dechet::CARTON, false, false));
	return new ChargementDechet(liste_dechets);

