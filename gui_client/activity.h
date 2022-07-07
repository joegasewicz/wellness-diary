//
// Created by joe on 07/07/22.
//

#ifndef GUI_CLIENT_ACTIVITY_H
#define GUI_CLIENT_ACTIVITY_H

#include <gtk/gtk.h>
#include <stdlib.h>

typedef struct ActivityType {
    char *name;
} WA_ActivityType;

typedef struct Activity {
    char *day_hours[24];
    WA_ActivityType type;
} WA_Activity;

WA_Activity *WA_activity_new(char *hours[24]);

void WA_set_combo_select_activity(WA_Activity* a, GtkComboBoxText *combo);


#endif //GUI_CLIENT_ACTIVITY_H
