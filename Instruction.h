
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <string>
using namespace std;
class Program;

class Instruction {
    protected :
    Program *program;
    unsigned int index;
    string opcode;
    public :
    Instruction(Program *init_program,unsigned int init_index, string init_opcode) {
        program = init_program;
        index = init_index;
        opcode = init_opcode;
        
    }
    unsigned int getIndex() {
        return index;
    }
    string getOpcode() {
        return opcode;
    }
    
    virtual unsigned int execute(stack<int> &eval_stack) = 0;
};
class READ: public Instruction {
    public :
    READ(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack)  {
        int value;
        cin>>value;
        eval_stack.push(value);
        return index + 1;
    }
    
};
class WRITE: public Instruction {
    public :
    WRITE(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 1);
        int TOP = eval_stack.top(); eval_stack.pop();
        cout<<TOP<<endl;
        return index + 1;
    }
    
};
class DUP: public Instruction {
    public :
    DUP(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) { 
        assert(eval_stack.size() >= 1);
        int TOP = eval_stack.top();
        eval_stack.push(TOP);
        return index + 1;
     }
    
};
class MUL: public Instruction {
    public :
    MUL(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2);
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        eval_stack.push(TOP * SECOND);
        return index + 1;
    }
    
};
class ADD: public Instruction {
    public :
    ADD(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2);
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        eval_stack.push(TOP + SECOND);
        return index + 1;
    }
    
};
class SUB: public Instruction {
    public :
    SUB(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2);
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        eval_stack.push(TOP - SECOND);
        return index + 1;
    }
    
};
class GT: public Instruction {
    public :
    GT(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2);        
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        eval_stack.push(TOP > SECOND);
        return index + 1;
    }
    
};
class LT: public Instruction {
    public :
    LT(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2); 
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        eval_stack.push(TOP < SECOND);
        return index + 1;
    }
    
};
class EQ: public Instruction {
    public :
    EQ(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2);
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        eval_stack.push(TOP == SECOND);
        return index + 1;
    }
    
};
class JMPZ: public Instruction {
    public :
    JMPZ(Program *init_program,unsigned int init_index, string init_opcode)
    :Instruction{init_program,init_index,init_opcode} {
        
    }
    unsigned int execute(stack<int> &eval_stack) {
        assert(eval_stack.size() >= 2);
        int TOP = eval_stack.top(); eval_stack.pop();
        int SECOND = eval_stack.top(); eval_stack.pop();
        if (SECOND == 0)
          return TOP;
        return index + 1;
    }
    
};
class OneOperandInstruction: public Instruction {
    protected :
    unsigned int operand;
    public :
    OneOperandInstruction(Program *init_program,unsigned int init_index, string init_opcode, unsigned int init_operand)
    :Instruction{init_program,init_index,init_opcode} {
        operand = init_operand;
    }
    unsigned int getOperand() { return operand; }
    
    
    
};
class PUSH:public OneOperandInstruction {
    public :
    PUSH(Program *init_program,unsigned int init_index, string init_opcode, unsigned int init_operand)
    :OneOperandInstruction{init_program,init_index,init_opcode,init_operand} {
    }
    unsigned int execute(stack<int> &eval_stack) {
        eval_stack.push(operand);
        return index + 1;
    }
};
class POP:public OneOperandInstruction {
    public :
    POP(Program *init_program,unsigned int init_index, string init_opcode, unsigned int init_operand)
    :OneOperandInstruction{init_program,init_index,init_opcode,init_operand} {
    }
    unsigned int execute(stack<int> &eval_stack) {
       assert(eval_stack.size() >= operand);
       for (int i = 0;i < operand; ++i) {
          eval_stack.pop();
       }
       return index + 1;
    }
};
class ROT:public OneOperandInstruction {
    public :
    ROT(Program *init_program,unsigned int init_index, string init_opcode, unsigned int init_operand)
    :OneOperandInstruction{init_program,init_index,init_opcode,init_operand} {
    }
    unsigned int execute(stack<int> &eval_stack) {
       assert(eval_stack.size() >= operand);
       vector<int> aux;
       for (int i = 0;i < operand; ++i) {
          int value = eval_stack.top(); eval_stack.pop();
          aux.push_back(value);
       }
       for (int i = 0;i < operand; ++i) {
          eval_stack.push(aux[i]);
       }
       return index + 1;
    }
};

#endif
