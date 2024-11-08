for ((i = 0; i <= 10000000; i++)); do
  echo $i
  ./gen $i > int
  # ./sol < int > so
  python3 sol.py < int > so
  python3 brute.py < int > bo
  #sleep 1
  diff -w so bo || break
done
