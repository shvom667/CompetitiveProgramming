for ((i = 0; i <= 10000000; i++)); do
  echo $i
  ./gen $i > int
  #cat int > cint
  ./sol < int > sout
  #cat sout >> cint
  #./check < cint > cout
  #diff -w cout sout || break
done
