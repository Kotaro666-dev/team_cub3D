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

# MAP SIZE

echo "error_test/large_map_2000.cub"
./cub3D error_test/large_map_2000.cub

echo "error_test/map_201.cub"
./cub3D error_test/map_201.cub

echo "error_test/map_300.cub"
./cub3D error_test/map_300.cub

echo "error_test/map_400.cub"
./cub3D error_test/map_400.cub

echo "error_test/map_500.cub"
./cub3D error_test/map_500.cub

echo "error_test/map_600.cub"
./cub3D error_test/map_600.cub

echo "error_test/map_800.cub"
./cub3D error_test/map_800.cub

# WRONG FORMAT
echo "error_test/errorformat01.cubwrong"
./cub3D error_test/errorformat01.cubwrong

echo "error_test/errorformat02.cub.cubwrong"
./cub3D error_test/errorformat02.cub.cubwrong

# FILE DOESNT'T EXSIT

echo "error_test/file_doesnt_exist.cub"
./cub3D error_test/file_doesnt_exist.cub

# FILE PERMISSION

echo "error_test/file_permisson.cub"
./cub3D error_test/file_permisson.cub

# MULTI MAP ERROR

echo "error_test/double_map.cub"
./cub3D error_test/double_map.cub

echo "error_test/multi_map.cub"
./cub3D error_test/multi_map.cub

# NO MAP ERROR

echo "error_test/no_map.cub"
./cub3D error_test/no_map.cub