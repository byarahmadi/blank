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
	
    if (argc != 2) {
       cerr<<endl<<"Arguments to the program must be well specified!"<<endl;
       return 11;
    }
    string filename = argv[1];
    Program *program = new Program(filename);
//    program->print();	
    program->run();	
    return 0;
	
}
