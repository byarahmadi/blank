#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <unordered_set>
#include <string>
using namespace std;

class Instruction;

class Program {
    private :
    fstream asmfile;
    std::vector<Instruction *> instructions;
    stack<int> eval_stack; // Evaluation Stack
    vector<string> split (string s, string delimiter);
    std::unordered_set<std::string> mnemonics{"READ","WRITE","DUP","MUL" ,"ADD"  ,"SUB",
                                                      "GT","LT"   ,"EQ","JMPZ","PUSH" ,"POP","ROT"};
    Instruction *getInstruction(vector<string> tokens);
    int parse();
      
    public :
    
    Program(string filename);
        
    
    void print();
    void run();

    friend class Instruction;
    
};

#endif
