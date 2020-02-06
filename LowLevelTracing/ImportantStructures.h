﻿#pragma once
#include "..\basicdefinition\basicdefinitions.h"
#include <math.h>
#include "..\LowLevelTracing\Light_LLT.h"



struct Matrix3x3AndExist
{
	real Matrix[3][3];

	//TODOQuestio: Warum tut sowas nicht und ich muss die Funktion saveMatrix bzw. getMatrix verwenden???
	//real check[3][3] = Matrix[3][3];

	int ExistMatrix;

	// save the matrix in the struct
	// hier könnte auch die Funktion "std::memcpy" verwendet werden!
	void saveMatrix(real const mat[3][3]);

	// get the matrix from the struct
	void getMatrix(real mat[3][3]);

};


struct VectorStructR3
{
	real x;
	real y;
	real z;

	/*Vector()
	: X( 0.0 )
	, Y( 0.0 )
	, Z( 0.0 )
	{}

	Vector(double _x, double _y, double _z)
	: X{ _x }
	, Y{ _y }
	, Z{ _z }
	{}*/

	void print() const;


	// set X
	void setX(real const& X_set);
	// get X
	double getX() const&;
	// set Y
	void setY(real const& Y_set);
	// get Y
	double getY() const&;
	//set Z;
	void setZ(real const& Z_set);
	//get Z
	double getZ() const&;
};

enum surfaceSide {A ,B, N};



struct IntersectInformationStruct 
{
	IntersectInformationStruct();
	~IntersectInformationStruct();
	IntersectInformationStruct(VectorStructR3 mIntersectionPoint, VectorStructR3 mNormaleUnitVector, surfaceSide mSurfaceSideABN,
		real mStepsToWalk, real mRefractiveIndexA, real mRefractiveIndexB, VectorStructR3 mDirectionRayUnit, Light_LLT mLight);


	// set intersection point
	void setIntersectionPoint(VectorStructR3 const& interPoint);
	// get intersection point
	VectorStructR3 getIntersectionPoint() const&;
	// set normal unit vector
	void setNormalUnitVector(VectorStructR3 const& NormalUnitVector);
	// get normal unit vector
	VectorStructR3 getNormalUnitVector() const&;
	// set surface side
	void setSurface(surfaceSide const& surSid);
	// get surface side
	char getSurfaceSide() const&;
	// set steps to walk
	void setStepsToWalk(real const& steps);
	// get steps to walk
	real getStepsToWalk() const&;
	// set refractive index side A
	void setRefractiveIndex_A(real refractiveIndex);
	// get refractive index side A
	real getRefractiveIndex_A() const&;
	// set refractive index side B
	void setRefractiveIndex_B(real refractiveIndex);
	// get refractive index side B
	real getRefractiveIndex_B() const&;
	// set direction ray unit
	void setDirectionRayUnit(VectorStructR3 const& direction);
	// get direction ray unit
	VectorStructR3 getDirectionRayUnit() const&;
	// set light
	void setLight(const Light_LLT light);
	// get Light
	Light_LLT getLight() const&;



	// print intersect information
	void printIntersectInformation() const&;


	// calculate unit vector
	VectorStructR3 unitVectorForIntersectInfoStruct(VectorStructR3 const& V);

public:
	VectorStructR3 mIntersectionPoint;
	VectorStructR3 mNormaleUnitVector;
	surfaceSide mSurfaceSideABN; // A or B -> if N -> there is NO intersection point!
	real mStepsToWalk;
	real mRefractiveIndexA;
	real mRefractiveIndexB;
	VectorStructR3 mDirectionRayUnit;
	Light_LLT mLight;
	
	// TODO: write functions gethitPoint, sethitPoint,...
};


struct pointAndIntensity
{
	pointAndIntensity();
	~pointAndIntensity();

	pointAndIntensity(VectorStructR3 /*intersection point*/ const& point, real /*intensity*/ const& intensity);

	//get point
	VectorStructR3 getPoint() const&;
	// set point
	void setPoint(VectorStructR3 const& setPoint);
	//get intesity
	real getIntensity() const&;
	//set intesity
	void setIntesity(real const& setIntensity);

private:
	VectorStructR3 mPoint;
	real mIntensity;

};

// We use this struct primary for ray aiming
struct VectorElementAndPosition
{
	double value;
	unsigned int posInVector;

	//get value in vector
	double getValue() const&;
	//get position in vector
	unsigned int getPosInVector() const&;

};

struct VectorStructR2
{
	real x;
	real y;

	// set X
	void setX(real const& X_set);
	// get X
	double getX() const&;
	// set Y
	void setY(real const& Y_set);
	// get Y
	double getY() const&;

};