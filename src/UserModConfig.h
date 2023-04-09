#ifndef USER_MOD_CONFIG_H
#define USER_MOD_CONFIG_H

#define UMVERSION 1.00
#define USERMOD_MENU_LENGTH 2

// Add your own custom values here:
extern RTC_DATA_ATTR int UMcurrentWatchFace;
extern RTC_DATA_ATTR int UMtestValue;


extern RTC_DATA_ATTR int* UMPointers[USERMOD_MENU_LENGTH];

const char* UMMods[] = {"Switch WatchFace","test"};

#endif