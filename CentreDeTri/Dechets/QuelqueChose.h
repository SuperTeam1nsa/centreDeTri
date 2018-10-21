#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class QuelqueChose :
	public Dechet
{
public:
	QuelqueChose() :Dechet(10, "Un gros tas sombre et plutot lourd", 0, "noir", INCONNU, 10, false, false) { Compteur::ajouterConstructeur(); }
	virtual ~QuelqueChose() { Compteur::ajouterDestructeur(); }
};
