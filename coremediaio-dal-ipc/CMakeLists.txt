cmake_minimum_required(VERSION 3.16)
project(coremediaio-dal-ipc)

include(GNUInstallDirs)
find_package(PkgConfig REQUIRED)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -std=c++11")
# We need this since we are using installed libraries using pkg-config
SET(CMAKE_SHARED_LINKER_FLAGS "-L/usr/local/lib")

pkg_check_modules(COREMEDIAIO_DAL REQUIRED coremediaio-dal)
find_library(AVFOUNDATION AVFoundation)
find_library(COCOA Cocoa)
find_library(COREFOUNDATION CoreFoundation)
find_library(COREMEDIA CoreMedia)
find_library(COREVIDEO CoreVideo)
find_library(COCOA Cocoa)
find_library(COREMEDIAIO CoreMediaIO)
find_library(IOSURFACE IOSurface)
find_library(IOKIT IOKit)

include_directories(${AVFOUNDATION}
					${COCOA}
					${COREFOUNDATION}
					${COREMEDIA}
					${COREVIDEO}
					${COREMEDIAIO}
					${COCOA}
                    ${IOSURFACE}
                    ${COREMEDIAIO_DAL_INCLUDE_DIRS}
                    common
                    client
                    server
                    server/Device)

set(coremediaio-dal-ipc_HEADERS
    client/CMIO_DPA_Sample_ClientExtras.h
    client/CMIODPASampleClient.h

    common/CMIO_DPA_Sample_Shared.h

    server/Device/CMIO_DPA_Sample_Server_ClientStream.h
    server/Device/CMIO_DPA_Sample_Server_Deck.h
    server/Device/CMIO_DPA_Sample_Server_Device.h
    server/Device/CMIO_DPA_Sample_Server_Frame.h
    server/Device/CMIO_DPA_Sample_Server_Stream.h
    server/Device/CMIO_DPA_Sample_Server_VCamInputStream.h
    server/CMIO_DPA_Sample_Server_Assistant.h
    server/CMIO_DPA_Sample_Server_Common.h
    server/CMIO_DPA_Sample_Server_MIGInterface.h
    server/CMIODPASampleServer.h)

set(coremediaio-dal-ipc_SOURCES
    client/CMIO_DPA_Sample_ClientExtras.cpp
    client/CMIODPASampleClient.cpp

    common/CMIO_DPA_Sample_Shared.h

    server/Device/CMIO_DPA_Sample_Server_ClientStream.cpp
    server/Device/CMIO_DPA_Sample_Server_Deck.cpp
    server/Device/CMIO_DPA_Sample_Server_Device.cpp
    server/Device/CMIO_DPA_Sample_Server_Frame.cpp
    server/Device/CMIO_DPA_Sample_Server_Stream.cpp
    server/Device/CMIO_DPA_Sample_Server_VCamInputStream.cpp
    server/CMIO_DPA_Sample_Server_Assistant.cpp
    server/CMIO_DPA_Sample_Server_MIGInterface.cpp
    server/CMIODPASampleServer.cpp)


add_library(coremediaio-dal-ipc SHARED
	${coremediaio-dal-ipc_SOURCES}
	${coremediaio-dal-ipc_HEADERS})

target_link_libraries(coremediaio-dal-ipc
	${AVFOUNDATION}
	${COCOA}
	${COREFOUNDATION}
	${COREMEDIA}
	${COREVIDEO}
	${COREMEDIAIO}
	${IOSURFACE}
    ${IOKIT}
    ${COREMEDIAIO_DAL_LIBRARIES})

configure_file(coremediaio-dal-ipc.pc.in coremediaio-dal-ipc.pc @ONLY)

install(TARGETS coremediaio-dal-ipc
    EXPORT        coremediaio-dal-ipc
    LIBRARY       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT shlib
    ARCHIVE       DESTINATION "${CMAKE_INSTALL_LIBDIR}"                            COMPONENT lib
    RUNTIME       DESTINATION "${CMAKE_INSTALL_BINDIR}"                            COMPONENT bin)
install(FILES ${coremediaio-dal-ipc_HEADERS}             DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/coremediaio-dal-ipc COMPONENT devel)
install(FILES ${CMAKE_BINARY_DIR}/coremediaio-dal-ipc.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)