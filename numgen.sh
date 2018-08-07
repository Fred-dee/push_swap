IN100=$(ruby -e "puts (0..99).to_a.shuffle.join(' ')")
IN500=$(ruby -e "puts (0..499).to_a.shuffle.join(' ')")
BIN=./push_swap
echo Sort 100
$BIN $IN100 | wc -l
echo Sort 500
$BIN $IN500 | wc -l