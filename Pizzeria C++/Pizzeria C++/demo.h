#ifndef DEMO_H
#define DEMO_H

#include <iostream>
#include <string>
using namespace std;

#include "pizzeria.h"  

class Pizzeria;
void setupDemoMenuAndStock(Pizzeria& pizzeria);
void loadDBTXT(Pizzeria& pizzeria, string path);

#endif 
