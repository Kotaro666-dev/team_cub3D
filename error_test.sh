#!/bin/sh

for i in `seq 10`
do
echo "error_pattern/error0$i.cub"
./cub3D error_pattern/error0$i.cub
done

for i in `seq 10`
do
echo "error_pattern/error1$i.cub"
./cub3D error_pattern/error1$i.cub
done

for i in `seq 5`
do
echo " error_pattern/error2$i.cub"
./cub3D error_pattern/error2$i.cub
done