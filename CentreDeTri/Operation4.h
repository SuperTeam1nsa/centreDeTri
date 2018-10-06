#pragma once
#include "Operation.h"
class Operation4 :
	public Operation
{
public:
	Operation4(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	virtual ~Operation4() {};
	bool effectuerOperation(Dechet* dechet) const override { return (dechet->getCouleur() == "brun" | dechet->getMateriel() == Dechet::NOURRITURE); }

};
