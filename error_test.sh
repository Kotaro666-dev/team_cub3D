#!/bin/sh

for i in `seq 9`
do
echo "error_pattern/error0$i.cub"
./cub3D error_pattern/error0$i.cub
done

echo "error_pattern/error10.cub"
./cub3D error_pattern/error10.cub

for i in `seq 9`
do
echo "error_pattern/error1$i.cub"
./cub3D error_pattern/error1$i.cub
done

echo "error_pattern/error20.cub"
./cub3D error_pattern/error20.cub

for i in `seq 9`
do
echo " error_pattern/error2$i.cub"
./cub3D error_pattern/error2$i.cub
done

echo "error_pattern/error30.cub"
./cub3D error_pattern/error30.cub

for i in `seq 7`
do
echo " error_pattern/error3$i.cub"
./cub3D error_pattern/error3$i.cub
done

echo "error_pattern/error40.cub"
./cub3D error_pattern/error40.cub

for i in `seq 4`
do
echo " error_pattern/error4$i.cub"
./cub3D error_pattern/error4$i.cub
done

# WRONG FORMAT
echo "error_pattern/errorformat01.cubwrong"
./cub3D error_pattern/errorformat01.cubwrong

echo "error_pattern/errorformat02.cub.cubwrong"
./cub3D error_pattern/errorformat02.cub.cubwrong