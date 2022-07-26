>src-build.log
@PiP-build
~PIPTOP=$PWD
### Building PiP-glibc (optional)
%git clone https://github.com/procinproc/PiP-glibc.git
mkdir glibc-build
*pushd glibc-build
%../PiP-glibc/build.sh $PIPTOP/install
*popd
### Building PiP Library
%git clone https://github.com/procinproc/PiP.git
*pushd PiP
%./configure --prefix=$PIPTOP/install --with-glibc-libdir=$PIPTOP/install/lib
%make install
*popd
### Testing PiP Library (optional)
%git clone https://github.com/procinproc/PiP-Testsuite.git
*pushd PiP-Testsuite
%./configure --with-pip=$PIPTOP/install
%make test
*popd
### Building PiP-gdb (optional)
%git clone https://github.com/procinproc/PiP-gdb.git
*pushd PiP-gdb
%./build.sh --prefix=$PIPTOP/install --with-pip=$PIPTOP/install
%./test.sh
*popd
### done
