for ((i = 0; i <= 10000000; i++)); do
  cat $i
  ./gen $i > int
  ./brute < int > bo
  ./sol < int > so
done
