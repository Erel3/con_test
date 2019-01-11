unit xoractive_lib;

interface

type
	array_of_longint = array of longint;
function get_pairwise_xor(a: array_of_longint): array_of_longint;
function ask(pos: longint): longint;

implementation

uses xoractive;

const
	MAX_NUM_MOVES: longint = 1000;

var
	n, i: longint;
	num_moves: longint;
	arr: array_of_longint;
	b: array_of_longint;

procedure wrong_answer(MSG: ansistring);
begin
	writeln('Wrong Answer: ', MSG);
	halt(0);
end;

procedure query();
begin
	inc(num_moves);
	if num_moves > MAX_NUM_MOVES then begin
		wrong_answer('too many moves');
	end;
end;

function ask(pos: longint): longint;
begin
	query();
	if ((pos < 1) or (pos > n)) then begin
		wrong_answer('not correct position');
	end;
	ask := arr[pos - 1];
end;



procedure Sort(l, r: longint);
var
    i, j, x, tmp: longint;
begin
    i := l; j := r;
    x := b[l + random(r - l + 1)];
    repeat
    while b[i] < x do inc(i);
    while x < b[j] do dec(j);
    if i <= j then begin
      tmp := b[i]; b[i] := b[j]; b[j] := tmp;
      inc(i); dec(j);
    end;
    until i > j;
    if l < j then Sort(l,j);
    if i < r then Sort(i,r);
end;




function get_pairwise_xor(a: array_of_longint): array_of_longint;
var
	len, i, j: longint;
	posI, posJ: longint;
begin 
	query();
	if((Length(a) = 0) or (Length(a) > n)) then
	begin
		wrong_answer('Not correct size');
	end;
	setLength(b, Length(a));
	for i := 0 to Length(a) - 1 do begin
		b[i] := a[i];
	end;
	Sort(0, n - 1);
	for i := 0 to Length(a) - 1 do begin
		a[i] := b[i];
	end;
	for i := 1 to Length(a) - 1 do begin
		if (a[i] = a[i - 1]) then begin
			wrong_answer('Not unique');
		end;
	end;
	setLength(b, Length(a) * Length(a));
	len := 0;
	for i := 0 to Length(a) - 1 do begin
		for j := 0 to Length(a) - 1 do begin
			posI := a[i];
			posJ := a[j];
			b[len] := arr[posI - 1] xor arr[posJ - 1];
			inc(len);
		end;
	end;
	sort(0, len - 1);
	get_pairwise_xor := b;
end;
	
begin
    read(n);
    setLength(arr, n);
    for i := 0 to n - 1 do begin
    	read(arr[i]);
    end;
	arr := guess(n);
	writeln(n);
    for i:= 0 to n - 1 do begin
        write(arr[i], ' ');
    end;
    writeln('');
    writeln(num_moves);
end.
