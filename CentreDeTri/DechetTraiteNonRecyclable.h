﻿#pragma once
#include "DechetTraite.h"
#include "Compteur.h"

class DechetTraiteNonRecyclable :
	public DechetTraite
{
public:
	DechetTraiteNonRecyclable(Dechet* dechet) : DechetTraite(dechet) { Compteur::ajouterConstructeur(); }
	virtual ~DechetTraiteNonRecyclable() { Compteur::ajouterDestructeur(); }
};
