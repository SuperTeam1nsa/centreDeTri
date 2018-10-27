#pragma once
#include "Operation.h"
#include "Compteur.h"


class Operation4 :
	public Operation
{
public:
	Operation4(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	virtual ~Operation4() { Compteur::ajouterDestructeur(); }
	bool effectuerOperation(Dechet* dechet)  override {
		return (dechet->getCouleur() == "brun") &&
			(dechet->getMateriel() == Dechet::NOURRITURE);
	}

};
