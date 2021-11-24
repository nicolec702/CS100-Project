CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

//ADD_EXECUTABLE(main main.cpp weapons.cpp)

//ADD_EXECUTABLE(test test.cpp)

ADD_EXECUTABLE(main2 main.cpp WeaponsFiles/weapons.cpp CharacterFiles/attribute.cpp CharacterFiles/character.hpp CharacterFiles/attackCharacter.hpp)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
