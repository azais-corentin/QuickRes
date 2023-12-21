cmake_minimum_required(VERSION 3.20)

include(FetchContent)

project(QuickRes LANGUAGES CXX)

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

install(TARGETS QuickRes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
include(CPack)