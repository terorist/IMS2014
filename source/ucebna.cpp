#include <iostream>
#include "libsim/libsim.h"

Store* pocitace = new Store("pocitace", 10);

class Student : public Event{
public:
	void Behavior();
}; 

class StudentPrichod : public Event{
public:
	void Behavior();
};

class MaPocitac : public Event{
public:
	void Behavior();
};

class OpoustiPocitac : public Event{
public:
	void Behavior();
};

void Student::Behavior(){  
	(new StudentPrichod)->Activate();
	//this->Activate(Exponential(10));
	(new Student)->Activate(Exponential(10));
}

void StudentPrichod::Behavior(){
	if (pocitace->Full()){
		//40%
		if (Random() > 0.6){
			if(Random() > 0.2){
				return;		//odesel a nevrati se 
			} else {
				//this->Activate(Uniform(30,60));	//odesel, vrati se
				(new StudentPrichod)->Activate(Uniform(30,60));   //odesel, vrati se
			}
		}else{
			pocitace->Enter(new MaPocitac);

		}
	}else{
		pocitace->Enter(new MaPocitac);
	}
}
void MaPocitac::Behavior(){
	(new OpoustiPocitac)->Activate(Exponential(100));
}
void OpoustiPocitac::Behavior(){
	pocitace->Leave();
}

int main(){
	init(0, 1000000);
	(new Student)->Activate();
	run();
	pocitace->PrintStats();
	
	endSimulation();
	delete pocitace;
}
