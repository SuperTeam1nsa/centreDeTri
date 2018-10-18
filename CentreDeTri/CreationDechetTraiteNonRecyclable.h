#pragma once
#include "OperationTraitement.h"
#include "Compteur.h"

class CreationDechetTraiteNonRecyclable :
	public OperationTraitement
{
public:
	CreationDechetTraiteNonRecyclable(UsineTraitement* usineTraitement) : OperationTraitement(usineTraitement) {Compteur::ajouterConstructeur();};
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteNonRecyclable(dechet); return true; }
	virtual ~CreationDechetTraiteNonRecyclable() {Compteur::ajouterDestructeur();};
};
