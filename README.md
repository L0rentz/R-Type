# R-TYPE

This project aims to recreate the R-Type game and add a multiplayer mode to it in C++.  

Click to see the presentation  
[![](http://img.youtube.com/vi/imlIwO6Lep0/0.jpg)](http://www.youtube.com/watch?v=imlIwO6Lep0 "R-Type")  

## Build

### Build on linux

First time
```
sudo apt install libudev-dev
```

```
mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .
```

### Build on windows

```
mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Visual Studio 16 2019" -A x64 && cmake --build .
```

Then start de server and any amount of clients.  
