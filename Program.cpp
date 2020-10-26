
#include "Program.h"
#include "Instruction.h"
#include <vector>

using namespace std;

void Program::run() {
    int PC = 0;
    while (PC < instructions.size()) {
       PC = instructions[PC]->execute(eval_stack);
    }
    
}
void Program::print() {
    for (int i = 0; i < instructions.size(); ++i) {
       cout<<instructions[i]->getOpcode()<<" ";
    }
}
Instruction *Program::getInstruction(vector<string> tokens) {
   if (tokens[1] == "READ")
     return new READ(this,stoi(tokens[0]),"READ");
   else if (tokens[1] == "WRITE")
     return new WRITE(this,stoi(tokens[0]),"WRITE");
   else if (tokens[1] == "DUP")
     return new DUP(this,stoi(tokens[0]),"DUP");
   else if (tokens[1] == "MUL")
     return new MUL(this,stoi(tokens[0]),"MUL");
   else if (tokens[1] == "ADD")
     return new ADD(this,stoi(tokens[0]),"ADD");
   else if (tokens[1] == "SUB")
     return new SUB(this,stoi(tokens[0]),"SUB");
   else if (tokens[1] == "GT")
     return new GT(this,stoi(tokens[0]),"GT");
   else if (tokens[1] == "LT")
     return new LT(this,stoi(tokens[0]),"LT");
   else if (tokens[1] == "EQ")
     return new EQ(this,stoi(tokens[0]),"EQ");
   else if (tokens[1] == "JMPZ")
     return new JMPZ(this,stoi(tokens[0]),"JMPZ");
   else if (tokens[1] == "PUSH")
     return new PUSH(this,stoi(tokens[0]),"PUSH",stoi(tokens[2]));
   else if (tokens[1] == "POP")
     return new POP(this,stoi(tokens[0]),"POP",stoi(tokens[2]));
   else if (tokens[1] == "ROT")
     return new ROT(this,stoi(tokens[0]),"ROT",stoi(tokens[2]));
}
Program::Program(string filename) {
    asmfile.open(filename);
    parse();
    asmfile.close();
}
int Program::parse() {
    string delimiter = " ";
    string line;
    if (asmfile.is_open()) {
        int index_line = 0;
        while(getline(asmfile,line)) {
            
            vector<string> tokens = split(line, delimiter);
            if (tokens.size() <= 1 || tokens.size() > 3) {
                std::cout<<"Error : line :"<<line<<endl<<"Token size is :"<<tokens.size();
                return 11;
            }
            if (mnemonics.find(tokens[1]) == mnemonics.end()) {
                std::cout<<"Unknown Identifier";
                return 11;
            }
            if (stoi(tokens[0]) != index_line) { // You should put try catch to handle unwanted exception
                std::cout<<"Index line is incorrect";
                return 11;
            }
            
            Instruction *inst = getInstruction(tokens);
            instructions.push_back(inst);
            index_line++;
            
        }
    } else {
        cout<<"Unable to open file";
    }

}
vector<string> Program::split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    
    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    
    res.push_back (s.substr (pos_start));
    return res;
}


