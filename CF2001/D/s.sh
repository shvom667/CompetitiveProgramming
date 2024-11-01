for ((i = 0; i <= 1000000; i++)); do
  echo $i
  ./gen $i > int
  ./sol < int > so
  ./brute < int > bo
  diff -w so bo || break
done

