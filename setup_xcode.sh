# This script sets up an Xcode project into "build" folder using cmake
# I recommend adding the "build" folder into .gitignore file

mkdir -p build
cd build
cmake -G Xcode ..
