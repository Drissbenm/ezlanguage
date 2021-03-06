//@author : ELFAQIR Ismail
#include "Conditionnal_instruction.h"
#include <iostream>
using namespace std;
/*s
Conditionnal_instruction::Conditionnal_instruction():instructions() {
	name= "Conditionnal instruction";
}
*/
Conditionnal_instruction::Conditionnal_instruction(const vector< vector<Instruction> >& inst,
										           const vector<Condition> &c,
												   int ct
												   ):instructions(inst),conditions(c),condition_type(ct) 
{
	name= "Conditionnal instruction";
}

// copy constructor
Conditionnal_instruction::Conditionnal_instruction(const Conditionnal_instruction &c) 
	::instructions(c.instructions),conditions(c.conditions),condition_type(c.condition_type){
	name= "Conditionnal instruction";	
}

// geter for the conditions
const vector<Condition> & Conditionnal_instruction::get_conditions() const {
	return conditions;
}

// geter for the instruction(s)
const vector< vector<Instruction> > & Conditionnal_instruction::get_instructions() const{
	return instructions;
}

// translate to bloc if in c++
std::string Conditionnal_instruction::translate() {
	
	string res="";
	
	switch (condition_type) {
		case CIf || CIfElse :  
			res+="if("+conditions[0].translate()+")"; // in this case vector of conditions has only one condition 
			res+="{";
			for(int i=0;i<instructions[0].size();i++) { // in this case vector of instructions has only the instructions of (if) 
				// here \t and \n for the view of the code c++
				res+="\t"+instructions[0][i].translate(); 
				res+="\n";
			}
			res+="\n";
			res +="}"; 						
			break;
			
		case CIfElse :
			res+="else"; // in this case vector of conditions has only one condition 
			res+="{";
			for(int i=0;i<instructions[1].size();i++) { // instructions[0] for the bloc (if) and instructions[1] for the bloc (else) 
				// here \t and \n for the view of the code c++
				res+="\t"+instructions[1][i].translate(); 
				res+="\n";
			}
			res+="\n";
			res +="}"; 			
			break;
			
		case CWhen :
			// here the left_son normally has the variable that we were willing to compare
			res+="switch("+this->left_son+")"; 
			res+="{";
				for(int i=0;i<conditions.size();i++){
					res+="\tcase "+conditions[i].translate()+" :\n";
					for(int j=0;j<instructions[i].size();j++) {
						res+="\t\t"+instructions[i][j].translate()+"\n";
					}
					res+="\t\tbreak;\n";
				}
			// if the size instructions > size of conditions then we have a default case
			if(instructions.size()>conditions.size()) {
				res+="\tdefault :\n";
					for(int i=0;i<instructions[instructions.size()-1].size();i++) {
						res+="\t\t"+instructions[instructions.size()-1][i].translate()+"\n";
					}
				res+="\t\tbreak;\n";
			}
			res +="}"; 	
			break;
				
			
	}
	
	return res;
}
