#pragma once
#include "Operation.h"
class Operation2 :
	public Operation
{
public:
	Operation2(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	virtual~Operation2() {};
	bool effectuerOperation(Dechet* dechet) override { return dechet->getMateriel() == Dechet::PLASTIQUE; }

};
