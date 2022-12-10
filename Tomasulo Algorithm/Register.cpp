#include "Register.h"
Register::Register(string n){
    name = n;
}
void Register::set_value(int v){
    value = v;
}
void Register::set_busy(bool b){
    busy = b;
}
void Register::set_Q(string q){
    Q = q;
}
string Register::get_name(){
    return name;
}
int Register::get_value(){
    return value;
}
bool Register::get_busy(){
    return busy;
}
string Register::get_Q(){
    return Q;
}
//Path: Register.h