duration=172800
end=$((SECONDS + duration))

echo "Screen will stay off for 2 days (unless interrupted)..."

while [ $SECONDS -lt $end ]; do
    xset dpms force off
    sleep 1
done
