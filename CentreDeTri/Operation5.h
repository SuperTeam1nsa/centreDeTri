#pragma once
#include "Operation.h"
class Operation5 :
	public Operation
{
public:
	Operation5(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	virtual ~Operation5() {};
	bool effectuerOperation(Dechet* dechet) const override { return (dechet->getCouleur() == "vert" | dechet->getMateriel() == Dechet::VEGETAL); }

};
