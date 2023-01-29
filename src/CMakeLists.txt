set(MODULE_NAME XoX)

message("BUILDING XoX")

file(GLOB_RECURSE SOURCES *.hpp *.cpp)

add_library(${MODULE_NAME} STATIC ${SOURCES})


find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(XoX sfml-graphics)

target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/..")