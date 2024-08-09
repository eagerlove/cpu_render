file(GLOB_RECURSE source CONFIGURE_DEPENDS src/*.cpp)

add_executable(CPURender ${source})

target_include_directories(CPURender PUBLIC include)
target_compile_definitions(CPURender PUBLIC GLM_FORCE_DEPTH_ZERO_TO_ONE GLM_FORCE_RADIANS GLM_FORCE_LEFT_HANDED)
target_link_libraries(CPURender glm)