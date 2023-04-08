#ifndef USER_MOD_CONFIG_H
#define USER_MOD_CONFIG_H

#define UMVERSION 0.1
#define USERMOD_MENU_LENGTH 2


extern int UMcurrentWatchFace = 0;
extern int* UMPointers[USERMOD_MENU_LENGTH] = {&UMcurrentWatchFace};

const char* UMMods[] = {"Switch WatchFace","test"};

#endif