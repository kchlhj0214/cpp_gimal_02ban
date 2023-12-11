//-----------------------------------------------------------------------------
// MemoryMonster.h
//
// 특수기 - 확보한 num 바이트 메모리의 값을 바이트 마다 1증가 시킨다.
// show() - 메모리의 값을 화면에 출력한다
//-----------------------------------------------------------------------------
#pragma once

#include "Monster.h"

class MemoryMonster : public Monster {
	int num;							// 단위는 milli second
	char* p;

public:
	MemoryMonster( int n );
	~MemoryMonster();

	virtual void special() override;

	void show() const;					// 메모리의 내용을 화면 출력한다
};


