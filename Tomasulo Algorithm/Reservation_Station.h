#pragma once
#include <iostream>
#include <string>
using namespace std;
class Reservation_Station{
    private:
        string Name;
        bool busy = false;
        string op;
        string Vj;
        string Vk;
        string Qj;
        string Qk;
        string A;
    public:
    Reservation_Station() = default;
    Reservation_Station(string);
    void set_name(string);
    void set_busy(bool);
    void set_op(string);
    void set_Vj(string);
    void set_Vk(string);
    void set_Qj(string);
    void set_Qk(string);
    void set_A(string);
    string get_name();
    bool get_busy();
    string get_op();
    string get_Vj();
    string get_Vk();
    string get_Qj();
    string get_Qk();
    string get_A();
};


