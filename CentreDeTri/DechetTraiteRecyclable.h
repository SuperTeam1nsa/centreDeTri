#pragma once
#include "DechetTraite.h"
#include "Compteur.h"

class DechetTraiteRecyclable :
	public DechetTraite
{
public:
	DechetTraiteRecyclable(Dechet* dechet) : DechetTraite(dechet) { Compteur::ajouterConstructeur(); }
	~DechetTraiteRecyclable() { Compteur::ajouterDestructeur(); }
};
