; ModuleID = 'main'

@.str = private constant [4 x i8] c"%d\0A\00"

define void @main() {
entry:
  %a = alloca i32
  %b = alloca i32
  %c = alloca i32
  %0 = icmp eq i32 1, 2
  br i1 %0, label %thenStmt, label %elseStmt

thenStmt:                                         ; preds = %entry
  store i32 22, i32* %a
  br label %mergeStmt

elseStmt:                                         ; preds = %entry
  store i32 100, i32* %a
  br label %mergeStmt

mergeStmt:                                        ; preds = %elseStmt, %thenStmt
  %1 = icmp eq i32 1, 1
  br i1 %1, label %thenStmt1, label %elseStmt2

thenStmt1:                                        ; preds = %mergeStmt
  store i32 22, i32* %a
  br label %mergeStmt3

elseStmt2:                                        ; preds = %mergeStmt
  store i32 100, i32* %a
  br label %mergeStmt3

mergeStmt3:                                       ; preds = %elseStmt2, %thenStmt1
  %2 = load i32* %a
  %3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i32 %2)
  ret void
}

declare i32 @printf(i8*, ...)
