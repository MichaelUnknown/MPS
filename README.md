PokerStove (modernized)
==========

This is a PokerStove revamp that removes unnecessary dependencies from the original project and
provides easy-to-use integration as library via [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake).

Some more info...

This project provides just the C++ source code. For the installer of the Win32 GUI, see the original [repository](https://github.com/andrewprock/pokerstove).

## Original documentation

PokerStove is a highly hand optimized C++ poker hand evaluation library.  The Win32 Hold'em
GUI was first released in 2002, and has been available as freeware since
it's first release.

The core libraries of pokerstove are being open sourced.  The project is
currently in the process of reviewing and publishing the code.  As code is
reviewed and code sanitized further commits will be added.

Please find the old installer in the win32 directory.  That installer should
install a version of PokerStove which will not expire at any time.  You can also
find the apk file for the Android version of the utility in the android folder.

## Libraries

### peval

This is a c++ poker hand evaluation library.  The main design goals of the library
are generality, extensibility, and ease of use.  There are evaluators for fourteen
variants of poker.  Additionally, there are various card manipulation and query tools built
into the CardSet class.


## Building

The pokerstove libraries come with build scripts for cmake. This
should allow you to build it on any platform with minimal
tweaking.

In order to build the libraries, use CPM.cmake to include the library, then link against it:
```cmake
CPMAddPackage(
    NAME mkpoker
    GITHUB_REPOSITORY MichaelUnknown/mkpoker
    VERSION 0.x
)
# define your executable
add_executable(MyPokerApp MyPokerApp.cpp MoreSources.cpp ...)

# 'link' against mkpoker like this
target_link_libraries(MyPokerApp mkpoker::mkpoker)
```


### Dependencies

Google test is used for unit tests, [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for
adding dependendcies and [PackageProject.cmake](https://github.com/TheLartians/PackageProject.cmake) to create an installable object.



## Programs

### ps-eval

A tool for poker hand evaluation.  It demonstrates how to use the peval library, and to create
evaluators for the different variants of poker.

### ps-colex

A utility for viewing colexicographical index for sets of cards.

