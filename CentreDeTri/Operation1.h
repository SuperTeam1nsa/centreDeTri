#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation1 :
	public Operation
{
public:
	Operation1(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {Compteur::ajouterConstructeur();};
	virtual ~Operation1() {Compteur::ajouterDestructeur();};
	bool effectuerOperation(Dechet* dechet) const override { return (dechet->estEnStyromousse() | dechet->estRigide()); }
};
