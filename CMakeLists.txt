cmake_minimum_required(VERSION 3.24)
project(TP1 C)

set(CMAKE_C_STANDARD 11)

include_directories(ProgTpIFT3205_TransfFourier)


add_executable(Tp1_IFT3205_1
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_1-1.c)

add_executable(Tp1_IFT3205_2
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_1-2.c)

add_executable(Tp1_IFT3205_3
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_1-3.c)

target_link_libraries(Tp1_IFT3205_1 m)
target_link_libraries(Tp1_IFT3205_2 m)
target_link_libraries(Tp1_IFT3205_3 m)