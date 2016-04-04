#pragma once

//СОВЕРШЕННО НЕПРАВИЛЬНО РАБОТАЕТ РАНДОМ

#include <iostream>
#include "Transport_system.h"
#include "Tickets_vect.h"
#include "Vectr.h"
#include "Plain_place.h"
#include "Bus_place.h"
#include "Train_place.h"
#include "Wrong_number.h"
#include "Incorrect_input.h"
#include <exception>

int interface();
int yes_or_no();
int creation (Transport_system &ts, Tickets_vect &tickets);
void finder(Tickets_vect &tickets);
int buy(const Transport_system &st, Tickets_vect &tickets, char trans_type);

