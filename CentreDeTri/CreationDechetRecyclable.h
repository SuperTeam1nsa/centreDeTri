#pragma once
#include "OperationTraitement.h"
#include "Compteur.h"

class CreationDechetRecyclable :
	public OperationTraitement
{
public:
	CreationDechetRecyclable(UsineTraitement* usineTraitement) : OperationTraitement(usineTraitement) { Compteur::ajouterConstructeur(); };
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteRecyclable(dechet); return true; }
	virtual ~CreationDechetRecyclable() { Compteur::ajouterDestructeur(); };
};
