killall -9 graph500_reference_bfs
/home/zyh/graph500-newreference/src/graph500_reference_bfs 16 2 &
TEST_PID=$!
./profile $TEST_PID