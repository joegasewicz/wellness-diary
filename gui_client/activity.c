//
// Created by joe on 07/07/22.
//

#include "activity.h"

WA_Activity *WA_activity_new()
{
   WA_Activity *a = malloc(sizeof(WA_Activity));
   return a;
}

void WA_set_combo_select_activity(WA_Activity* a, GtkComboBox *combo, char *hours[24])
{
    for (int i = 1; i < 24; i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), hours[i]);
    }
}
