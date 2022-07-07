//
// Created by joe on 07/07/22.
//

#include "activity.h"

WA_Activity *WA_activity_new(char *hours[24])
{
   printf("NOW -----> %s", hours[0]);
   WA_Activity *a = malloc(sizeof(WA_Activity));
    memcpy(a->day_hours, hours, sizeof(*hours) + 1);
   return a;
}

void WA_set_combo_select_activity(WA_Activity* a, GtkComboBoxText *combo)
{
    for (int i = 1; i < 24; i++)
    {
        printf("here-----> %s\n", a->day_hours[i]);
//        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), a->day_hours[i]);
    }
}
