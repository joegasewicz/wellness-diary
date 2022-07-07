//
// Created by joe on 07/07/22.
//


#include "utils.h"

void WD_get_day_count(char *hours[24])
{
    for (int i = 1; i < 24; i++)
    {
        char time[6];
        sprintf(time, "%i:00", i);
        hours[i] = malloc(sizeof(time));
        strcpy(hours[i] ,time);
    }
}