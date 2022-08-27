#!/bin/sh
docker build \
    --platform linux/amd64 \
    -t pysamp/build \
    . \
&&
docker run \
    --rm \
    --platform linux/amd64 \
    -v $PWD:/destination \
    pysamp/build \
    sh -c '
    cd PySAMP &&
    cmake \
        -S src \
        -B build \
        -DCMAKE_BUILD_TYPE=${build_type} \
        -DSAMPSDK_DIR=$PWD/../samp-plugin-sdk \
        -DSAMPGDK_DIR=$PWD/../sampgdk \
        -DPython3_ROOT_DIR=$(python3-config --configdir) \
    &&
    cmake --build build --parallel ${job_count} &&
    cp build/PySAMP.so /destination
    '
