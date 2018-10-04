#pragma once
#include "Dechet.h"
class DechetTraite :
	public Dechet
{
public:
	DechetTraite(Dechet* dechet);
	DechetTraite();
	~DechetTraite();
	Dechet getDechet() const;
};

