#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation6 :
	public Operation
{
public:
	Operation6(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	virtual ~Operation6() { Compteur::ajouterDestructeur(); }
	virtual bool effectuerOperation(Dechet* dechet)  override {
		return (dechet->getMateriel() == Dechet::PLASTIQUE &&
			(dechet->getType() == 0 || dechet->getType() == 6));
	}
};
