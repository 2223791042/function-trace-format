# function-trace-format
A format print function trace tools which is base on C

```bash
/*
function_a()
    function_b()
        function_c()
            function_d()
            function_e()

function_a()
 |
 o--> function_b()
       |
       o--> function_c()
             |
             o--> function_d()
             |
             o--> function_e()
*/
```

