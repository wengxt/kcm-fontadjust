include_directories(${FONTCONFIG_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(kcm_SRCS
    fontadjustpage.cpp
    subpixelpage.cpp
    hintpage.cpp
    antialiasingpage.cpp
    fontadjustwizard.cpp
    fontadjust.cpp
    kxftconfig.cpp
    helper.cpp
)

kde4_add_ui_files(kcm_SRCS antialiasing_page.ui hint_page.ui subpixel_page.ui)

kde4_add_plugin(kcm_fontadjust ${kcm_SRCS})

target_link_libraries(kcm_fontadjust
    ${KDE4_KDEUI_LIBRARY}
    ${QT_QTXML_LIBRARY}
    ${FONTCONFIG_LIBRARIES}
)

install(TARGETS kcm_fontadjust DESTINATION ${PLUGIN_INSTALL_DIR})
install(FILES fontadjust.desktop DESTINATION ${SERVICES_INSTALL_DIR})