for i in {1..25}; do
 echo -n "$(/usr/bin/time -f %E ./sum 2>&1);" | colrm 1 2
 echo -n "$(/usr/bin/time -f %E ./getppid 2>&1);" | colrm 1 2
 echo -n "$(/usr/bin/time -f %E ./gettimeofday 2>&1);" | colrm 1 2
 echo -n "$(/usr/bin/time -f %E ./forkwait 2>&1) " | colrm 1 2
 echo
done
