#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

#define DEBUG 1
#define GC_LOGGER(msg) if (DEBUG) printf("%s\n", msg);
#define GC_WINDOW_WIDTH 1004
#define GC_WINDOW_HEIGHT 558

GtkWidget *activity_detail_txt;
GtkWidget *symptom_txt;

static const char *DAY_COUNT[][20] = {
    "01.00",
    "02.00",

};

static void get_day_count(char *hours[24])
{
    for (int i = 1; i < 24; i++)
    {
        char time[6];
        sprintf(time, "%i:00", i);
        hours[i] = malloc(sizeof(time));
        strcpy(hours[i] ,time);
    }
}

static void create_list_box_day_times(GtkListBox *list_box, char *hours[24])
{
    for (int i = 1; i < 24; i++)
    {
        GtkWidget *list_row_item_one_lbl = gtk_label_new(hours[i]);
        gtk_list_box_insert(list_box, list_row_item_one_lbl, i);
    }

}

void end_program(GtkWidget *wid, gpointer ptr)
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
    char *list_box_hours[24];

    GC_LOGGER("Starting gui");
    gtk_init(&argc, &argv);

    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Widgets
    GtkWidget *quit_btn = gtk_button_new_with_label("Quit");
    GtkWidget *add_activity_lbl = gtk_label_new("Add Activity");
    GtkWidget *main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    GtkWidget *main_table = gtk_table_new(2, 2 ,TRUE);
    GtkWidget *left_table = gtk_table_new(5, 5, TRUE);
    GtkWidget *right_table = gtk_table_new(5, 5, TRUE);
    GtkWidget *day_list_box = gtk_list_box_new();
    GtkWidget *list_row_item_one = gtk_list_box_row_new();
    GtkWidget *main_separator = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    // Entries
    activity_detail_txt = gtk_entry_new();
    symptom_txt = gtk_entry_new();
    // Listbox
    get_day_count(list_box_hours);
    create_list_box_day_times(GTK_LIST_BOX(day_list_box), list_box_hours);
    // Table
    gtk_table_attach_defaults(GTK_TABLE(left_table), day_list_box, 0, 5, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(right_table), activity_detail_txt, 0, 5, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(main_table), left_table, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(main_table), right_table, 1, 2, 0, 1);
    // Containers
    gtk_container_add(GTK_CONTAINER(win), main_table);
    // Signals
    g_signal_connect(quit_btn, "clicked", G_CALLBACK(end_program), NULL);
    g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);

    gtk_widget_show_all(win);

    gtk_window_resize(win, GC_WINDOW_WIDTH, GC_WINDOW_HEIGHT);
    gtk_main();

    return 0;
}