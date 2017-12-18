gcc -o server.bin server/server.c
gcc -o client.bin client/client.c

./server.bin &
sleep 1
./client.bin