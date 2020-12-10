#!/bin/sh

for i in `seq 9`
do
echo "ok_test/ok_test0$i.cub"
./cub3D ok_test/ok_test0$i.cub
done

echo "ok_test/ok_test10.cub"
./cub3D ok_test/ok_test10.cub

for i in `seq 9`
do
echo "ok_test/ok_test1$i.cub"
./cub3D ok_test/ok_test1$i.cub
done

echo "ok_test/ok_test20.cub"
./cub3D ok_test/ok_test20.cub

for i in `seq 4`
do
echo "ok_test/ok_test2$i.cub"
./cub3D ok_test/ok_test2$i.cub
done

# CUB FORMAT EXTENSION

echo "ok_test/ok_test_format.cub.cub"
./cub3D ok_test/ok_test_format.cub.cub

echo "ok_test/ok_test_format.ok...cub"
./cub3D ok_test/ok_test_format.ok...cub

echo "ok_test/ok_test_format.ok.cub"
./cub3D ok_test/ok_test_format.ok.cub

# MAP SIZE

echo "ok_test/map_100.cub"
./cub3D ok_test/map_100.cub

echo "ok_test/map_199.cub"
./cub3D ok_test/map_199.cub

echo "ok_test/map_200.cub"
./cub3D ok_test/map_200.cub

echo "ok_test/map_200_199.cub"
./cub3D ok_test/map_200_199.cub