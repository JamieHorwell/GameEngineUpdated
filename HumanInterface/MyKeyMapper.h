#pragma once
#include "AbstractKeyMapper.h"

class MyKeyMapper : public AbstractKeyMapper
{
public:
	MyKeyMapper();
	~MyKeyMapper();

	 int getAction(int key) const;

};



