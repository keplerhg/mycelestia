include(CheckLibraryExists)
check_library_exists(m sqrt "" HAS_LIBM)
if(HAS_LIBM)
  set(LIBM "m")
endif()

foreach(tool vsoptrunc-rect vsoptrunc-sph)
  add_executable(${tool} "${tool}.c")
  target_link_libraries(${tool} PUBLIC ${LIBM})
  install(
    TARGETS ${tool}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT tools
  )
endforeach()
