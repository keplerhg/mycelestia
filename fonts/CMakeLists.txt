file(GLOB FONTS_SOURCES "*.ttf")

install(
  FILES ${FONTS_SOURCES}
  DESTINATION "${DATADIR}/fonts"
  COMPONENT core
)
