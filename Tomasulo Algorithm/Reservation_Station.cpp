#include "Reservation_Station.h"
Reservation_Station::Reservation_Station(string name){
    Name = name;
    busy = false;
    op = "";
    Vj = "";
    Vk = "";
    Qj = "";
    Qk = "";
    A = "";
}
void Reservation_Station::set_name(string name){
    Name = name;
}
void Reservation_Station::set_busy(bool b){
    busy = b;
}
void Reservation_Station::set_op(string o){
    op = o;
}
void Reservation_Station::set_Vj(string v){
    Vj = v;
}
void Reservation_Station::set_Vk(string v){
    Vk = v;
}
void Reservation_Station::set_Qj(string q){
    Qj = q;
}
void Reservation_Station::set_Qk(string q){
    Qk = q;
}
void Reservation_Station::set_A(string a){
    A = a;
}
string Reservation_Station::get_name(){
    return Name;
}
bool Reservation_Station::get_busy(){
    return busy;
}
string Reservation_Station::get_op(){
    return op;
}
string Reservation_Station::get_Vj(){
    return Vj;
}
string Reservation_Station::get_Vk(){
    return Vk;
}
string Reservation_Station::get_Qj(){
    return Qj;
}
string Reservation_Station::get_Qk(){
    return Qk;
}
string Reservation_Station::get_A(){
    return A;
}
//Path: Reservation_Station.h