﻿#pragma once
#include "../Dechet.h"
#include "../Compteur.h"
class PlanteVerte :
	public Dechet
{
public:
	PlanteVerte() :Dechet(5, "Plante verte", 0, "vert", VEGETAL, 55, false, false) { Compteur::ajouterConstructeur(); }
	~PlanteVerte() { Compteur::ajouterDestructeur(); }
};
