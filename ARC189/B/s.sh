for ((i = 0; i <= 10000000; i++)); do
  echo $i
  ./gen $i > int
  # ./brute < int > bo
  ./sol < int > so || {
      break
  }
  # diff -w bo so || break
done
