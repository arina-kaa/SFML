add_executable(sfml21 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

target_include_directories(sfml21 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(sfml21 PUBLIC cxx_std_17)
target_compile_definitions(sfml21 PRIVATE SFML_STATIC)

target_link_libraries(sfml21 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})