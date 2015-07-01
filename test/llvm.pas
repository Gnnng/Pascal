program llvm;
var a, b, c: integer;
function add(var a, b: integer): integer;
begin
    add := a + b;
end;
begin
    a:=1;
    if 1=2 then  
        a := 22
    else
        a := 100+5;
    if 1=1 then  
        a := 22
    else
        a := 100;
    writeln(add(a, 1));
end.
