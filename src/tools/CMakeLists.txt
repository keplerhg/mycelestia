macro(install_perl_tools)
  if(${ARGC} LESS 1)
    message(FATAL_ERROR "install_perl_tools requires at least 1 argument")
  endif()

  set(__sources ${ARGV})

  install(
    PROGRAMS ${__sources}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT tools
  )
endmacro()

add_subdirectory(atmosphere)
add_subdirectory(binaries)
add_subdirectory(charm2)
add_subdirectory(cmod)
add_subdirectory(galaxies)
add_subdirectory(globulars)
add_subdirectory(spice2xyzv)
add_subdirectory(stardb)
add_subdirectory(vsop)
add_subdirectory(xindex)
add_subdirectory(xyzv2bin)
