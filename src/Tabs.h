/* Copyright 2014 the SumatraPDF project authors (see AUTHORS file).
   License: GPLv3 */

#ifndef Tabs_h
#define Tabs_h

// TODO: take WindowInfo::uiDPIFactor into account?
#define TABBAR_HEIGHT    24
#define TAB_WIDTH        200
#define TAB_HEIGHT       TABBAR_HEIGHT - 1

struct PageAnnotation;
class WindowInfo;
class Controller;

// This is the data, for every opened document, which is preserved between
// tab selections. It's loaded back in the WindowInfo for the currently active document.
struct TabData
{
    Controller *ctrl;
    bool        showToc;
    Vec<int>    tocState;
    WCHAR *     title;
    WCHAR *     filePath;
    RectI       canvasRc;

    TabData(): ctrl(NULL), showToc(false), title(NULL), filePath(NULL) { }
};

void SaveTabData(WindowInfo *win, TabData *tdata);
void PrepareAndSaveTabData(WindowInfo *win, TabData **tdata);
void SaveCurrentTabData(WindowInfo *win);
int TabsGetCount(WindowInfo *win);
TabData *GetTabData(WindowInfo *win, int tabIndex);
void DeleteTabData(TabData *tdata, bool deleteModel);
void LoadModelIntoTab(WindowInfo *win, TabData *tdata);

void CreateTabbar(WindowInfo *win);
void TabsOnLoadedDoc(WindowInfo *win);
void TabsOnCloseDoc(WindowInfo *win);
void TabsOnCloseWindow(WindowInfo *win);
void TabsOnChangedDoc(WindowInfo *win);
LRESULT TabsOnNotify(WindowInfo *win, LPARAM lparam, int tab1=-1, int tab2=-1);
void TabsSelect(WindowInfo *win, int tabIndex);
void TabsOnCtrlTab(WindowInfo *win, bool reverse);
// also shows/hides the tabbar when necessary
void UpdateTabWidth(WindowInfo *win);
void SwapTabs(WindowInfo *win, int tab1, int tab2);

#endif