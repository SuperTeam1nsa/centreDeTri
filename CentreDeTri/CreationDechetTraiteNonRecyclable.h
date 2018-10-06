#pragma once
#include "OperationTraitement.h"
class CreationDechetTraiteNonRecyclable :
	public OperationTraitement
{
public:
	CreationDechetTraiteNonRecyclable(UsineTraitement* usineTraitement) : OperationTraitement(usineTraitement) {};
	CreationDechetTraiteNonRecyclable() {};
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteNonRecyclable(dechet); return true; }
	virtual ~CreationDechetTraiteNonRecyclable() {};
};
