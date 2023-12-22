cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(QuickRes
    VERSION 0.1.0
    LANGUAGES CXX
)

add_executable(QuickRes)

target_compile_features(QuickRes PRIVATE cxx_std_23)

target_sources(QuickRes PRIVATE
    main.cc
)

FetchContent_Declare(
    argh
    GIT_REPOSITORY https://github.com/adishavit/argh
    GIT_TAG c429ee27134195b317e852324212bf39056bbff4
)
FetchContent_MakeAvailable(argh)

target_link_libraries(QuickRes PRIVATE argh)

# Install
set(CPACK_PACKAGE_VENDOR "AZAIS Corentin")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "QuickRes is a small command line utility that allows the user to quickly change screen resolution and refresh rate.")
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_HOMEPAGE_URL "https://github.com/azais-corentin/QuickRes")
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_SOURCE_GENERATOR "CPACK_BINARY_NSIS")
set(CPACK_PACKAGE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/installer)

install(TARGETS QuickRes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
include(CPack)