﻿#pragma once
#include "Operation.h"
class Operation3 :
	public Operation
{
public:
	Operation3(Operation* operationSuivanteTrue, Operation* operationSuivanteFalse) :Operation(operationSuivanteTrue, operationSuivanteFalse) {};
	virtual ~Operation3() {};
	bool effectuerOperation(Dechet* dechet) const override { return (dechet->getMateriel() == Dechet::PAPIER | dechet->getMateriel() == Dechet::CARTON); }
};