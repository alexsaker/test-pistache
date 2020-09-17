# TEST PISTACHE

## Pre requisites

```bash
# Compile to host pistache
cd pistache
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```

## Build & Launch server

```bash
clang++ -o ./dist/server ./src/server.cpp  -lboost_system -lpthread
./dist/server
```

## Test server

```bash
curl http://localhost:9080/
```

## Bench server with Apache Benchmark

```bash
 ab -n 1000000 -c 1000 http://localhost:9080/
```
