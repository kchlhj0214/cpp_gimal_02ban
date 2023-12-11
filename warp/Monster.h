//-----------------------------------------------------------------------------
// Monster.h
//
// 모든 Monster의 부모 클래스이다.
// Monster는 자신만의 특수기술을 갖는다
//-----------------------------------------------------------------------------

#pragma once

class Monster {

protected:							// 자식 클래스는 protected 멤버를 자신의 private 멤버로 사용할 수 있다.
	int id;							// 생성된 모든 몬스터에 붙는 id
										
public:
	Monster();
	~Monster();

	virtual void special() = 0;		// 특수기술
};

