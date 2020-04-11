killall -9 test
./test &
TEST_PID=$!
./profile $TEST_PID
kill -9 $TEST_PID