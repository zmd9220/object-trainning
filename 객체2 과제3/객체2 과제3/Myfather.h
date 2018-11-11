#pragma once

#ifndef MYFATHER_H
#define MYFATHER_H
#include <iostream>
class MyFather {
protected:
	char* EyeColor;
	char* HairType;
	double FamSaving;
	int FamCar;
public:
	MyFather(char* eye, char* hair, long double saving, int car);
	~MyFather();
	char* ShowEyeColor();
	char* ShowHairType();
	long double FamilySaving();
	int FamilyCar();
};
class MyMother {
protected:
	char* EyeColor;
	char* HairType;
	int FamHouse;
public:
	MyMother(char*, char*, int);
	~MyMother();
	char* ShowMotherEye();
	char* ShowMotherHair();
	int FamilyHouse();
}; 
class MySelf : public MyFather {
	char* HairType;
	char* Education;
public:
	MySelf(char* hair, char* edu, MyFather mf) : MyFather(mf.ShowEyeColor(), mf.ShowHairType(), mf.FamilySaving(), mf.FamilyCar()) 
	{
		HairType = hair;
		Education = edu;
		std::cout << "--My data (derived/inherited class)--" << std::endl << "My hair: " << ShowMyHair() << std::endl
			<< "My family saving: USD" << FamilySaving() << std::endl << "My family car: " << FamilyCar() << " cars." << std::endl
			<< "My education: " << ShowMyEducation() << std::endl << std::endl;
	}
	~MySelf();
	char* ShowMyHair();
	char* ShowMyEducation();
};
class MySister : public MyFather, public MyMother {
	char* SisEye;
	float MonAllowance;
public:
	MySister(char* eye, float allow, MyFather mf, MyMother mm) : MyFather(mf.ShowEyeColor(), mf.ShowHairType(), mf.FamilySaving(), mf.FamilyCar()),
		MyMother(mm.ShowMotherEye(), mm.ShowMotherHair(), mm.FamilyHouse())
	{
		SisEye = eye;
		MonAllowance = allow;

		std::cout << "--My father's data (base class)--" << std::endl << "His eye: " << ShowEyeColor() << std::endl
			<< "His hair: " << ShowHairType() << std::endl << "Family Saving: USD" << FamilySaving() << std::endl
			<< "Family Car: " << FamilyCar() << " cars." << std::endl << std::endl;


		std::cout << "--My mother's data (base class)--" << std::endl << "Her eye: " << ShowMotherEye() << std::endl
			<< "Her hair: " << ShowMotherHair() << std::endl << "Our family house: " << FamilyHouse() << " houses." << std::endl << std::endl;

	}
	~MySister();
	char* ShowSisEye();
	float ShowSisAllownace();
};

#endif