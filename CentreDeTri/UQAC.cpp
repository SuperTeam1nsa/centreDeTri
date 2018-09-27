#include "UQAC.h"
#include <list>



UQAC::UQAC()
{
}



UQAC::~UQAC()
{
}


ChargementDechet * UQAC::getChargementDechet()
{
	std::list<Dechet> liste_dechets;
	liste_dechets.push_back(Dechet(1, "DechetDe1kg"));
	liste_dechets.push_back(Dechet(45, "DechetDe45kg"));
	//materiel matos = CARTON;
	//DECHET:: car l'enum est défini(en public dans la classe déchet, sinon direct CARTON)
	//https://bytes.com/topic/c/answers/685178-how-pass-enum-function
	liste_dechets.push_back(Dechet(13, 50, 1, "DechetDe13kgAsssezPurDeType1", "vert", Dechet::carton, false, false));
	return new ChargementDechet(liste_dechets);
}

