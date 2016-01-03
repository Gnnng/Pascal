program hello;
const
	cn = 2;
	dn = 123.23;

var	
	k : integer;

procedure outer;

var 
	res : integer;
	added : integer;

function inner1(a , b : integer) : integer;
begin
	inner1 := a + b;
end
;

procedure inner2(var aa : integer; b :integer);
begin
	aa := inner1(aa , b);
	k := k + 10;
end
;

begin
	k := 0;
	inner2(k , 10);
end
;

begin
	outer;
	writeln(k);
end
.
