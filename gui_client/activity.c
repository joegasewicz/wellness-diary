//
// Created by joe on 07/07/22.
//

#include "activity.h"

static WA_ActivityType *WA_activity_type_new(uint8_t id, char *name)
{
    WA_ActivityType *at = malloc(sizeof(WA_ActivityType));
    at->id = id;
    at->name = malloc(sizeof(name));
    strcpy(at->name, name);
    return at;
}

static WA_ActivityDetail *WA_activity_detail_new(uint8_t id, char *name, uint8_t activity_id)
{
    WA_ActivityDetail *ad = malloc(sizeof(WA_ActivityDetail));
    ad->id = id;
    ad->name = malloc(sizeof(name));
    strcpy(ad->name, name);
    ad->activity_id = activity_id;
    return ad;
}

WA_Activity *WA_activity_new(char *hours[24])
{
   WA_Activity *a = malloc(sizeof(WA_Activity));
    for (int i = 1; i < 24; i ++)
    {
        a->day_hours[i] = hours[i];
    }
    // Static types
    a->types[0] = WA_activity_type_new(1, "Sleeping");
    a->types[1] = WA_activity_type_new(2, "Eating");
    a->types[2] = WA_activity_type_new(3, "Exercise");
    a->types[3] = WA_activity_type_new(4, "Work");
    a->types[4] = WA_activity_type_new(5, "Mental");
    a->types[5] = WA_activity_type_new(6, "Relaxing");
    a->types[6] = WA_activity_type_new(7, "Leisure");

    a->details[0] = WA_activity_detail_new(1, "Fish &  Chips", 2);
    a->details[1] = WA_activity_detail_new(2, "Cereal with Oat Milk", 2);
   return a;
}

void WA_set_combo_select_time(WA_Activity* a, GtkComboBoxText *combo)
{
    for (int i = 1; i < 24; i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), a->day_hours[i]);
    }
}

void WA_set_combo_select_activity(WA_Activity* a, GtkComboBoxText *combo)
{
    for (int i = 0; i <= 6; i++)
    {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), a->types[i]->name);
    }
}

void WA_set_combo_select_activity_detail(WA_Activity* a, GtkComboBoxText *combo)
{

}