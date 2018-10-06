#pragma once
#include "Operation.h"
class Operation1 :
	public Operation
{
public:
	Operation1(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	virtual ~Operation1() {};
	bool effectuerOperation(Dechet* dechet) const override { return (dechet->estEnStyromousse() | dechet->estRigide()); }
};
