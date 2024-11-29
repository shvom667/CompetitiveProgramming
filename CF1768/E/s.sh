for ((i = 0; i <= 10000000; i++)); do
  echo $i
  ./gen $i > int
  ./bad < int > bo
  ./bad2 < int > so
  diff -w bo so || break
done
