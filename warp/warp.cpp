#include <iostream>
#include <stdio.h>
#include <fstream>
#include <format>
#include <random>
#include "Monster.h"
#include "MemoryMonster.h"
#include "ScreenMonster.h"
#include "TimeMonster.h"
using namespace std;

extern default_random_engine dre;

void SPECIAL(Monster* a)
{
	if (dynamic_cast<MemoryMonster*>(a) != nullptr) {
		a->special();
		a->special();
	}
}

int main()
{
	// Monster를 생성할 때 이용할 랜덤값
	uniform_int_distribution<> uiTime(1, 9);
	uniform_int_distribution<> uiMemory(22, 50);
	uniform_int_distribution<> uiScreen(11, 66);
	uniform_int_distribution<> uiThree(0, 2);


	// 문제의 그림과 같이 프로젝트를 만들었다면 다음 코드가 문제없이 실행될 것이다. 
	// 실행시켜 보자.
	// [생성 예] 자식 Monster를 생성할 때 생성자의 인자로 랜덤값을 주어 생성한다.
	{
		// 각 자식 Monster를 한 개 생성하였다
		TimeMonster timeMonster(uiTime(dre));
		MemoryMonster memoryMonster(uiMemory(dre));
		ScreenMonster screenMonster(uiScreen(dre));

		// 생성한 Monster의 special 멤버를 호출하였다
		// 화면 출력결과는 옆의 주석문과 같다

		timeMonster.special();			// [1] : CPU 정지 - 426ms
		memoryMonster.special();		// [2] : 값++
		screenMonster.special();		// [3] : 문자-- > hFEbDjtnZmhSSFHzegQUfXzbRiops
		screenMonster.special();		// [3] : 문자-- > haIxuqtzgiOcRTyKCGWiokTSgJZxu

		cout << endl;
		cout << "MemoryMonster의 메모리 값을 출력해 보았다" << endl;
		memoryMonster.show();			// 메모리 값 출력, MemoryMonster의 값은 따로 출력해 볼 수도 있다.
	}
	
	//------------------------------------------------------------------
	// [문제 1]

	ifstream in{ "소문자들1.txt" };
	int num{ };

	char a{};

	while (in >> a)
	{
		if (a == 'm')
			++num;
	}

	cout << "m의 개수 : " << num << endl;

	//------------------------------------------------------------------
	// [문제 2]

	Monster** monsters = new Monster * [num] {};

	//------------------------------------------------------------------
	// [문제 3]

	for (int i = 0; i < num; ++i) {
		int sel = uiThree(dre);			
	
		switch (sel) {
		case 0:
			monsters[i] = new TimeMonster(uiTime(dre));
			break;

		case 1:
			monsters[i] = new MemoryMonster(uiMemory(dre));
			break;

		case 2:
			monsters[i] = new ScreenMonster(uiScreen(dre));
			break;
		default :
			break;
		}
	}

	//------------------------------------------------------------------

	cout << endl;
	cout << "-------------------------------------" << endl;
	cout << "[문제 4] special() 멤버를 호출한 결과" << endl;
	cout << "-------------------------------------" << endl;

	//------------------------------------------------------------------
	// [문제 4]

	for (int i = 0; i < num; ++i) {
		monsters[i]->special();
	}

	//------------------------------------------------------------------

	cout << endl;
	cout << " - MemoryMonster라면 special 함수를 2번 호출한다 -" << endl;
	cout << endl;

	//------------------------------------------------------------------
	// [문제 5]

	for (int i = 0; i < num; ++i)
		SPECIAL(monsters[i]);

	//for (int i = 0; i < num; ++i)
	//	SPECIAL(monsters[i]);

	//------------------------------------------------------------------

	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "[문제 6] 첫째 Monster를 삭제하고 나서 special() 멤버를 호출한 결과" << endl;
	cout << "------------------------------------------------------------------" << endl;

	//------------------------------------------------------------------
	// [문제 6]

	Monster** tmp = new Monster * [num-1] {};

	for (int i = 0; i < num; ++i) {
		tmp[i] = monsters[i + 1];
	}
	delete[] monsters;

	monsters = tmp;

	for (int i = 0; i < num-1; ++i) {
		monsters[i]->special();
	}

	//------------------------------------------------------------------
	// [문제 7]

	for (int i = 0; i < num; ++i)
		delete monsters[i];

	delete[] monsters;

	//------------------------------------------------------------------

}