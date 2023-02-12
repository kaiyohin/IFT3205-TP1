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

add_executable(Tp1_IFT3205_4
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_1-4.c)

add_executable(Tp1_IFT3205_2-1a
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_2-1a.c)

add_executable(Tp1_IFT3205_2-1b
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_2-1b.c)
target_link_libraries(Tp1_IFT3205_2-1b m)

add_executable(Tp1_IFT3205_2-1c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_2-1c.c)
target_link_libraries(Tp1_IFT3205_2-1c m)

add_executable(Tp1_IFT3205_2-1d
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_2-1d.c)
target_link_libraries(Tp1_IFT3205_2-1d m)

add_executable(Tp1_IFT3205_2-1e
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_2-1e.c)
target_link_libraries(Tp1_IFT3205_2-1e m)

add_executable(Tp1_IFT3205_2-2
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_2-2.c)
target_link_libraries(Tp1_IFT3205_2-2 m)


add_executable(Tp1_IFT3205_3-2a
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_3-2a.c)
target_link_libraries(Tp1_IFT3205_3-2a m)

add_executable(Tp1_IFT3205_3-2b
        ProgTpIFT3205_TransfFourier/FonctionDemo1.c
        ProgTpIFT3205_TransfFourier/FonctionDemo1.h
        ProgTpIFT3205_TransfFourier/Tp1_IFT3205_3-2b.c)
target_link_libraries(Tp1_IFT3205_3-2b m)


target_link_libraries(Tp1_IFT3205_1 m)
target_link_libraries(Tp1_IFT3205_2 m)
target_link_libraries(Tp1_IFT3205_3 m)
target_link_libraries(Tp1_IFT3205_4 m)
target_link_libraries(Tp1_IFT3205_2-1a m)
