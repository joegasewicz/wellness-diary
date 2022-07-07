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
    char *name;
    char *date;
    WA_ActivityType type;
} WA_Activity;

void WA_set_combo_select_activity(WA_Activity* a, GtkComboBox *combo, char *hours[24]);
WA_Activity *WA_activity_new();

#endif //GUI_CLIENT_ACTIVITY_H
