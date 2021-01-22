cmake_minimum_required(VERSION 3.13)
project(Chess)

set(CMAKE_CXX_STANDARD 11)

add_executable(Chess Piece.cpp Square.cpp Game.cpp Board.cpp Player.cpp Pawn.cpp King.cpp chess.cpp Knight.cpp Bishop.cpp Rook.cpp Queen.cpp)