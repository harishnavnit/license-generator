cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(license-generator)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(QT_MIN_VERSION "5.5.0")
find_package(Qt5 ${QT_MIN_VERSION} REQUIRED COMPONENTS Core Quick)

qt5_add_resources(qml_QRC ${CMAKE_SOURCE_DIR}/src/ui/qml.qrc)

set(license_generator_SRCS src/license.cpp src/main.cpp)
add_executable(generator ${license_generator_SRCS} ${qml_QRC})
target_link_libraries(generator 
    Qt5::Qml
    Qt5::Core 
    Qt5::Quick 
)

install(TARGETS generator DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
