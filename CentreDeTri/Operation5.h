#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation5 :
	public Operation
{
public:
	Operation5(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	virtual ~Operation5() { Compteur::ajouterDestructeur(); }
	bool effectuerOperation(Dechet* dechet)  override { return (dechet->getCouleur() == "vert") | (dechet->getMateriel() == Dechet::VEGETAL); }

};
