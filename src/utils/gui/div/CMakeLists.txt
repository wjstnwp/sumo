set(utils_gui_div_STAT_SRCS
   GLHelper.cpp
   GLHelper.h
   GLObjectValuePassConnector.h
   GUIBasePersonHelper.cpp
   GUIBasePersonHelper.h
   GUIBaseVehicleHelper.cpp
   GUIBaseVehicleHelper.h
   GUIDesigns.cpp
   GUIDesigns.h
   GUIDialog_GLChosenEditor.cpp
   GUIDialog_GLChosenEditor.h
   GUIDottedGeometry.cpp
   GUIDottedGeometry.h
   GUIGeometry.cpp
   GUIGeometry.h
   GUIGlobalSelection.cpp
   GUIGlobalSelection.h
   GUIGlobalViewObjectsHandler.cpp
   GUIGlobalViewObjectsHandler.h
   GUIGlobalViewUpdater.cpp
   GUIGlobalViewUpdater.cpp
   GUIIOGlobals.cpp
   GUIIOGlobals.h
   GUIMessageWindow.cpp
   GUIMessageWindow.h
   GUIParam_PopupMenu.cpp
   GUIParam_PopupMenu.h
   GUIParameterTableItem.h
   GUIParameterTableWindow.cpp
   GUIParameterTableWindow.h
   GUIPersistentWindowPos.cpp
   GUIPersistentWindowPos.h
   GUISelectedStorage.cpp
   GUISelectedStorage.h
   GUIUserIO.cpp
   GUIUserIO.h
   GUIVideoEncoder.h
   GUIViewObjectsHandler.cpp
   GUIViewObjectsHandler.h
   GUIViewUpdater.cpp
   GUIViewUpdater.h
)

add_library(utils_gui_div STATIC ${utils_gui_div_STAT_SRCS})
set_property(TARGET utils_gui_div PROPERTY PROJECT_LABEL "z_utils_gui_div")
