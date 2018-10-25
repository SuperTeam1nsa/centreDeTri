#pragma once
#include "Operation.h"
#include "Compteur.h"

class Operation1 :
	public Operation
{
public:
	Operation1(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {
		Compteur::ajouterConstructeur();
	}
	virtual ~Operation1() { Compteur::ajouterDestructeur(); }
	virtual bool effectuerOperation(Dechet* dechet)  override { return (dechet->estEnStyromousse() || dechet->estRigide()); }
};
