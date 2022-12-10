#pragma once
#include <iostream>
#include <string>
using namespace std;
class Instruction{
    private:
        string op;
        string assembly;
        string rs1;
        string rs2;
        string rd;
        int issue;
        int exec;
        int wb;
    public:
        Instruction() = default;
        Instruction(string, string, string, string, string);
        void set_op(string);
        void set_assembly(string);
        void set_rs1(string);
        void set_rs2(string);
        void set_rd(string);
        void set_issue(int);
        void set_exec(int);
        void set_wb(int);
        string get_op();
        string get_assembly();
        string get_rs1();
        string get_rs2();
        string get_rd();
        int get_issue();
        int get_exec();
        int get_wb();
};
