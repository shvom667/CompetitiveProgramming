echo 100 > int
for ((i = 0; i <= 100; i++)); do
  ./gen $i >> int
  #./brute < int > bo
  #./sol < int > so
  #diff -w bo so || break
done
