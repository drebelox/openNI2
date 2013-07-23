
# OpenNI2
Modified build to work on rpi and other helpful changes

## Mods

- Patches For ARM based boards
- Generate deb packages
- Update lib paths to allow for global install


## Build

```
$ make
```

### Cross-Compiling for arm on Linux:
The following environment variables should be defined:

- ARM_CXX=<path to cross-compilation g++>
- ARM_STAGING=<path to cross-compilation staging dir>

```
$ PLATFORM=Arm make
```

### Creating OpenNI2 package:

- Go into the directory 'Redist'
- Run ReleaseVersion.py [x86|x64|arm|android]
- Installer will be placed in the 'Final' directory