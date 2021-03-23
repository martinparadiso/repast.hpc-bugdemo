# Construct an image using the original repast
FROM ubuntu:20.04

# Add MPICH bin to the PTH
ENV PATH="/root/sfw/MPICH/bin:${PATH}"
ADD ./bugdemo/ /demo/src/

    # Install requirements and clone Repast.HPC
RUN apt update -y && apt upgrade -y git build-essential zlib1g-dev libgtest-dev && \
    cd /demo && \
    git clone https://github.com/martinparadiso/repast.hpc.git && \
    cd repast.hpc && \
    git checkout 63db36c && \
    # Install the depedencies
    cd /demo/repast.hpc/dist/Manual/Typical/ && \
    ./install.sh curl && \
    ./install.sh mpich && \
    ./install.sh netcdf && \
    ./install.sh boost && \
    # Install repast
    mkdir /demo/repast.hpc/Debug && \
    cd /demo/repast.hpc/Debug && \
    cp ../Makefile.tmplt ./Makefile && \
    cd /demo/repast.hpc/Debug && \
    make install && \
    # Compile the demo
    cd /demo && \
    yes | rm -r /demo/repast.hpc && \
    cd /demo/src/ && \
    make bugdemo && \
    apt remove -y git build-essential && \
    apt autoremove -y && \
    # Pass the libraries directories to ld
    ldconfig /root/sfw/CURL/lib/ \
             /root/sfw/MPICH/lib/ \
             /root/sfw/NetCDF/lib/ \
             /root/sfw/NetCDF-cxx/lib/ \
             /root/sfw/repast_hpc-2.3.1/lib/ \
             /root/sfw/Boost/Boost_1.61/lib/

WORKDIR /demo/src/build
CMD ["mpiexec", "-np", "4", "./demo", "../props/config.props", "../props/model.props"]
