cmake_minimum_required()

project(deckofcards CXX)

set(SOURCE_FILES
    main.cc
    deck.cc
)

add_executable(deckofcards ${SOURCE_FILES})

include_directories(
    TOP_LEVEL_DIRECTORY
)

install (TARGETS deckofcards DESTINATION ${CMAKE_INSTALL_BINDIR})