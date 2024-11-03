for ((i = 0; i <= 1000000; i++)); do
  echo $i
  ./gen $i > int
  ./sol < int > os
  ./brute < int > ob
  diff -w os ob || break
done

