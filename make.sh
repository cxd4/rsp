mkdir -p obj
mkdir -p obj/vu

# The below path configuration will only work if you have this `make.sh` script
# installed to the parent directory just outside the RSP source when you run it.
src="." # or an absolute path, like "/home/user/rsp"
obj="$src/obj"

FLAGS_x86="\
    -O3 \
    -DPLUGIN_API_VERSION=0x0101 \
    -DARCH_MIN_SSE2 \
    -msse2 \
    -mstackrealign \
    -Wall \
    -pedantic"
OBJ_LIST="\
    $obj/module.o \
    $obj/su.o \
    $obj/vu/vu.o \
    $obj/vu/multiply.o \
    $obj/vu/add.o \
    $obj/vu/select.o \
    $obj/vu/logical.o \
    $obj/vu/divide.o"

echo Compiling C source code...
cc -S $FLAGS_x86 -o $obj/module.s  $src/module.c
cc -S $FLAGS_x86 -o $obj/su.s      $src/su.c
cc -S $FLAGS_x86 -o $obj/vu/vu.s       $src/vu/vu.c
cc -S $FLAGS_x86 -o $obj/vu/multiply.s $src/vu/multiply.c
cc -S $FLAGS_x86 -o $obj/vu/add.s      $src/vu/add.c
cc -S $FLAGS_x86 -o $obj/vu/select.s   $src/vu/select.c
cc -S $FLAGS_x86 -o $obj/vu/logical.s  $src/vu/logical.c
cc -S $FLAGS_x86 -o $obj/vu/divide.s   $src/vu/divide.c

echo Assembling compiled sources...
as --statistics -o $obj/module.o $obj/module.s
as --statistics -o $obj/su.o     $obj/su.s
as --statistics -o $obj/vu/vu.o  $obj/vu/vu.s
as -o $obj/vu/multiply.o $obj/vu/multiply.s
as -o $obj/vu/add.o      $obj/vu/add.s
as -o $obj/vu/select.o   $obj/vu/select.s
as -o $obj/vu/logical.o  $obj/vu/logical.s
as -o $obj/vu/divide.o   $obj/vu/divide.s

echo Linking assembled object files...
ld --shared -o $obj/rsp.so $OBJ_LIST
strip -o $obj/rsp.so $obj/rsp.so
