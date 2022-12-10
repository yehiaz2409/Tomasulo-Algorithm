#include "Instruction.h"


Instruction::Instruction(string o, string a, string r1, string r2, string r3){
    op = o;
    assembly = a;
    rs1 = r1;
    rs2 = r2;
    rd = r3;
    issue = -1;
    exec = -1;
    wb = -1;
}

void Instruction::set_op(string o){
    op = o;
}

void Instruction::set_assembly(string a){
    assembly = a;
}

void Instruction::set_rs1(string r){
    rs1 = r;
}

void Instruction::set_rs2(string r){
    rs2 = r;
}

void Instruction::set_rd(string r){
    rd = r;
}

void Instruction::set_issue(int i){
    issue = i;
}

void Instruction::set_exec(int e){
    exec = e;
}

void Instruction::set_wb(int w){
    wb = w;
}

string Instruction::get_op(){
    return op;
}

string Instruction::get_assembly(){
    return assembly;
}

string Instruction::get_rs1(){
    return rs1;
}

string Instruction::get_rs2(){
    return rs2;
}

string Instruction::get_rd(){
    return rd;
}

int Instruction::get_issue(){
    return issue;
}

int Instruction::get_exec(){
    return exec;
}

int Instruction::get_wb(){
    return wb;
}

// Path: Instruction.h