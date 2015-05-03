project(voip.tox)

cmake_minimum_required(VERSION 2.6)

enable_language(CXX)

find_package(kodiplatform REQUIRED)

include_directories(${kodiplatform_INCLUDE_DIRS}
                    ${KODI_INCLUDE_DIR})

set(DEPLIBS ${kodiplatform_LIBRARIES})

message(STATUS "DEPLIST: ${DEPLIBS}")

set(VOIPTOX_SOURCES src/client.cpp
                    src/VOIPToxData.cpp)

build_addon(voip.tox VOIPTOX DEPLIBS)

include(CPack)
