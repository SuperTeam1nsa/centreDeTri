#pragma once
#include "../Dechet.h"
#include "../Compteur.h"

class BoiteCarton :
	public Dechet
{
public:
	BoiteCarton() :Dechet(3, "Grosse boite de demenagement", 0, "marron", CARTON, 100, false, true) { Compteur::ajouterConstructeur(); }
	~BoiteCarton() { Compteur::ajouterDestructeur(); } //automatiquement virtual par héritage de dechet de tte façon
};
