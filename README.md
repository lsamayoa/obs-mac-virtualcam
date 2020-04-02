# OBS VirtualCam Mac Plugin

obs-mac-virutalcam is a plugin for obs-studio that exposes an output transforming the output video from obs into a virtual CoreMediaIO device.

# Features

- mac-virtualcam-obs-plugin: Plugin that sinks raw video into CoreMediaIO DAL interface through mach
- mac-virtualcam-osx-plugin: CoreMediaIO DAL implementation that listens to the mac-virtualcam-obs-plugin output

# Build & Install

Currently building from source is necesary to install the plugin as no binary is provided (YET )

## Build

You need to install cmake and build the OBS project first. Set following Cmake variables:

- **LIBOBS_INCLUDE_DIR** (path) : Libobs include folder
- **LIBOBS_LIB** (filepath) : obs.lib path

```
mkdir build
cd build 
cmake -DLIBOBS_INCLUDE_DIR="../../obs-studio/libobs" -DLIBOBS_LIB="../../obs-studio/build/libobs/libobs.dylib" ..
make
```

## Install

Building the project that you should be able to:
- Copy **build/mac-virtualcam-obs-plugin/mac-virtualcam-obs-plugin.so** into **${OBS_INSTALL_DIR}/obs-plugins**
- Copy **build/mac-virtualcam-dal-plugin/mac-virtualcam-dal-plugin.plugin** into **/Library/CoreMediaIO/Plug-Ins/DAL/virtualcam-mac-dal-plugin.plugin/** to install the DAL plugin.
- Run obs-studio
- Run any videocapture software (i.e. Quicktime) and a camera should be available as "OBS Virtual Camera" with obs output
