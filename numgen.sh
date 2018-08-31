IN100=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")
IN500=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
IN5=$(ruby -e "puts (0..5).to_a.shuffle.join(' ')")
BIN="./push_swap"
echo Sort 5
$BIN $IN5 |wc -l
$BIN $IN5 | "./checker" $IN5
echo Sort 100
$BIN $IN100 | wc -l
$BIN $IN100 | "./checker" $IN100
echo Sort 500
$BIN $IN500 | wc -l
$BIN $IN500 | "./checker" $IN500
