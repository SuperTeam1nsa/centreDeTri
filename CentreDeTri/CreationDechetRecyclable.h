#pragma once
#include "OperationTraitement.h"
class CreationDechetRecyclable :
	public OperationTraitement
{
public:
	CreationDechetRecyclable(UsineTraitement* usineTraitement) : OperationTraitement(usineTraitement) {};
	CreationDechetRecyclable() {};
	bool effectuerOperation(Dechet* dechet) override { creerDechetTraiteRecyclable(dechet); return true; }
	virtual ~CreationDechetRecyclable() {};
};
