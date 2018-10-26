#include <iostream>
#include "student.h"
#include "professor.h"
#include "inha personh.h"
#include "Class.h"
using namespace std;
//iterator ->  벡터의 순서 (처음부터 끝까지?)begin
int main()  
{	
	inhaPerson hi(123, "hi", "home");
	professor Tamer(12, "Tamer", "99 Cambridge st.", 3, 3000);
	Student Jay(911923, "Jay", "Philippines", 18, 24);
	hi.displayProfile();
	Tamer.displayProfile();
	Jay.displayProfile();
	Class eng(100, "eng");
	Class* e1 = &eng;
	Jay.addClassTaken(e1);
	//dynamic_cast = 부모는 원래 자식의 값을 다 가지지 못하는데 에러처리 하기위함
	Jay.displayProfile();
}