FROM ubuntu:16.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    build-essential bison flex git gperf texinfo help2man gawk libtool-bin \
    libncurses5-dev unzip wget curl python3 patch xz-utils bc automake \
    && rm -rf /var/lib/apt/lists/*

# crosstool-NG 1.22.0 (suele compilar mejor que 1.20 en hosts modernos)
WORKDIR /opt
RUN wget http://crosstool-ng.org/download/crosstool-ng/crosstool-ng-1.22.0.tar.bz2 && \
    tar xf crosstool-ng-1.22.0.tar.bz2 && cd crosstool-ng && \
    ./configure --enable-local && make && make install

# Directorio de trabajo para tu toolchain
#WORKDIR /
