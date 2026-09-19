# Queue ADT in C

## How to Test

To compile and run the project on **Linux/macOS**, open a terminal in the project directory and run:

```bash
make simple
./simple-queue/simple_queue
```

```bash
make circular
./circular-queue/circular_queue
```

On **Windows** using MinGW, run:

```bash
mingw32-make simple
./simple-queue/simple_queue
```

```bash
mingw32-make circular
./circular-queue/circular_queue
```

To compile both implementations at once, run `make all` (or `mingw32-make all` on Windows).

After testing the project, clean up the generated object files (`.o`) and executables by running:

**Linux/macOS:**

```bash
make clean
```

**Windows:**

```bash
mingw32-make clean
```