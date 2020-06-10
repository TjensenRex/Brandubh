cmake_minimum_required(VERSION 3.16)
project(Tafl)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tafl main.cpp Pieces.cpp Pieces.h Attackers.cpp Attackers.h Defenders.cpp Defenders.h King.cpp King.h functsForMain.cpp functsForMain.h)