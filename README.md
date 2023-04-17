# WatchyUserMod
WatchyUserMod is a fork of the official Watchy repository that adds a Usermod element to the Main Menu. Clicking on `UserMod` will open another Menu where you can see UserModValues. These are just variables that you can change and later access to change the behavior of your Watchface. You can click on a UserModValue to open an interface where you can increase or decrease the value by pressing the up or down button.
## Setup
1. Download this Repository as a .zip file. Extract it into your libraries folder.
2. Move the original library to another location which is not in your libraries folder to prevent complications.
3. Technically you're good to go now but you won't be able to access your custom settings right away.
4. To make your Watchface compatible you just have to rename your `drawWatchFace()` method to `UMdrawWatchFace(int *values[])`. Now you can access Uservalues by using `*values[index]`. (Other ways are currently not possible)

## Switching Watchface
1. Create a switch case statment in your `UMdrawWatchFace` like `switch (values[0]) {}`. The first element of values is already definde as the current Watchface but you can change that.
2. now you can add different cases that run code from different WatchFaces depending on the value of `values[0]`. But remember that all the functions have to be in the same class.

## Create custom Uservalues
1. Open UserModConfig.h and Watchy.cpp in you're favorite text/code editor.
2. Add your own variable `extern RTC_DATA_ATTR int yourCustomValue;` into `UserModConfig.h`.
3. Add a quick title string to `UMMods` like `const char* UMMods[] = {"Switch WatchFace","test","My Value"};`.
4. Now go into `Watchy.cpp` at line 22 and add your custom Value like `RTC_DATA_ATTR int yourCustomValue = 0;`(zero obviously being the default value).
5. Scroll down a bit until you see a list `UMPointers`. Now you have to add a pointer to the end of the list like `RTC_DATA_ATTR int* UMPointers[USERMOD_MENU_LENGTH] = {&UMcurrentWatchFace, &UMtestValue, &yourCustomValue};`.
6. In `UserModconfig.h` increase the value of `#define USERMOD_MENU_LENGTH 2` by one

## Example
In the following example you're going to have to replace the methods with your own. Be careful to **not override the original drawWatchFace() method**.
```c++
void SwitchingWatchFace::UMdrawWatchFace(int values[]) {
  switch (values[0]) {
    case 0:
      SEGdrawWatchFace(); // replace with your own method
      break;
    case 1:
      BasicDrawWatchFace(); // replace with your own method
      break;
    case 2:
      BINdrawWatchFace(); // replace with your own method
    default:
      break;      
  }
}

SwitchingWatchFace watchy(settings);

void setup(){
  watchy.init();
}

void loop(){}
```