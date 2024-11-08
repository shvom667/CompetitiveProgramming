for ((i = 0; i <= 100000; i++)); do
  echo $i
  ./gen $i > int
  ./brute < int > bo
  ./sol < int > so
  diff -w bo so #|| break
done
