PokerStove (modernized)
==========

This is a PokerStove revamp that restructred the project to a modern layout and provides easy-to-use integration
as library via [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) which also auto-includes all dependencies
(most importantly `Boost`, which still doesn't provide good cmake integration yet...).

Some more info about any changes...

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

Working/tested parts of the library:
- Rank
- Suit
- Card
- CardSet

### penum

Tbd...

Working/tested parts of the library:
- None yet


## Building

The pokerstove libraries come with build scripts for cmake. This
should allow you to build it on any platform with minimal
tweaking.

In order to build the libraries, use CPM.cmake to include the library, then link against it:
```cmake
CPMAddPackage("gh:MichaelUnknown/MPS@0.0.1")

# define your executable
add_executable(MyPokerApp MyPokerApp.cpp MoreSources.cpp ...)

# 'link' against the lib
target_link_libraries(MyPokerApp modern-pokerstove::peval)
```

### Dependencies

[Google test](https://github.com/google/googletest) is used for unit tests, [CPM.cmake](https://github.com/cpm-cmake/CPM.cmake) for
adding dependendcies and [PackageProject.cmake](https://github.com/TheLartians/PackageProject.cmake) to make the project easily installable.


## Programs

### ps-eval

A tool for poker hand evaluation.  It demonstrates how to use the peval library, and to create
evaluators for the different variants of poker.

### ps-colex

A utility for viewing colexicographical index for sets of cards.
