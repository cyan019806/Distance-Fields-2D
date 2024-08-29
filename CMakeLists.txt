cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project("Distance_Fields_2D")

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(imgui REQUIRED)

add_executable(Distance_Fields_2D)

add_subdirectory(ext/glad)

set_target_properties(Distance_Fields_2D
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_sources(Distance_Fields_2D PRIVATE
    "src/main.cpp"
    "src/model.cpp"
    "src/Iso-curve.cpp"
    "src/MatrixStack.cpp"
    "src/DrawModel.cpp"
    "src/background.cpp"
)

target_include_directories(Distance_Fields_2D PRIVATE
    "include/"
)

target_link_libraries(Distance_Fields_2D PRIVATE
    glad
    glfw
    imgui::imgui
    glm::glm
    OpenGL::GL
)

add_custom_command(TARGET Distance_Fields_2D POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        "${CMAKE_CURRENT_SOURCE_DIR}/shader"
        "$<TARGET_FILE_DIR:Distance_Fields_2D>/shader"
    VERBATIM
)

# add_custom_command(TARGET Distance_Fields_2D POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E create_symlink
#         "${CMAKE_CURRENT_SOURCE_DIR}/raw"
#         "$<TARGET_FILE_DIR:Distance_Fields_2D>/raw"
#     VERBATIM
# )

# add_custom_command(TARGET voxel_texture POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E create_symlink
#         "${CMAKE_CURRENT_SOURCE_DIR}/texture"
#         "$<TARGET_FILE_DIR:Distance_Fields_2D>/texture"
#     VERBATIM
# )