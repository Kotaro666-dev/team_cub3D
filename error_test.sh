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

for i in `seq 5`
do
echo " error_pattern/error2$i.cub"
./cub3D error_pattern/error2$i.cub
done