#pragma once

class Shape {
	static int gid;					// 객체를 디폴트 생성할때마다 고유번호를 부여한다

protected:							// Shape의 protected 멤버는
	int id;							// 자식 클래스에서는 private 멤버가 된다.

public:
	Shape() : id(++gid) { }

	virtual void draw() const = 0;
};

int Shape::gid{ 0 };

