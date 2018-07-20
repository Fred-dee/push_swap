# push_swap
Work as done for the project push_swap at WeThinkCode_
The point of the project is to, with a predifined instruction set, sort out a stack of integers in the smallest amount of moves.
The project uses work from the <a href="https://github.com/Fred-Dee/libft"> libft </a> project as well as the <a href= "https://github.com/Fred-Dee/get_next_line"> get next line </a> project.
  
 Here is a list of the allowed operations:
<table style="width: 100%">
	<tr>
  		<th>Operation</th>
  		<th>Description </th>
	</tr>
	<tr>
		<td>swap a</td>
		<td>Swap the first 2 elements at the top of stack a.</td>
	</tr>
	<tr>
		<td>swap b</td>
		<td>Swap the first 2 elements at the top of stack b.</td>
	</tr>
	<tr>
		<td>swap s</td>
		<td>swap a and swap b at the same time.</td>
	</tr>
	<tr>
		<td>push a</td>
		<td>Take the first element at the top of b and put it at the top of a.</td>
	</tr>
	<tr>
		<td>push b</td>
		<td>Take the first element at the top of a and put it at the top of b.</td>
	</tr>
	<tr>
		<td>rotate a</td>
		<td>Shift up all elements of stack a by 1. <br>
			The first element becomes the last one</td>
	</tr>
	<tr>
		<td>rotate b</td>
		<td>Shift up all elements of stack b by 1. <br>
			The first element becomes the last one</td>
	</tr>
	<tr>
		<td>rotate r</td>
		<td>rotate a and b at the same time</td>
	</tr>
	<tr>
		<td>reverse rotate a</td>
		<td>Shift down all elements of stack a by 1. <br>
			The last element becomes the first one</td>
	</tr>
	<tr>
		<td>reverse rotate b</td>
		<td>Shift down all elements of stack b by 1. <br>
			The last element becomes the first one</td>
	</tr>
	<tr>
		<td>reverse rotate r</td>
		<td>reverse rotate a and b at the same time</td>
	</tr>
</table>

<h1>Usage</h1>
<p>
The program should be compiled using the [make] command, [make re] to recompile.<br/>
To run the algorithm generating program use:<br/>
./push_swap [space separated integers]<br/>
To run the checker program user:<br/>
./push_swap [space separated integers] | ./checker [space separated integers] <br/>
OR to run each instruction using the flags "-v": step by step and -c "colour code the last operation" use:<br/>
./checker <flags> [space separated integers]<br/>
</p>
