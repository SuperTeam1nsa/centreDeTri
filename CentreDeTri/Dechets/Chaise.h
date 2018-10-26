#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class Chaise :
	public Dechet
{
public:
	Chaise() :Dechet(6, "Chaise", 0, "brun", BOIS, 100, false, true) { Compteur::ajouterConstructeur(); }
	~Chaise() { Compteur::ajouterDestructeur(); }
};
