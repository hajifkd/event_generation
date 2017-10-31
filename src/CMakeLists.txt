cmake_minimum_required(VERSION 2.8)

#add_library(tracker STATIC
#  Particle.cc
#)

add_executable(main
  main.cc
)

target_link_libraries(main ${PYTHIA8_LIBRARY} m pthread dl)
