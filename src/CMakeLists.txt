add_subdirectory(Vendor)

set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/src/)

# Inject version number
configure_file(
  ${SRCROOT}/version.rc.in
  ${SRCROOT}/version.rc
  @ONLY)

file(GLOB SRC "${SRCROOT}/*.cpp" "${SRCROOT}/*.hpp" "${SRCROOT}/*.rc")
source_group("Sources" FILES ${SRC})

message("${SRCROOT}")

add_executable(SDVXPAD ${SRC})

target_compile_features(SDVXPAD PRIVATE cxx_std_17)
target_include_directories(SDVXPAD PRIVATE ${SRCROOT})

target_link_libraries(SDVXPAD PRIVATE uws optparse spdlog)

add_custom_command(
    TARGETSDVXPAD POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res/ $<TARGET_FILE_DIR:SDVXPAD>/res/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/static/ $<TARGET_FILE_DIR:SDVXPAD>/
)
