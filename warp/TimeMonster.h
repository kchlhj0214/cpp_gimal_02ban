//-----------------------------------------------------------------------------
// TimeMonster.h
//
// 특수기 - mSec 시간만큼 CPU를 멈춘다
//-----------------------------------------------------------------------------

#pragma once

#include "Monster.h"

class TimeMonster : public Monster {
	int mSec;							// CPU를 멈추는 시간 단위는 milli second

public:
	TimeMonster( int n ) : mSec( n ) 
	{

	}

	virtual void special() override;
};

