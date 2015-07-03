program llvm;
var a, b, c: integer;
procedure count(var b:integer);
begin
    b:=1;
end;
begin
    a:=1;
    while a<30 do begin
        a:=a+1;
        writeln(a);
    end;
    repeat
        a:=a+1;
    until a=60;
    for a:=1 to 100 do
    begin
        b:=b+1;
        b:=b+1;
    end;
    if ((b>30) and (b<100)) then 
        if (a<120) then writeln(a);
    a := 1;
    writeln(a);
    case a of 
        1: writeln(1);
        100: begin goto 1;writeln(9999);end;
    end;
1:  
    writeln(b*3 mod 600);
end.
