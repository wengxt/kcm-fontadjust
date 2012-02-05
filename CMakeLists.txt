project(kcm-fontadjust)

find_package(KDE4 REQUIRED)
find_package(Fontconfig REQUIRED)

add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(${KDE4_INCLUDES} ${QT_INCLUDES})

add_subdirectory(src)
add_subdirectory(helper)