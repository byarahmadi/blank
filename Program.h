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
    /* Evaluation stack for operands */
    stack<int> eval_stack; 
    vector<string> split (string s, string delimiter);
    std::unordered_set<std::string> mnemonics{"READ","WRITE","DUP","MUL" ,"ADD"  ,"SUB",
                                                      "GT","LT"   ,"EQ","JMPZ","PUSH" ,"POP","ROT"};
    Instruction *getInstruction(vector<string> tokens);
    int parse();
      
    public :
    /*!constructor */
    Program(string filename);
    /* Prints instructions of the program in stdout */
    void print();
    /* Executes the program */
    void run();
    
};

#endif
