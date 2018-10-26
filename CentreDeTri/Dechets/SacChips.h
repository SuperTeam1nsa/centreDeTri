#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class SacChips :
	public Dechet
{
public:
	SacChips() :Dechet(1, "Sac de chips vide", 3, "inconnu", PLASTIQUE, 80, false, false) { Compteur::ajouterConstructeur(); }
	~SacChips() { Compteur::ajouterDestructeur(); }
};
