for ((i = 0; i <= 100000; i++)); do
	echo $i
	./gen $i > int
	./snuke < int > os
	./chmax < int > oc
	diff -w os oc || break
done