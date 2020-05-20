#include <iostream>
#include "Myfather.h"

using namespace std;




MyFather::MyFather(char* eye, char* hair, long double saving, int car) 
{
	EyeColor = eye;
	HairType = hair;
	FamSaving = saving;
	FamCar = car;
	//cout << "--My father's data (base class)--" << endl << "His eye: " << ShowEyeColor() << endl
	//	<< "His hair: " << ShowHairType() << endl << "Family Saving: USD" << FamilySaving() << endl
	//	<< "Family Car: " << FamilyCar() << " cars." << endl << endl;
}
MyFather::~MyFather() {}
	char* MyFather::ShowEyeColor()
	{
		return EyeColor;
	}
	char* MyFather::ShowHairType()
	{
		return HairType;
	}
	long double MyFather::FamilySaving()
	{
		return FamSaving;
	}
	int MyFather::FamilyCar()
	{
		return FamCar;
	}




	MyMother::MyMother(char* eye, char* hair, int house) 

	{
		EyeColor = eye;
		HairType = hair;
		FamHouse = house;
	//	cout << "--My mother's data (base class)--" << endl << "Her eye: " << ShowMotherEye() << endl
	//		<< "Her hair: " << ShowMotherHair() << endl << "Our family house: " << FamilyHouse() << " houses." << endl << endl;

	} 
	MyMother::~MyMother()
	{

	}
	char* MyMother::ShowMotherEye()
	{
		return EyeColor;
	}
	char* MyMother::ShowMotherHair()
	{
		return HairType;
	}
	int MyMother::FamilyHouse()
	{
		return FamHouse;
	}


	//MySelf::MySelf(char* hair, char* edu, MyFather mf) : MyFather(mf.ShowEyeColor(), mf.ShowHairType(), mf.FamilySaving(), mf.FamilyCar())

	MySelf::~MySelf() { }
	char* MySelf::ShowMyHair()
	{
		return HairType;
	}
	char* MySelf::ShowMyEducation()
	{
		return Education;
	}



	//MySister::MySister(char* eye, float allow, MyFather mf, MyMother mm) : MyFather(mf.ShowEyeColor(),mf.ShowHairType(),mf.FamilySaving(),mf.FamilyCar()),
		//MyMother(mm.ShowMotherEye(),mm.ShowMotherHair(),mm.FamilyHouse())

	MySister::~MySister() 
	{
		std::cout << "--My sister's data (derived/inherited class)--" << std::endl << "Her eye: " << ShowSisEye() << std::endl
			<< "Our family saving: USD" << FamilySaving() << std::endl << "Our family car: " << FamilyCar() << " cars." << std::endl
			<< "Our family house: " << FamilyHouse() << " houses." << std::endl
			<< "Her monthly allowances: USD" << ShowSisAllownace() << std::endl;
	}

	char* MySister::ShowSisEye()
	{
		return SisEye;
	}
	float MySister::ShowSisAllownace()
	{
		return MonAllowance;
	}
