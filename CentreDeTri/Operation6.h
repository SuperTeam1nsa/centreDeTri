#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation6 :
	public Operation
{
public:
	Operation6(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {Compteur::ajouterConstructeur();};
	virtual ~Operation6() {};
	bool effectuerOperation(Dechet* dechet) const override {Compteur::ajouterDestructeur();
		return (dechet->getMateriel() == Dechet::PLASTIQUE &&
			(dechet->getType() == 0 || dechet->getType() == 6));
	}
};
