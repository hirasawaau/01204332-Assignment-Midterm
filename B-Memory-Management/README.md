## Compile

```bash
$ gcc -o a.out memory.c
```

## Run

```bash
$ ./a.out > output.txt # reserve stack and heap 5 times
$ ./a.out 1 > output.txt # reserve stack and heap until overflow
```

## Output File Example

### output.txt

Output from `./a.out > output.txt`

### output_overflow.txt

Output from `./a.out 1 > output_overflow.txt`
