>src-build.log
@PiP-build
*piptop=$PWD
### Building PiP-glibc (optional)
%git clone https://github.com/procinproc/PiP-glibc.git
mkdir glibc-build
*pushd glibc-build
%../PiP-glibc/build.sh "\$piptop/install"
*popd
### Building PiP Library
%git clone https://github.com/procinproc/PiP.git
*pushd PiP
%./configure --prefix="\$piptop/install" --with-glibc-libdir="\$piptop/install/lib"
%make install
*popd
### Testing PiP Library (optional)
%git clone https://github.com/procinproc/PiP-Testsuite.git
*pushd PiP-Testsuite
%./configure --with-pip="\$piptop/install"
%make test
*popd
### Building PiP-gdb (optional)
%git clone https://github.com/procinproc/PiP-gdb.git
*pushd PiP-gdb
%./build.sh --prefix="\$piptop/install" --with-pip="\$piptop/install"
%./test.sh
*popd
### done
