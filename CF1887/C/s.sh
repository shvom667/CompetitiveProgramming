for ((i = 0; i <= 10000000; i++)); do
  echo $i
  ./gen $i > int
  ./sol < int > so
  ./brute < int > bo
  diff -w so bo || break
done
