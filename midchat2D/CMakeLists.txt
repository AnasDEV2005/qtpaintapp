cmake_minimum_required(VERSION 3.5)
project(Midchat2D)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find Qt5
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Enable AUTOMOC for Q_OBJECT processing
set(CMAKE_AUTOMOC ON)

# Add the executable
add_executable(Midchat2D main.cpp Canvas.cpp)

# Link Qt5 libraries
target_link_libraries(Midchat2D Qt5::Core Qt5::Gui Qt5::Widgets)
