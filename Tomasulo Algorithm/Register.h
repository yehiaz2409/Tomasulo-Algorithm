#pragma once
#include <iostream>
#include <string>
using namespace std;

class Register{
    private:
        string name;
        int value;
        bool busy = false;
        string Q;
    public:
        Register() = default;
        Register(string);
        void set_value(int);
        void set_busy(bool);
        void set_Q(string);
        string get_name();
        int get_value();
        bool get_busy();
        string get_Q();
};