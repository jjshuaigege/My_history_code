#ifndef __OTHER_FUNCTION_H__
#define __OTHER_FUNCTION_H__
#include <string>
#include "warrior.h"
class HQ;
class warrior;
class weapon;
warrior* choose_worrior_by_name(std::string s,int serial,int health,int force,HQ* HQ_belonged,color camp);
weapon* choose_weapon_by_serial(int serial,warrior* owner);
bool weapons_resort(weapon* a,weapon* b);
bool weapons_resort_for_rob(weapon* a,weapon* b);
void print_now_time();
#endif
