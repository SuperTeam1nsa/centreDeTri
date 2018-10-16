#pragma once
#include "ChargementDechet.h"
#include "Dechets/BoiteCarton.h"
#include "Dechets/BouteilleBiere.h"
#include "Dechets/Chaise.h"
#include "Dechets/DechetMalConcu.h"
#include "Dechets/FeuillePapier.h"
#include "Dechets/PlanteVerte.h"
#include "Dechets/QuelqueChose.h"
#include "Dechets/QuelqueChose.h"
#include "Dechets/RestantNourriture.h"
#include "Dechets/SacChips.h"
#include "Dechets/VerreCafe.h"

class UQAC
{
public:
	UQAC();
	~UQAC();
	//test de git
	static ChargementDechet* getChargementDechets();
};

ChargementDechet* UQAC::getChargementDechets() {
	std::list<Dechet*> *liste = new std::list<Dechet*>();
	for (int i = 0; i < 5; i++)
	{
		liste->push_back(new BoiteCarton());
		liste->push_back(new BouteilleBiere());
		liste->push_back(new Chaise());
		liste->push_back(new DechetMalConcu());
		liste->push_back(new FeuillePapier());
		liste->push_back(new PlanteVerte());
		liste->push_back(new QuelqueChose());
		liste->push_back(new RestantNourriture());
		liste->push_back(new SacChips());
		liste->push_back(new VerreCafe());
	}
	return new ChargementDechet(liste);
}
