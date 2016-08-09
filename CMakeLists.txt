cmake_minimum_required(VERSION 3.0)
project(TicTacToe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
set(SOURCE_FILES main.cpp Grid.cpp Grid.h Exceptions.h XandZero.cpp XandZero.h .idea/pozition.cpp .idea/pozition.h include/WinLogic.cpp include/WinLogic.h WinScreen.cpp WinScreen.h WinCondition.h Logger.cpp Logger.h)
add_executable(TicTacToe ${SOURCE_FILES})

# Detect and add SFML
set(SFML_DIR "/home/petru/ClionProjects/TicTacToe/share/SFML/cmake/Modules/")
set(CMAKE_MODULE_PATH "/home/petru/ClionProjects/TicTacToe/share/SFML/cmake/Modules/" ${CMAKE_MODULE_PATH})
find_package(SFML REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TicTacToe ${SFML_LIBRARIES})
endif()