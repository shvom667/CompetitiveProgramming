for((i = 1; i <= 10000; ++i)); do
    echo $i
    ./gen $i > int
    ./ac < int > out1
    ./brute < int > out2
    diff -w out1 out2 || break
       
done
