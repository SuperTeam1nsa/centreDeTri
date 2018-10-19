#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation3 :
	public Operation
{
public:
	Operation3(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	virtual ~Operation3() { Compteur::ajouterDestructeur(); }
	bool effectuerOperation(Dechet* dechet) override { return (dechet->getMateriel() == Dechet::PAPIER) | (dechet->getMateriel() == Dechet::CARTON); }
};
