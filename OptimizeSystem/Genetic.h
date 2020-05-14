#pragma once
#include "importantOptimizeStructs.h"
#include <iostream>
#include <random>

enum chooseValueForGenerationMode { randomMode, cleverSamplingMode, normalDistributionMode, normalDistributionDefaultMode};

struct structToBuildGeneration
{
	public:
	structToBuildGeneration();
	~structToBuildGeneration();

	// surface number
	unsigned int getSurfaceNumber();
	void setSurfaceNumber(unsigned int surfaceNum);

	// kind parameter var
	kindParaOptSys getKindPara();
	void setKindPara(kindParaOptSys kindPara);

	// value
	real getValue();
	void setValue(real value);

	// copy
	void copy(structToBuildGeneration strctToBuildGene);


private:
	unsigned int mSurfaceNum;
	kindParaOptSys mKindParaVar;
	real mValue;
};

struct defaultParaGenetic
{
public:
	defaultParaGenetic();
	~defaultParaGenetic();

	// start refractiv index
	real getStartRefIndex();
	void setStartRefIndex(unsigned int startRefIndex);
	// tolerance withoutMin
	real getToleranceWithoutMIN_Radius();
	void setToleranceWithoutMIN(real tolWithoutMIN);
	// tolerance withoutMax
	real getToleranceWithoutMAX_Radius();
	void setToleranceWithoutMAX(real tolWithoutMAX);
	// max iteration genetic
	unsigned int getMaxInterationsGenetic();
	void setMaxInterationGenetic(unsigned int maxIterations);
	// merit value stop
	real getDeltaMeritValueStop();
	void setDeltaMeritValueStop(real meritValueStop);
	// tolerance for evaluation
	real getToleranceForEvaluatiion();
	void setToleranceForEvaluation(real toleranceForEvalu);
	// choose value mode
	chooseValueForGenerationMode getChooseValueMode();
	void setChooseValueMode(chooseValueForGenerationMode chooseMode);


private:
	real mStartRefractivIndex{};
	real mToleranceWithoutMIN;
	real mToleranceWithoutMAX;
	unsigned int mMaxIterations;
	real mDeltaMeritValueStop;
	real mToleranceForEvaluation;
	chooseValueForGenerationMode mChooseValueMode;

};

struct normalDistributionStruct
{
public:
	normalDistributionStruct();
	~normalDistributionStruct();

	// mean to calc normal distribution
	real getMeanToCalcND();
	void setMeanToCalcND(real mean);
	// stddev to calc normal distribution
	real getStddevToCalcND();
	void setStddevToCalcND(real stddev);

private:
	real mMean_ToCalcNormalDistribution;
	real mStddev_ToCalcNormalDistribution;
	
};

struct withOutMinMax
{
public:

	withOutMinMax();
	~withOutMinMax();
	
	// without min
	real getWithoutMin_Radius();
	void setWithoutMin_Radius(real withoutMin);

	// without max
	real getWithoutMax_Radius();
	void setWithoutMax_Radius(real withoutMax);

private:
	real mWithOutMin_Radius;
	real mWithOutMax_Radius;
};

class Genetic
{
public:
	Genetic();
	Genetic(OpticalSystemElement /*optSysEle*/ optSysEle, std::vector<VectorStructR3> /*fields*/ fields, std::vector<real> /*wavelengths*/ wavelengths, unsigned int /*rings*/ rings, unsigned int /*arms*/ arms, unsigned int /*populatuion*/ population);
	~Genetic();

	void buildOptSys_LLT_wave_vec();
	real calcMeritVal();
	real calculateMeritVal_RMS(const VectorStructR3& fieldPoint);
	void resizeAllRelevantStdVectorsAndCalcConst();
	void loadDefaultPra();

	// randomize a number between min and max 
	real randomNumberReal(real min, real max);

	// clever sampling to build optical system
	real getCleverSampledNumber(real min, real max);

	// normal distribution
	real normalDistribution(real mean, real stddev, real min, real max);

	// default normal distribution
	real defaultNormalDistribution(real min, real max);

	// get value to build optical system
	real getNumberToBuildOptSys(real min, real max);

	// resize vector to build generations
	void resizeVecToBuildGenerations();

	// generate values for generations
	void generateValuesFor_FIRST_Generations();

	// load without min and Max default
	void loadWithoutMinMaxDefault_Radius();

	// check if radisu is valide
	real checkValueRadius(real val, real min, real withoutMin, real max, real withoutMax);

	// build the generations and evaluate
	void buildTheGenerationsAndEvaluate();

	// change radius to value
	void changeRadiusToValue(unsigned int surfaceNum, real value);

	// change radius to value and flip direction
	void changeRadiusAndFlipDierction(unsigned int surfaceNum, real value);

	// change thickness surface to
	void changeThickness_Z_SurfaceTo(unsigned int surfaceNo, real newThickness);

	// do the genetic process
	void doTheGeneticProcess();

	// find best system
	void findBestSystemNum();

	// select system in generation
	unsigned int selectSystemInGeneration();

	// genetic process
	void geneticProcess(unsigned int selectetSystemNum, unsigned int number);

	// set evaluate system false
	void setEvaluateSystemFalse();

	// check while loop for genetic
	bool checkWhileGenetic(unsigned int iteration);

	// calculat fitness value
	void calcFitnessValAndSum();

	// check if system has to be evaluated
	bool checkEvaluateSystem(unsigned int systemNumber, unsigned int variableNum);

	// get optimized optical system element
	OpticalSystemElement getOptimizedOpticalSystemElement();

	// build the optical system
	void buildTheOpticalSystem(unsigned int generationNum);

	void loadThicknessParameter();

	// ***
	// mean to calc normal distribution
	real getMeanToCalcND();
	void setMeanToCalcND(real mean);
	// stddev to calc normal distribution
	real getStddevToCalcND();
	void setStddevToCalcND(real stddev);
	// ***

	// ***
	// start refractiv index
	real getStartRefIndex();
	void setStartRefIndex(unsigned int startRefIndex);
	// tolerance withoutMin
	real getToleranceWithoutMIN_Radius();
	void setToleranceWithoutMIN_Radius(real tolWithoutMIN);
	// tolerance withoutMax
	real getToleranceWithoutMAX_Radius();
	void setToleranceWithoutMAX_Radius(real tolWithoutMAX);
	// max iteration genetic
	unsigned int getMaxInterationsGenetic();
	void setMaxInterationGenetic(unsigned int maxIterations);
	// merit value stop
	real getDeltaMeritValueStop();
	void setDeltaMeritValueStop(real meritValueStop);
	// tolerance for evaluation
	real getToleranceForEvaluatiion();
	void setToleranceForEvaluation(real toleranceForEvalu);
	// choose value mode
	chooseValueForGenerationMode getChooseValueMode();
	void setChooseValueMode(chooseValueForGenerationMode chooseMode);
	// ***

private:
	OpticalSystemElement mOpticalSystemEle_initial;
	std::vector<VectorStructR3> mFields_vec;
	std::vector<real> mWavelength_vec;
	unsigned int mRings;
	unsigned int mArms;
	unsigned int mPopulation;

	//std::vector<OpticalSystem_LLT> mOptSys_LLT_vec{};
	std::vector<OpticalSystem_LLT> mChangedOptSys_LLT_vec{};
	unsigned int mNumOptSys{};

	parameterVar mParameterVar{};

	unsigned int mSizeOptSys;
	unsigned int mPosLastSurface{};
	std::vector<unsigned int> mWeightWavelenght_vec{};
	std::vector<real> mWeightFields_vec{};
	unsigned int mNumFieldPoints;
	Light_LLT mDefaultLight{};
	unsigned int mNumVar{};
	
	defaultParaGenetic mDefaultParaGenetic{};

	std::vector<bool> mEvaluateSystem;
	std::vector<real> mAllMeritVal;
	std::vector<real> mAllFitnessVal;
	std::vector<real> mSaveAllBestMeritValues;
	real mMeritVal_bestSystem;
	real mSumAllFitnessVal;
	std::vector<std::vector<structToBuildGeneration>> mFirstGenerationVec;
	std::vector<std::vector<structToBuildGeneration>> mSecondGenerationVec;

	std::vector<withOutMinMax> mWithoutMinMax_Radius;
	unsigned int mNumBestOptSysInGeneration{};

	std::vector<structToBuildGeneration> mTempStructToBuildGeneration_vec;
	
	OpticalSystemElement mOptimizedOpticalSytemElement;

	std::vector<bool> mCheckToEvaluateVec;

	std::vector<real> mThickness_vec;

	VectorStructR3 mNewPosition{};

	normalDistributionStruct mNormalDistribution;
	std::normal_distribution<real> mDistribution;
	std::default_random_engine mGenerator;
};

