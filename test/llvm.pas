program llvm;
var a, b, c: integer;

function add(var x, y:integer) : integer;
begin
	add := x + y;
end;

function st: integer;
begin

end;

function stt(): integer;
begin

end;

begin
	a := 0;
	b := 1;
	c := a + b;
	a := a + c;
end.