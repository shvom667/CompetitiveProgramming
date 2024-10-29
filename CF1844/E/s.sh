for ((i = 0; i <= 1000000; i++)); do
  echo $i
  ./gen $i > int
  ./brute < int > bo
  ./genius < int > ao
  diff -w ao bo || break
done
