/*
Implement a simulator for the Tomasulo algorithm for 16-bit RISC-V processor. The simulator should be able to simulate the execution of the following instructions:
LOAD, STORE, BEQ, JAL, RET, ADD, ADDI, NEG, NOR, MULT
*/
#include "Instruction.h"
#include "Instruction.cpp"
#include "Reservation_Station.h"
#include "Reservation_Station.cpp"
#include "Register.h"
#include "Register.cpp"
#include <bits/stdc++.h>
using namespace std;


void issue(int cycle, vector <Instruction> &instruction_table, vector <Reservation_Station> &reservation_station_table, vector <Register> &register_table, vector <int> &memory){
    bool issue = false;
    for(int i = 0; i < instruction_table.size(); i++){
        if(instruction_table[i].get_issue() == -1){
            if(instruction_table[i].get_op() == "LOAD"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "Load" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        //cout << "Load Test\n";
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                        }
                        // reservation_station_table[j].set_Vj("0");
                        // [j].set_Vk("0");
                        // reservation_station_table[j].set_Qj("0");
                        // reservation_station_table[reservation_station_tablej].set_Qk("0");
                        reservation_station_table[j].set_A(instruction_table[i].get_rs2());
                        instruction_table[i].set_issue(cycle);
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rd()){
                                register_table[k].set_Q(reservation_station_table[j].get_name());
                            }
                        }
                        break;
                    }
                }
                if (issue == true){
                    break;
                }
            }
            else if(instruction_table[i].get_op() == "STORE"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "Store" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                        }
                        // reservation_station_table[j].set_Vj("0");
                        // [j].set_Vk("0");
                        // reservation_station_table[j].set_Qj("0");
                        // reservation_station_table[reservation_station_tablej].set_Qk("0");
                        reservation_station_table[j].set_A(instruction_table[i].get_rs1());
                        instruction_table[i].set_issue(cycle);
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rd()){
                                register_table[k].set_Q(reservation_station_table[j].get_name());
                            }
                        }
                        break;
                    }
                }
                if (issue == true){
                    break;
                }
            }
            else if(instruction_table[i].get_op() == "BEQ"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "BEQ" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                            if(register_table[k].get_name() == instruction_table[i].get_rs2()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vk(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qk("");
                                }
                                else{
                                    reservation_station_table[j].set_Qk(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vk("");
                                }
                            }
                        }
                        // reservation_station_table[j].set_Vj("0");
                        // [j].set_Vk("0");
                        // reservation_station_table[j].set_Qj("0");
                        // reservation_station_table[reservation_station_tablej].set_Qk("0");
                        reservation_station_table[j].set_A(instruction_table[i].get_rd());
                        instruction_table[i].set_issue(cycle);
                        break;
                    }
                    
                }
                if (issue == true){
                    break;
                }
            }
            else if (instruction_table[i].get_op() == "JAL" || instruction_table[i].get_op() == "RET"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "JAL_RET" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                         reservation_station_table[j].set_Vj("0");
                         reservation_station_table[j].set_Vk("0");
                         reservation_station_table[j].set_Qj("0");
                         reservation_station_table[j].set_Qk("0");
                        reservation_station_table[j].set_A(instruction_table[i].get_rs1());
                        instruction_table[i].set_issue(cycle);
                        break;
                    }
                }
                if (issue == true){
                    break;
                }
            }
            else if(instruction_table[i].get_op() == "ADD" || instruction_table[i].get_op() == "ADDI" || instruction_table[i].get_op() == "SUB"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "Add" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                            if(register_table[k].get_name() == instruction_table[i].get_rs2()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vk(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qk("");
                                }
                                else{
                                    reservation_station_table[j].set_Qk(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vk("");
                                }
                            }
                        }
                        // reservation_station_table[j].set_Vj("0");
                        // [j].set_Vk("0");
                        // reservation_station_table[j].set_Qj("0");
                        // reservation_station_table[reservation_station_tablej].set_Qk("0");
                        reservation_station_table[j].set_A("");
                        instruction_table[i].set_issue(cycle);
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rd()){
                                register_table[k].set_Q(reservation_station_table[j].get_name());
                            }
                        }
                        break;
                    }
                    
                }
                if (issue == true){
                    break;
                }
            }
            else if(instruction_table[i].get_op() == "NEG"){
                for (int j = 0; i < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "Neg" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                        }
                        reservation_station_table[j].set_Vk("0");
                        reservation_station_table[j].set_Qk("0");
                        reservation_station_table[j].set_A("");
                        instruction_table[i].set_issue(cycle);
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rd()){
                                register_table[k].set_Q(reservation_station_table[j].get_name());
                            }
                        }
                        break;
                    }
                }
                if (issue == true){
                    break;
                }
            }
            else if(instruction_table[i].get_op() == "NOR"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "Nor" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                            if(register_table[k].get_name() == instruction_table[i].get_rs2()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vk(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qk("");
                                }
                                else{
                                    reservation_station_table[j].set_Qk(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vk("");
                                }
                            }
                        }
                        // reservation_station_table[j].set_Vj("0");
                        // [j].set_Vk("0");
                        // reservation_station_table[j].set_Qj("0");
                        // reservation_station_table[reservation_station_tablej].set_Qk("0");
                        reservation_station_table[j].set_A("");
                        instruction_table[i].set_issue(cycle);
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rd()){
                                register_table[k].set_Q(reservation_station_table[j].get_name());
                            }
                        }
                        break;
                    }
                    
                }
                if (issue == true){
                    break;
                }
            }
            else if(instruction_table[i].get_op() == "MULT" || instruction_table[i].get_op() == "DIV"){
                for(int j = 0; j < reservation_station_table.size(); j++){
                    if(reservation_station_table[j].get_name() == "Mult" && reservation_station_table[j].get_busy() == false){
                        issue = true;
                        reservation_station_table[j].set_busy(true);
                        reservation_station_table[j].set_op(instruction_table[i].get_op());
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rs1()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vj(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qj("");
                                }
                                else{
                                    reservation_station_table[j].set_Qj(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vj("");
                                }
                            }
                            if(register_table[k].get_name() == instruction_table[i].get_rs2()){
                                if(register_table[k].get_busy() == false){
                                    reservation_station_table[j].set_Vk(to_string(register_table[k].get_value()));
                                    reservation_station_table[j].set_Qk("");
                                }
                                else{
                                    reservation_station_table[j].set_Qk(register_table[k].get_Q());
                                    reservation_station_table[j].set_Vk("");
                                }
                            }
                        }
                        // reservation_station_table[j].set_Vj("0");
                        // [j].set_Vk("0");
                        // reservation_station_table[j].set_Qj("0");
                        // reservation_station_table[reservation_station_tablej].set_Qk("0");
                        reservation_station_table[j].set_A("");
                        instruction_table[i].set_issue(cycle);
                        for(int k = 0; k < register_table.size(); k++){
                            if(register_table[k].get_name() == instruction_table[i].get_rd()){
                                register_table[k].set_Q(reservation_station_table[j].get_name());
                            }
                        }
                        break;
                    }
                    
                }
                if (issue == true){
                    break;
                }
            }
        }
    }
}


int main(){
    //Declaring the memory
    vector <int> memory(1000,0);
    
    //Declaring the reservation stations
    Reservation_Station load1("Load");
    Reservation_Station load2("Load");
    Reservation_Station add1("Add");
    Reservation_Station add2("Add");
    Reservation_Station add3("Add");
    Reservation_Station mult1("Mult");
    Reservation_Station mult2("Mult");
    Reservation_Station jal_ret("JAL_RET");
    vector <Reservation_Station> reservation_station_table;
    reservation_station_table.push_back(load1);
    reservation_station_table.push_back(load2);
    reservation_station_table.push_back(add1);
    reservation_station_table.push_back(add2);
    reservation_station_table.push_back(add3);
    reservation_station_table.push_back(mult1);
    reservation_station_table.push_back(mult2);
    reservation_station_table.push_back(jal_ret);

    //Declaring the registers
    Register r1("R1");
    Register r2("R2");
    Register r3("R3");
    Register r4("R4");
    Register r5("R5");
    Register r6("R6");
    Register r7("R7");
    Register r8("R8");

    //Declaring the register table
    vector <Register> register_table;
    register_table.push_back(r1);
    register_table.push_back(r2);
    register_table.push_back(r3);
    register_table.push_back(r4);
    register_table.push_back(r5);
    register_table.push_back(r6);
    register_table.push_back(r7);
    register_table.push_back(r8);

    //Declaring the instructions
    Instruction i1("LOAD", "Load R2,32(R1)", "R2", "32", "R6");
    Instruction i2("LOAD", "Load R4,44(R3)", "R3", "44", "R4");
    Instruction i3("MULT", "Mult R5,R4,R7", "R4", "R7", "R5");
    Instruction i4("SUB", "Sub R6,R4,R2", "R4", "R2", "R6");
    Instruction i5("DIV", "Div R8,R5,R2", "R5", "R2", "R8");
    Instruction i6("ADD", "Add R2,R6,R4", "R6", "R4", "R2");

    //Declaring the instruction table
    vector <Instruction> instruction_table;
    instruction_table.push_back(i1);
    instruction_table.push_back(i2);
    instruction_table.push_back(i3);
    instruction_table.push_back(i4);
    instruction_table.push_back(i5);
    instruction_table.push_back(i6);
    int cycle = 0;
    //void issue(int cycle, vector <Instruction> &instruction_table, vector <Reservation_Station> &reservation_station_table, vector <Register> &register_table, vector <int> &memory)
    for (int i = 0; i < 7; i++){
        cout << "Cycle: " << cycle << endl;
        issue(cycle, instruction_table, reservation_station_table, register_table, memory);
        // if (i == 1){
        //     cout << reservation_station_table.size() << endl;
        //     for (int x = 0; x < reservation_station_table.size(); x++){
        //         cout << x << endl;
        //         cout << "Reservation Station: " << reservation_station_table[x].get_name() << endl;
        //         cout << "Operation: " << reservation_station_table[x].get_op() << endl;
        //         cout << "Busy: " << reservation_station_table[x].get_busy() << endl;
        //         cout << "Vj: " << reservation_station_table[x].get_Vj() << endl;
        //         cout << "Vk: " << reservation_station_table[x].get_Vk() << endl;
        //         cout << "Qj: " << reservation_station_table[x].get_Qj() << endl;
        //         cout << "Qk: " << reservation_station_table[x].get_Qk() << endl;
        //         cout << "A: " << reservation_station_table[x].get_A() << endl;
        //     }
        // }
        for (int j = 0; j < instruction_table.size(); j++){
                //cout << reservation_station_table.size() << endl;
            cout << "Operation: " << instruction_table[j].get_op() << endl;
            cout << "Instruction: " << instruction_table[j].get_assembly() << endl;
            cout << "Destination: " << instruction_table[j].get_rd() << endl;
            cout << "Source 1: " << instruction_table[j].get_rs1() << endl;
            cout << "Source 2: " << instruction_table[j].get_rs2() << endl;
            cout << "Issue: " << instruction_table[j].get_issue() << endl;
        }
        cout << "=====================================================================================================" << endl;
        cycle++;
    }
}