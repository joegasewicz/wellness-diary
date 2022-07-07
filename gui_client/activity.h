//
// Created by joe on 07/07/22.
//

#ifndef GUI_CLIENT_ACTIVITY_H
#define GUI_CLIENT_ACTIVITY_H

typedef struct ActivityType {
    char *name;
} WA_ActivityType;

typedef struct Activity {
    char *name;
    char *date;
    WA_ActivityType type;
} WA_Activity;

#endif //GUI_CLIENT_ACTIVITY_H
