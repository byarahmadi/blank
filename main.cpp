#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>
#include <stack>
#include "Program.h"
#include "Instruction.h"


using namespace std;



										   
										   
int main(int argc,char *argv[]) {
	
//	Instruction inst0(0,"READ");
        string filename = "example.class";
        Program *program = new Program(filename);
        program->print();	
        program->run();	
	return 0;
	
}
