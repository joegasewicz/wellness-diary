#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

#define DEBUG 1
#define GC_LOGGER(msg) if (DEBUG) printf("%s\n", msg);
#define GC_WINDOW_WIDTH 1004
#define GC_WINDOW_HEIGHT 558

GtkWidget *activity_detail_txt;
GtkWidget *symptom_txt;


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

static void create_list_store_day_times(GtkListStore *list_store, char *hours[24])
{
    for (int i = 1; i < 24; i++)
    {
        gtk_list_store_insert_with_values(list_store, NULL, i, 0,
                                          hours[i], 1, "text...", -1);
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
    GtkWidget *main_table = gtk_table_new(2, 2 ,TRUE);
    GtkWidget *left_table = gtk_table_new(2, 2, TRUE);
    GtkWidget *right_table = gtk_table_new(5, 5, TRUE);
    GtkListStore *day_list_store = gtk_list_store_new(2, G_TYPE_STRING, G_TYPE_STRING);
    GtkWidget *day_tree = gtk_tree_view_new_with_model(GTK_TREE_MODEL(day_list_store));

    // Entries
    activity_detail_txt = gtk_entry_new();
    symptom_txt = gtk_entry_new();
    // Day hours list
    get_day_count(list_box_hours);
    create_list_store_day_times(GTK_LIST_STORE(day_list_store), list_box_hours);
    GtkCellRenderer *day_text_rend = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(
            GTK_TREE_VIEW(day_tree), -1, "Today", day_text_rend, "text", 0, NULL);

    // Table
    gtk_table_attach_defaults(GTK_TABLE(left_table), day_tree, 0, 2, 0, 2);
    gtk_table_attach_defaults(GTK_TABLE(right_table), activity_detail_txt, 0, 5, 0, 5);
    gtk_table_attach_defaults(GTK_TABLE(main_table), left_table, 0, 1, 0, 2);
    gtk_table_attach_defaults(GTK_TABLE(main_table), right_table, 1, 2, 0, 2);
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