# Create MakeFile
cmake -B../build -H..

# Compile using make
cd ../build
make

# Execute the app
cd ../bin
./mandelbrot

# Return to previous
cd -