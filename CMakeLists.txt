SET(CMAKE_CXX_FLAGS "-std=c++0x")
PROJECT(main)
FILE(
	 GLOB main_SRCS
    newHTeam.hpp
    newTeam.hpp
    main.cpp
)
SOURCE_GROUP("" FILES ${main_SRCS})

ADD_EXECUTABLE(main ${main_SRCS})

ADD_DEPENDENCIES(main frame utility)
TARGET_LINK_LIBRARIES(main frame utility ${Boost_LIBRARIES})
