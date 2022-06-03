# Simple Minesweeper game in C++

This project was put together because of my love of MS Minesweeper back during my Win 3.1 days.  A lot of time was burned playing this game during late nights of study and I thought this would be a complicated enough project to write in C++ and to play around with the Makefile build process.  Let's start from the beginning.

And that beginning is picking a widget library.  [wxWidgets](https://www.wxwidgets.org/) to the rescue!  I needed something that would be cross platform compatible, and wxWidgets fit that requirement to a tee.  Not only was it available easily or by default on all the major linux distros ~~(I daily use [elementary OS](https://elementary.io/))~~, but it was baked in to macOS, since when it was going by the name OSX.  Getting it on Windows was also fairly simple using [MSYS2](https://www.msys2.org/), needing a quick compile of the library using the native tools there.

The project, as contrived as it was already, became a little more complicated as I moved the build in to linux containers.  Not docker or LXD; the og LXC, which I'd been using to bring up other various dev environments and servers locally for other projects.  I thought one day, why am I not doing this?, so I gradually started to move the build stages over to containers.

Ubuntu bionic (18.04) containers for the i686 and x86_64 wxGTK versions and a debian buster (10.7) container for the mingw32 version.  The project from the start was meant to be compiled with [clang](https://clang.llvm.org/) and the [llvm project](http://llvm.org/), but in the case of wxMSW, this was not so easy or convenient.  Some hours (days really) were wasted coming up with a way to build LLVM + company locally from source and was a downright nightmare on Windows.  At some point, clang appeared in MSYS2, but I had already gotten far enough in to the cross compiling linux container that I stopped thinking about incorporating it in to the project.  No fancy LLVM or clang programming/extensions were even used in this very simple project, either.  Not that it would've been too difficult to switch wxMSW now, since the Makefiles all reference and check for clang anyway. I'll leave it for the future when I want to torture myself more with this project.

The tile assets I've had for a while, a gift from a friend years ago when I had the idea to work on this project on my free time.  Everything else is credited in the code and the program in the help and about dialogs. I get pretty much everything from [Flaticon](https://www.flaticon.com) and the other assets were no exception.

The repo is laid out as follows:

```
.
./include
./assets
./assets/set2
./assets/set1
./packages
./packages/wxMSW
./packages/wxMac
./packages/wxMac/minesweep.iconset
./packages/wxGTK
./packages/wxGTK/release
./packages/wxGTK/armhf
./src
./src/panels
./src/game
```

`include` contains all the headers for each of the `src` files, `src` contains the main program, and the directories `game` and `panels` contain the source for the game logic and panels respectively. It's not very pretty, but it sufficiently made sense to me separating everything in to smaller chunks to debug and be able to wrap my head around.  I spent more time playing with the build system more than the core logic and coding style of the actual project to be honest.

Within the 'packages' directory, there are subdirectories for each of the platforms I chose to target, `wxGTK` for linux, `wxMSW` for MS windows and `wxMac` for darwin/Apple.  Each of those directories has a `configure.txt` file with brief notes on how to get up and running generating local dynamic/shared libraries in their respective native build environments.  Towards the end of those files are instructions on how to recreate the linux containers to cross compile or build the project.  Of the three platforms, `wxMac` is the only one that has no cross compiling instructions, broken or otherwise.  I recall seeing in my searches a way to import the toolchain from my mac mini and use that to produce the executable, but that looked to be more of a nice to have and another time sink to get that correct.  Another TODO for torture, I suppose.

Anyway, that's pretty much it with regards to this project.  It's simple, it's complicated, and it's all time suck Minesweeper.  Enjoy!
