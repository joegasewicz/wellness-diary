// Wellness Diary Prototype GUI tool. Copyright 2022.
// Usage subject to the GPL2 license conditions.
// All public functions prefixed with 'WA_'
#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include "utils.h"

#define DEBUG 1
#define GC_LOGGER(msg) if (DEBUG) printf("%s\n", msg);
#define GC_WINDOW_WIDTH 1004
#define GC_WINDOW_HEIGHT 558

GtkWidget *activity_detail_txt;
GtkWidget *symptom_txt;

static void WA_create_list_store_day_times(GtkListStore *list_store, char *hours[24])
{
    for (int i = 1; i < 24; i++)
    {
        gtk_list_store_insert_with_values(list_store, NULL, i, 0,
                                          hours[i], 1, "text", -1);
    }
}

void WA_end_program(GtkWidget *wid, gpointer ptr)
{
    GC_LOGGER("User exiting app.");
    gtk_main_quit();
}

void get_input(GtkWidget *wid, gpointer ptr, GtkWidget *txt)
{
    const char *input = gtk_entry_get_text(GTK_ENTRY(txt));
    gtk_label_set_text(GTK_LABEL(ptr), input);
}

void add_activity()
{
    GC_LOGGER("Adding activity");
}

int main(int argc, char *argv[])
{
    GC_LOGGER("Starting gui");

    char *list_box_hours[24];
    // Init
    gtk_init(&argc, &argv);
    // Window
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Widgets
    GtkWidget *main_table = gtk_table_new(2, 2 ,TRUE);
    GtkWidget *left_table = gtk_table_new(2, 2, TRUE);
    GtkWidget *right_table = gtk_table_new(9, 2, TRUE);
    GtkListStore *day_list_store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    GtkWidget *day_tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(day_list_store));
    GtkWidget *activity_sub_heading_lb = gtk_button_new_with_label("Add new activity to Monday");
    GtkWidget *activity_detail_sub_heading_lb = gtk_button_new_with_label("Create a new activity detail");
    GtkWidget *add_symptom_sub_heading_lb = gtk_button_new_with_label("Add Symptom");
    GtkWidget *create_new_symptom_sub_heading_lb = gtk_button_new_with_label("Create a new symptom");
    GtkWidget *combo_select_time = gtk_combo_box_new();
    GtkWidget *combo_select_activity_type = gtk_combo_box_new();
    GtkWidget *combo_select_activity_detail = gtk_combo_box_new();
    GtkWidget *combo_select_activity = gtk_combo_box_new();
    GtkWidget *combo_select_symptom = gtk_combo_box_new();
    GtkWidget *diary_next_btn = gtk_button_new_with_label("Next");
    GtkWidget *diary_prev_btn = gtk_button_new_with_label("Previous");
    GtkWidget *activity_add_btn = gtk_button_new_with_label("Add");
    GtkWidget *activity_detail_btn = gtk_button_new_with_label("Add");
    GtkWidget *symptom_add_btn = gtk_button_new_with_label("Add");
    GtkWidget *symptom_create = gtk_button_new_with_label("Add");
    // Entries
    activity_detail_txt = gtk_entry_new();
    symptom_txt = gtk_entry_new();
    // Day hours list
    WD_get_day_count(list_box_hours);
    WA_create_list_store_day_times(GTK_LIST_STORE(day_list_store), list_box_hours);
    GtkCellRenderer *day_text_rend = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(
            GTK_TREE_VIEW(day_tree), -1, "Today", day_text_rend, "text", 0, NULL);
    // Combos
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo_select_time), "");

    // Left table
    gtk_table_attach_defaults(GTK_TABLE(left_table), day_tree, 0, 2, 0, 2);
    // Right table
    gtk_table_attach_defaults(GTK_TABLE(right_table), activity_detail_txt, 0, 1, 0, 1);
    // Main table
    gtk_table_attach_defaults(GTK_TABLE(main_table), left_table, 0, 1, 0, 2);
    gtk_table_attach_defaults(GTK_TABLE(main_table), right_table, 1, 2, 0, 2);
    // Containers
    gtk_container_add(GTK_CONTAINER(win), main_table);
    // Signals
    g_signal_connect(quit_btn, "clicked", G_CALLBACK(WA_end_program), NULL);
    g_signal_connect(win, "delete_event", G_CALLBACK(WA_end_program), NULL);
    // Window work
    gtk_widget_show_all(win);
    gtk_window_resize(win, GC_WINDOW_WIDTH, GC_WINDOW_HEIGHT);
    // Start main
    gtk_main();
    // Cleanup
    return 0;
}