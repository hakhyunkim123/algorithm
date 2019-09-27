# Algorithm problems from backjoon

>scanf()에서 공백 스킵하기(p3190 참조).
```c 
scanf("%*[ \n\t]%c", &var); 
```

>연속된 정수 input line(ex: 11111)에서 하나씩 받기(p2667 참조).
```c 
scanf("%1d", &map[i][j]);
```

>BFS에서 queue를 2개로 나누어서 하면 안된다.(p3055 참조).

>call by reference는 가급적이면 지양하도록 하자.(p17143에서 move_shark를 사용할 경우 시간초과가 뜬다.)
