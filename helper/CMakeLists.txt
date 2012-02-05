set(fontadjust_helper_SRCS
    main.cpp
    )
    
add_executable(fontadjust_helper ${fontadjust_helper_SRCS})

target_link_libraries(fontadjust_helper
    ${KDE4_KDEUI_LIBRARY}
)

install(TARGETS fontadjust_helper DESTINATION ${LIBEXEC_INSTALL_DIR})