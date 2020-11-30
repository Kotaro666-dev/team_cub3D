#!/bin/sh

for i in `seq 9`
do
echo "error_test/error0$i.cub"
./cub3D error_test/error0$i.cub
done

echo "error_test/error10.cub"
./cub3D error_test/error10.cub

for i in `seq 9`
do
echo "error_test/error1$i.cub"
./cub3D error_test/error1$i.cub
done

echo "error_test/error20.cub"
./cub3D error_test/error20.cub

for i in `seq 9`
do
echo "error_test/error2$i.cub"
./cub3D error_test/error2$i.cub
done

echo "error_test/error30.cub"
./cub3D error_test/error30.cub

for i in `seq 9`
do
echo "error_test/error3$i.cub"
./cub3D error_test/error3$i.cub
done

echo "error_test/error40.cub"
./cub3D error_test/error40.cub

for i in `seq 9`
do
echo "error_test/error4$i.cub"
./cub3D error_test/error4$i.cub
done

echo "error_test/error50.cub"
./cub3D error_test/error50.cub

for i in `seq 9`
do
echo "error_test/error5$i.cub"
./cub3D error_test/error5$i.cub
done

echo "error_test/error60.cub"
./cub3D error_test/error60.cub

# WRONG FORMAT
echo "error_test/errorformat01.cubwrong"
./cub3D error_test/errorformat01.cubwrong

echo "error_test/errorformat02.cub.cubwrong"
./cub3D error_test/errorformat02.cub.cubwrong