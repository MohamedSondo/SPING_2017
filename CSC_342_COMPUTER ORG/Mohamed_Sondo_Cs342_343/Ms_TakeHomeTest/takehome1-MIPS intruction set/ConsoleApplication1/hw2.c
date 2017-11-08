void main()
{
	int quizint = 0x01000080;
	int n = 0xffffffff;
	int MIPSzint = 0x80000001;
	register int m = 3;
	register int p = 256;
	static int q = 0x7fffffff;
	static int r = 0x10000000;
	static int R = 0x80000000;
	_asm
	{
	start_loop:
			mov ebx, MIPSzint
			add ebx, -2
			mov ecx, quizint
			mov eax, n
			sub eax, q
			add eax, R
			mov edx, 1
			add edx, q
			add edx, 1
			add edx, n
			add R, -1
	}
}