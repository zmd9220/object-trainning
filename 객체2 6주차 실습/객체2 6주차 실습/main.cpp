#include <iostream>
#include "student.h"
#include "professor.h"
#include "inha personh.h"
#include "Class.h"
using namespace std;
//iterator ->  ������ ���� (ó������ ������?)begin
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
	//dynamic_cast = �θ�� ���� �ڽ��� ���� �� ������ ���ϴµ� ����ó�� �ϱ�����
	Jay.displayProfile();
}