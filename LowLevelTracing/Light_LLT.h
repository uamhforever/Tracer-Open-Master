#pragma once
#include "JonesVector.h"

// Difference light types
enum typeLight { typeLightRay, typeWaveScalar, typeWaveVectorial, typeGaussian };

class Light_LLT {
public: Light_LLT() {};
		Light_LLT(double wavelength, double intensity, JonesVector_LLT polarisation, typeLight lightType, int isAlive) :
			mWavelength(wavelength),
			mIntensity(intensity),
			mPolarisation(polarisation),
			mLightType(lightType),
			mIsAlive(isAlive)
		{}
		~Light_LLT() {};

		// set light_LLT
		void set(Light_LLT light_LLT);

		// get wavelength
		double getWavelength() const&;
		// set wavelength
		void setWavelength(double const& wavelength);

		// get intensity 
		double getIntensity();
		// set intensity
		void setIntensity(double intensity);
		// get jones vector
		JonesVector_LLT getJonesVector();
		// set jones vector
		void setJonesVector(JonesVector_LLT jonesVector);
		//get light type
		typeLight getTypeLight();
		//set light type
		void setTypeLight(typeLight lightType);
		// is light alive
		int isAlive();
		// set light alive
		void setIsAlive(int isAlive);

		

private:
	double mWavelength;
	double mIntensity;
	JonesVector_LLT mPolarisation;
	typeLight mLightType;
	int mIsAlive;

};