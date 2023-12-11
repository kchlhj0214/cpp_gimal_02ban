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
	// Monster�� ������ �� �̿��� ������
	uniform_int_distribution<> uiTime(1, 9);
	uniform_int_distribution<> uiMemory(22, 50);
	uniform_int_distribution<> uiScreen(11, 66);
	uniform_int_distribution<> uiThree(0, 2);


	// ������ �׸��� ���� ������Ʈ�� ������ٸ� ���� �ڵ尡 �������� ����� ���̴�. 
	// ������� ����.
	// [���� ��] �ڽ� Monster�� ������ �� �������� ���ڷ� �������� �־� �����Ѵ�.
	{
		// �� �ڽ� Monster�� �� �� �����Ͽ���
		TimeMonster timeMonster(uiTime(dre));
		MemoryMonster memoryMonster(uiMemory(dre));
		ScreenMonster screenMonster(uiScreen(dre));

		// ������ Monster�� special ����� ȣ���Ͽ���
		// ȭ�� ��°���� ���� �ּ����� ����

		timeMonster.special();			// [1] : CPU ���� - 426ms
		memoryMonster.special();		// [2] : ��++
		screenMonster.special();		// [3] : ����-- > hFEbDjtnZmhSSFHzegQUfXzbRiops
		screenMonster.special();		// [3] : ����-- > haIxuqtzgiOcRTyKCGWiokTSgJZxu

		cout << endl;
		cout << "MemoryMonster�� �޸� ���� ����� ���Ҵ�" << endl;
		memoryMonster.show();			// �޸� �� ���, MemoryMonster�� ���� ���� ����� �� ���� �ִ�.
	}
	
	//------------------------------------------------------------------
	// [���� 1]

	ifstream in{ "�ҹ��ڵ�1.txt" };
	int num{ };

	char a{};

	while (in >> a)
	{
		if (a == 'm')
			++num;
	}

	cout << "m�� ���� : " << num << endl;

	//------------------------------------------------------------------
	// [���� 2]

	Monster** monsters = new Monster * [num] {};

	//------------------------------------------------------------------
	// [���� 3]

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
	cout << "[���� 4] special() ����� ȣ���� ���" << endl;
	cout << "-------------------------------------" << endl;

	//------------------------------------------------------------------
	// [���� 4]

	for (int i = 0; i < num; ++i) {
		monsters[i]->special();
	}

	//------------------------------------------------------------------

	cout << endl;
	cout << " - MemoryMonster��� special �Լ��� 2�� ȣ���Ѵ� -" << endl;
	cout << endl;

	//------------------------------------------------------------------
	// [���� 5]

	for (int i = 0; i < num; ++i)
		SPECIAL(monsters[i]);

	//for (int i = 0; i < num; ++i)
	//	SPECIAL(monsters[i]);

	//------------------------------------------------------------------

	cout << endl;
	cout << "------------------------------------------------------------------" << endl;
	cout << "[���� 6] ù° Monster�� �����ϰ� ���� special() ����� ȣ���� ���" << endl;
	cout << "------------------------------------------------------------------" << endl;

	//------------------------------------------------------------------
	// [���� 6]

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
	// [���� 7]

	for (int i = 0; i < num; ++i)
		delete monsters[i];

	delete[] monsters;

	//------------------------------------------------------------------

}